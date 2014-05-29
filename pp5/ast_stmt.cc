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
#include "codegen.h"


CodeGenerator* Program::cg = new CodeGenerator();

Program::Program(List<Decl*> *d) {
    Assert(d != NULL);
    (decls=d)->SetParentAll(this);
}

void Program::Check() {
    nodeScope = new Scope();
    decls->DeclareAll(nodeScope);
    decls->CheckAll();

    Emit();
}

Location* Program::Emit() {
      /* pp5: here is where the code generation is kicked off.
     *      The general idea is perform a tree traversal of the
     *      entire program, generating instructions as you go.
     *      Each node can have its own way of translating itself,
     *      which makes for a great use of inheritance and
     *      polymorphism in the node classes.
     */
     Decl* mainDecl = NULL;
     for(int i = 0; i < decls->NumElements(); i++){
        Decl* decl = decls->Nth(i);
        if(strcmp(decl->GetName(), "main") == 0){
            mainDecl = decl;
        }else{
            decl->Emit();
        }
     }

     if(mainDecl)
        mainDecl->Emit();
    else
        ReportError::NoMainFound();

    Program::cg->DoFinalCodeGen();

    return NULL;
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
  for (int i = 0; i < decls->NumElements(); i++)
    decls->Nth(i)->Emit();

  for(int i = 0; i < stmts->NumElements(); i++)
    stmts->Nth(i)->Emit();

  return NULL;
}

ConditionalStmt::ConditionalStmt(Expr *t, Stmt *b) { 
    Assert(t != NULL && b != NULL);
    (test=t)->SetParent(this); 
    (body=b)->SetParent(this);
}

void ConditionalStmt::Check() {
    body->Check();
}

void LoopStmt::Check() {
    this->GetParent()->GetScope()->SetLoopStmt(this);
    ConditionalStmt::Check();
}

Location* LoopStmt::Emit(){
  char *label_0 = Program::cg->NewLabel();
  char *label_1 = Program::cg->NewLabel();

  Program::cg->GenLabel(label_0);
  Program::cg->GenIfZ(test->Emit(), label_1);

  next = label_1;

  body->Emit();
  
  Program::cg->GenGoto(label_0);
  Program::cg->GenLabel(label_1);
  return NULL;
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

Location* IfStmt::Emit() {
  char *label_0 = Program::cg->NewLabel();
  char *label_1 = Program::cg->NewLabel();

  Program::cg->GenIfZ(test->Emit(), label_0);
  body->Emit();

  Program::cg->GenGoto(label_1);
  Program::cg->GenLabel(label_0);

  if(elseBody)
    elseBody->Emit();

  Program::cg->GenLabel(label_1);

  return NULL;
}

void BreakStmt::Check() {
}

Location* BreakStmt::Emit() {
  Program::cg->GenGoto(dynamic_cast<LoopStmt*>(parent)->next);
  return NULL;
}

ReturnStmt::ReturnStmt(yyltype loc, Expr *e) : Stmt(loc) { 
    Assert(e != NULL);
    (expr=e)->SetParent(this);
}

void ReturnStmt::Check() {
}

Location* ReturnStmt::Emit() {
  if(expr)
    Program::cg->GenReturn(expr->Emit());
  else
    Program::cg->GenReturn(NULL);

  return NULL;
}

PrintStmt::PrintStmt(List<Expr*> *a) {    
    Assert(a != NULL);
    (args=a)->SetParentAll(this);
}

void PrintStmt::Check() {
    args->CheckAll();
}

Location* PrintStmt::Emit() {
  for(int i = 0; i < args->NumElements(); i++){
    Expr *e = args->Nth(i);
    Type *type = e->GetType();

    if(type->IsEquivalentTo(Type::intType))
      Program::cg->GenBuiltInCall(PrintInt, e->Emit());
    else if(type->IsEquivalentTo(Type::stringType))
      Program::cg->GenBuiltInCall(PrintString, e->Emit());
    else if(type->IsEquivalentTo(Type::boolType))
      Program::cg->GenBuiltInCall(PrintBool, e->Emit());
  }
  return NULL;
}