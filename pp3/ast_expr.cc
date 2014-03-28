/* File: ast_expr.cc
 * -----------------
 * Implementation of expression node classes.
 */
#include "ast_expr.h"
#include "ast_type.h"
#include "ast_decl.h"
#include <string.h>
#include "errors.h"

ClassDecl* Expr::GetClassDecl(Scope *scope) {
    ClassDecl *c = NULL;
    Scope *s = scope;
    while(s != NULL && (c = s->GetClassDecl()) == NULL)
        s = s->GetParent();
    return c;
}

Decl* Expr::GetFieldDecl(Identifier *f, Scope *scope){
    Decl *lookup = NULL;
    Scope *s = scope;
    while(s != NULL && (lookup = s->table->Lookup(f->Name())) == NULL){
        s = s->GetParent();
    }
    return lookup;
}


IntConstant::IntConstant(yyltype loc, int val) : Expr(loc) {
    value = val;
}

DoubleConstant::DoubleConstant(yyltype loc, double val) : Expr(loc) {
    value = val;
}

BoolConstant::BoolConstant(yyltype loc, bool val) : Expr(loc) {
    value = val;
}

StringConstant::StringConstant(yyltype loc, const char *val) : Expr(loc) {
    Assert(val != NULL);
    value = strdup(val);
}

Operator::Operator(yyltype loc, const char *tok) : Node(loc) {
    Assert(tok != NULL);
    strncpy(tokenString, tok, sizeof(tokenString));
}
CompoundExpr::CompoundExpr(Expr *l, Operator *o, Expr *r) 
  : Expr(Join(l->GetLocation(), r->GetLocation())) {
    Assert(l != NULL && o != NULL && r != NULL);
    (op=o)->SetParent(this);
    (left=l)->SetParent(this); 
    (right=r)->SetParent(this);
}

CompoundExpr::CompoundExpr(Operator *o, Expr *r) 
  : Expr(Join(o->GetLocation(), r->GetLocation())) {
    Assert(o != NULL && r != NULL);
    left = NULL; 
    (op=o)->SetParent(this);
    (right=r)->SetParent(this);
}
void CompoundExpr::BuildScope(Scope *parent) {
    scope->SetParent(parent);

    if(left != NULL)
        left->BuildScope(scope);

    right->BuildScope(scope);
}

void CompoundExpr::Check() {
    if(left != NULL)
        left->Check();

    right->Check();
}
  
ArrayAccess::ArrayAccess(yyltype loc, Expr *b, Expr *s) : LValue(loc) {
    (base=b)->SetParent(this); 
    (subscript=s)->SetParent(this);
}
     
void ArrayAccess::BuildScope(Scope *parent){
    scope->SetParent(parent);

    if(base != NULL)
        base->BuildScope(scope);

    if(subscript != NULL)
        subscript->BuildScope(scope);
}

FieldAccess::FieldAccess(Expr *b, Identifier *f) 
  : LValue(b? Join(b->GetLocation(), f->GetLocation()) : *f->GetLocation()) {
    Assert(f != NULL); // b can be be NULL (just means no explicit base)
    base = b; 
    if (base) base->SetParent(this); 
    (field=f)->SetParent(this);
}

void FieldAccess::BuildScope(Scope *parent){
    scope->SetParent(parent);

    if(base != NULL)
        base->BuildScope(scope);

}

void FieldAccess::Check(){
    if (base != NULL)
        base->Check();

    Decl *d = NULL;

    if (base == NULL){
        ClassDecl *c = GetClassDecl(scope);
        if (c == NULL){
            if ((d = GetFieldDecl(field, scope)) == NULL){
                ReportError::IdentifierNotDeclared(field, LookingForVariable);
                return;
            }
        }
    }

    if (dynamic_cast<VarDecl*>(d) == NULL)
        ReportError::IdentifierNotDeclared(field, LookingForVariable);
}

Call::Call(yyltype loc, Expr *b, Identifier *f, List<Expr*> *a) : Expr(loc)  {
    Assert(f != NULL && a != NULL); // b can be be NULL (just means no explicit base)
    base = b;
    if (base) base->SetParent(this);
    (field=f)->SetParent(this);
    (actuals=a)->SetParentAll(this);
}

void Call::BuildScope(Scope *parent){
    scope->SetParent(parent);

    if(base != NULL)
        base->BuildScope(scope);

    for(int i = 0; i < actuals->NumElements(); i++)
        actuals->Nth(i)->BuildScope(scope);
}

void Call::Check() {
    if (base != NULL)
        base->Check();

    Decl *d;
    Type *t;
    if ( base == NULL ){
        ClassDecl *c = GetClassDecl(scope);
        if(c == NULL){
            if ((d = GetFieldDecl(field, scope)) == NULL){
                ReportError::IdentifierNotDeclared(field, LookingForVariable);
                return;
            }
        }
    }
}

NewExpr::NewExpr(yyltype loc, NamedType *c) : Expr(loc) { 
  Assert(c != NULL);
  (cType=c)->SetParent(this);
}

void NewExpr::Check() {}

NewArrayExpr::NewArrayExpr(yyltype loc, Expr *sz, Type *et) : Expr(loc) {
    Assert(sz != NULL && et != NULL);
    (size=sz)->SetParent(this); 
    (elemType=et)->SetParent(this);
}

void NewArrayExpr::BuildScope(Scope *parent){
    scope->SetParent(parent);

    size->BuildScope(scope);
}
