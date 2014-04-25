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


Program::Program(List<Decl*> *d) {
    Assert(d != NULL);
    (decls=d)->SetParentAll(this);
}

void Program::Check() {
    nodeScope = new Scope();
    decls->DeclareAll(nodeScope);
    decls->CheckAll();
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

ConditionalStmt::ConditionalStmt(Expr *t, Stmt *b) { 
    Assert(t != NULL && b != NULL);
    (test=t)->SetParent(this); 
    (body=b)->SetParent(this);
}

void ConditionalStmt::Check() {
    body->Check();

   if(!test->GetType()->IsEquivalentTo(Type::errorType) && !test->IsBool()){
        ReportError::TestNotBoolean(test);
    }

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

IfStmt::IfStmt(Expr *t, Stmt *tb, Stmt *eb): ConditionalStmt(t, tb) { 
    Assert(t != NULL && tb != NULL); // else can be NULL
    elseBody = eb;
    if (elseBody) elseBody->SetParent(this);
}

void IfStmt::Check() {
    ConditionalStmt::Check();
    if (elseBody) elseBody->Check();
}

void BreakStmt::Check() {
    Node *parent = this->GetParent();
    Scope *s;
    while(parent != NULL){
        s = parent->GetScope();
        if(s && s->GetLoopStmt() != NULL)
            return;
        parent = parent->GetParent();
    }
    ReportError::BreakOutsideLoop(this);
}

ReturnStmt::ReturnStmt(yyltype loc, Expr *e) : Stmt(loc) { 
    Assert(e != NULL);
    (expr=e)->SetParent(this);
}

void ReturnStmt::Check() {
    Node *parent = this->GetParent();
    FnDecl *fn = NULL;
    while (parent != NULL){

        if((fn = dynamic_cast<FnDecl*>(parent)) != NULL)
            break;

        parent = parent->GetParent();
    }

    Type *expected = fn->GetType();
    Type *actual = expr->GetType();
    if (!expected->IsEquivalentTo(actual)){
        ReportError::ReturnMismatch(this, actual, expected);
        return;
    }
}

PrintStmt::PrintStmt(List<Expr*> *a) {    
    Assert(a != NULL);
    (args=a)->SetParentAll(this);
}

void PrintStmt::Check() {
    args->CheckAll();

    Type* t;
    for(int i = 0; i < args->NumElements(); i++){
        t = args->Nth(i)->GetType();
        if (   !t->IsEquivalentTo(Type::errorType)  && !t->IsEquivalentTo(Type::intType) 
            && !t->IsEquivalentTo(Type::stringType) && !t->IsEquivalentTo(Type::boolType))
            ReportError::PrintArgMismatch(args->Nth(i), i + 1, t);
    }
}

