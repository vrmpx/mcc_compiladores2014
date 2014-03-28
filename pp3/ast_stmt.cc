/* File: ast_stmt.cc
 * -----------------
 * Implementation of statement node classes.
 */
#include "ast_stmt.h"
#include "ast_type.h"
#include "ast_decl.h"
#include "ast_expr.h"
#include "errors.h"


int Scope::AddDecl(Decl *decl) {
    Decl *lookup = table->Lookup(decl->Name());

    if (lookup != NULL){
        ReportError :: DeclConflict(decl, lookup);
        return 1;
    }

    table->Enter(decl->Name(), decl);
    return 0;
}

Scope *Program::pScope = new Scope();


Program::Program(List<Decl*> *d) {
    Assert(d != NULL);
    (decls=d)->SetParentAll(this);
}

void Program::Check() {
    /* pp3: here is where the semantic analyzer is kicked off.
     *      The general idea is perform a tree traversal of the
     *      entire program, examining all constructs for compliance
     *      with the semantic rules.  Each node can have its own way of
     *      checking itself, which makes for a great use of inheritance
     *      and polymorphism in the node classes.
     */

     BuildScope();
     int n = decls->NumElements();
     for(int i = 0; i < n; i++){
        decls->Nth(i)->Check();
     }
}

void Program::BuildScope(){
    int n = decls->NumElements();
    for (int i = 0; i < n; i++) {
        pScope->AddDecl(decls->Nth(i));
    }

    for (int i = 0; i < n; i++){
        decls->Nth(i)->BuildScope(pScope);
    }

}

void Stmt::BuildScope(Scope *parent){
    scope->SetParent(parent);
}


StmtBlock::StmtBlock(List<VarDecl*> *d, List<Stmt*> *s) {
    Assert(d != NULL && s != NULL);
    (decls=d)->SetParentAll(this);
    (stmts=s)->SetParentAll(this);
}

void StmtBlock::BuildScope(Scope *parent){
    scope->SetParent(parent);

    for (int i = 0; i < decls->NumElements(); i ++)
        scope->AddDecl(decls->Nth(i));

    for (int i = 0; i < decls->NumElements(); i++)
        decls->Nth(i)->BuildScope(scope);

    for (int i = 0; i < stmts->NumElements(); i++)
        stmts->Nth(i)->BuildScope(scope);

}

void StmtBlock::Check(){
    for (int i = 0; i < decls->NumElements(); i++)
        decls->Nth(i)->Check();

    for (int i = 0; i < stmts->NumElements(); i++)
        stmts->Nth(i)->Check();
}


ConditionalStmt::ConditionalStmt(Expr *t, Stmt *b) { 
    Assert(t != NULL && b != NULL);
    (test=t)->SetParent(this); 
    (body=b)->SetParent(this);
}

void ConditionalStmt::BuildScope(Scope *parent) {
    scope->SetParent(parent);

    test->BuildScope(scope);
    body->BuildScope(scope);
}

void ConditionalStmt::Check(){
    test->Check();
    body->Check();

    // if (!test->GetType()->IsEquivalentTo(Type::boolType))
    //     ReportError::TestNoBoolean(test);
}


void LoopStmt::BuildScope(Scope *parent){
    scope->SetParent(parent);

    test->BuildScope(scope);
    body->BuildScope(scope);
}

ForStmt::ForStmt(Expr *i, Expr *t, Expr *s, Stmt *b): LoopStmt(t, b) { 
    Assert(i != NULL && t != NULL && s != NULL && b != NULL);
    (init=i)->SetParent(this);
    (step=s)->SetParent(this);
}


IfStmt::IfStmt(Expr *t, Stmt *tb, Stmt *eb): ConditionalStmt(t, tb) { 
    Assert(t != NULL && tb != NULL); // else can be NULL
    elseBody = eb;
    if (elseBody) elseBody->SetParent(this);
}

void IfStmt::BuildScope(Scope *parent){
    scope->SetParent(parent);

    test->BuildScope(scope);
    body->BuildScope(scope);

    if (elseBody != NULL)
        elseBody->BuildScope(scope);
}

void IfStmt::Check() {
    test->Check();
    body->Check();

    // if (!test->GetType()->IsEquivalentTo(Type::boolType))
    //     ReportError::TestNoBoolean(test);   

    if (elseBody != NULL)
        elseBody->Check();

}

void BreakStmt::Check() {
    LoopStmt *lp = NULL;
    Scope *s = scope;

    // PP4
    // while(s != NULL){
    //     if((lp = s->GetLoopDecl()) != NULL)
    //         break;

    //     s = s->GetParent();
    // }

    // if (lp == NULL)
    //     ReportError::BreakOutsideLoop(this);

}

ReturnStmt::ReturnStmt(yyltype loc, Expr *e) : Stmt(loc) { 
    Assert(e != NULL);
    (expr=e)->SetParent(this);
}

void ReturnStmt::BuildScope(Scope *parent){
    scope->SetParent(parent);

    expr->BuildScope(scope);
}
  
void ReturnStmt::Check() {
    expr->Check();

    //Recuperamos la declaracion de funcion
    FnDecl *fn = NULL;
    Scope *s = scope;

    // PP4
    // while(s != NULL){
    //     if((fn = s->GetFunctionDecl()) != NULL)
    //         break;
    //     s = s->GetParent();
    // }

    // if (fn == NULL) {
    //     ReportError::Formatted(location,
    //                            "return is only allowed inside a function");
    //     return;
    // }

    // Type *expected = fn->GetReturnType();
    // Type *given = expr->GetType();

    // if(!given->IsEquivalentTo(expected))
    //     ReportError::ReturnMismatch(this, given, expected);

}

PrintStmt::PrintStmt(List<Expr*> *a) {    
    Assert(a != NULL);
    (args=a)->SetParentAll(this);
}

void PrintStmt::BuildScope(Scope *parent){
    scope->SetParent(parent);

    for(int i=0; i<args->NumElements(); i++)
        args->Nth(i)->BuildScope(scope);
    
}

void PrintStmt::Check() {
    //PP4
    // ???

    for(int i = 0; i < args->NumElements(); i++)
        args->Nth(i)->Check();

}

