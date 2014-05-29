/* File: ast_stmt.cc
 * -----------------
 * Implementation of statement node classes.
 */
#include "ast_stmt.h"
#include "ast_type.h"
#include "ast_decl.h"
#include "ast_expr.h"
#include "scope.h"
#include "errors.h"

CodeGenerator *Program::cg = new CodeGenerator();

Program::Program(List<Decl*> *d) {
    Assert(d != NULL);
    (decls=d)->SetParentAll(this);
}

void Program::Check() {
    nodeScope = new Scope();
    decls->DeclareAll(nodeScope);
    decls->CheckAll();
}

Location* Program::Emit() {
    /* pp5: here is where the code generation is kicked off.
     *      The general idea is perform a tree traversal of the
     *      entire program, generating instructions as you go.
     *      Each node can have its own way of translating itself,
     *      which makes for a great use of inheritance and
     *      polymorphism in the node classes.
     */
     for(int i = 0; i < decls->NumElements(); i++){
        decls->Nth(i)->Emit();
     }
}

StmtBlock::StmtBlock(List<VarDecl*> *d, List<Stmt*> *s) {
    Assert(d != NULL && s != NULL);
    (decls=d)->SetParentAll(this);
    (stmts=s)->SetParentAll(this);
}
void StmtBlock::Check() {
    nodeScope = new Scope();
    decls->DeclareAll(nodeScope);
    decls->CheckAll();
    stmts->CheckAll();
}

Location* StmtBlock::Emit() { 
    for(int i = 0; i < decls->NumElements(); i++){
        decls->Nth(i)->Emit();
    }

    for(int i = 0; i < stmts->NumElements(); i++){
        stmts->Nth(i)->Emit();
    }
}

ConditionalStmt::ConditionalStmt(Expr *t, Stmt *b) { 
    Assert(t != NULL && b != NULL);
    (test=t)->SetParent(this); 
    (body=b)->SetParent(this);
}

void ConditionalStmt::Check() {
    body->Check();
}

Location* ConditionalStmt::Emit() {
    test->Emit();
    body->Emit();
}

void LoopStmt::Check() {
    this->GetParent()->GetScope()->SetLoopStmt(this);
    ConditionalStmt::Check();
}

ForStmt::ForStmt(Expr *i, Expr *t, Expr *s, Stmt *b): LoopStmt(t, b) { 
    Assert(i != NULL && t != NULL && s != NULL && b != NULL);
    (init=i)->SetParent(this);
    (step=s)->SetParent(this);
}

Location* ForStmt::Emit() {
    ConditionalStmt::Emit();
    init->Emit();
    step->Emit();
}

IfStmt::IfStmt(Expr *t, Stmt *tb, Stmt *eb): ConditionalStmt(t, tb) { 
    Assert(t != NULL && tb != NULL); // else can be NULL
    elseBody = eb;
    if (elseBody) elseBody->SetParent(this);
}

void IfStmt::Check() {
    ConditionalStmt::Check();
    if (elseBody) elseBody->Check();
}

Location* IfStmt::Emit() {
    ConditionalStmt::Emit();
    if(elseBody)
        elseBody->Emit();
    return NULL;
}

ReturnStmt::ReturnStmt(yyltype loc, Expr *e) : Stmt(loc) { 
    Assert(e != NULL);
    (expr=e)->SetParent(this);
}

PrintStmt::PrintStmt(List<Expr*> *a) {    
    Assert(a != NULL);
    (args=a)->SetParentAll(this);
}

void PrintStmt::Check() {args->CheckAll();}

Location* PrintStmt::Emit() {
    for (int i = 0; i < args->NumElements(); i++){
        Expr *expr = args->Nth(i);

        Type *type = expr->GetType();
        if (type == Type::intType)
            Program::cg->GenBuiltInCall(PrintInt, expr->Emit());
        else if (type == Type::stringType)
            Program::cg->GenBuiltInCall(PrintString, expr->Emit());
        else if (type == Type::boolType)
            Program::cg->GenBuiltInCall(PrintBool, expr->Emit());
    }
    return NULL;
}
