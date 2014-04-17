/* File: ast_expr.cc
 * -----------------
 * Implementation of expression node classes.
 */
#include "ast_expr.h"
#include "ast_type.h"
#include "ast_decl.h"
#include <string.h>

#include "errors.h"

bool Expr::IsBool() {
    return GetType()->IsEquivalentTo(Type::boolType);
}

Type* Expr::GetType() {
    return Type::nullType;
}


Type* EmptyExpr::GetType() {
    return Type::errorType;
}

IntConstant::IntConstant(yyltype loc, int val) : Expr(loc) {
    value = val;
}

Type* IntConstant::GetType() {
    return Type::intType;
}

DoubleConstant::DoubleConstant(yyltype loc, double val) : Expr(loc) {
    value = val;
}

Type* DoubleConstant::GetType() {
    return Type::doubleType;
}

BoolConstant::BoolConstant(yyltype loc, bool val) : Expr(loc) {
    value = val;
}

Type* BoolConstant::GetType() {
    return Type::boolType;
}

StringConstant::StringConstant(yyltype loc, const char *val) : Expr(loc) {
    Assert(val != NULL);
    value = strdup(val);
}

Type* StringConstant::GetType() {
    return Type::stringType;
}

Type* NullConstant::GetType() {
    return Type::nullType;
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

void CompoundExpr::Check() {
    right->Check();
    if(left!=NULL)
        left->Check();
}

void ArithmeticExpr::Check() {
    right->Check();
    if(left!=NULL)
        left->Check();

    Type* rtype = right->GetType();

    if(rtype->IsEquivalentTo(Type::errorType))
        return;

    if(left == NULL){
        if(!rtype->IsEquivalentTo(Type::intType) && !rtype->IsEquivalentTo(Type::doubleType))
            ReportError::IncompatibleOperand(op, rtype);
    }else{
        Type* ltype = left->GetType();

        if(ltype->IsEquivalentTo(Type::errorType))
            return;

        if(rtype->IsEquivalentTo(Type::intType) && !ltype->IsEquivalentTo(Type::intType))
            ReportError::IncompatibleOperands(op, ltype, rtype);
        else if (rtype->IsEquivalentTo(Type::doubleType) && !ltype->IsEquivalentTo(Type::doubleType))
            ReportError::IncompatibleOperands(op, ltype, rtype);
        else if(!rtype->IsEquivalentTo(Type::intType) && ltype->IsEquivalentTo(Type::intType))
            ReportError::IncompatibleOperands(op, ltype, rtype);
        else if(!rtype->IsEquivalentTo(Type::doubleType) && ltype->IsEquivalentTo(Type::doubleType))
            ReportError::IncompatibleOperands(op, ltype, rtype);
    }
}

Type* ArithmeticExpr::GetType() {
    Type* rtype = right->GetType();
    if(left == NULL){
        return rtype;
    }else{
        Type* ltype = left->GetType();
        if(rtype->IsEquivalentTo(ltype))
            return rtype;
        else
            return Type::errorType;
    }
}

void RelationalExpr::Check() {
    right->Check();
    left->Check();

    Type* rtype = right->GetType();
    Type* ltype = left->GetType();


    if(rtype->IsEquivalentTo(Type::intType) && !ltype->IsEquivalentTo(Type::intType))
        ReportError::IncompatibleOperands(op, ltype, rtype);
    else if (rtype->IsEquivalentTo(Type::doubleType) && !ltype->IsEquivalentTo(Type::doubleType))
        ReportError::IncompatibleOperands(op, ltype, rtype);
    else if(!rtype->IsEquivalentTo(Type::intType) && ltype->IsEquivalentTo(Type::intType))
        ReportError::IncompatibleOperands(op, ltype, rtype);
    else if(!rtype->IsEquivalentTo(Type::doubleType) && ltype->IsEquivalentTo(Type::doubleType))
        ReportError::IncompatibleOperands(op, ltype, rtype);
}

Type* RelationalExpr::GetType() {
    Type* rtype = right->GetType();
    Type* ltype = left->GetType();


    if(rtype->IsEquivalentTo(Type::intType) && !ltype->IsEquivalentTo(Type::intType))
        return Type::errorType;
    else if (rtype->IsEquivalentTo(Type::doubleType) && !ltype->IsEquivalentTo(Type::doubleType))
        return Type::errorType;
    else if(!rtype->IsEquivalentTo(Type::intType) && ltype->IsEquivalentTo(Type::intType))
        return Type::errorType;
    else if(!rtype->IsEquivalentTo(Type::doubleType) && ltype->IsEquivalentTo(Type::doubleType))
        return Type::errorType;

    return Type::boolType;
}

Type* EqualityExpr::GetType() {
    return Type::boolType;
}

void LogicalExpr::Check() {
    right->Check();
    if(left!=NULL)
        left->Check();

    Type* rtype = right->GetType();
    if(left == NULL){
        if(!rtype->IsEquivalentTo(Type::boolType))
            ReportError::IncompatibleOperand(op, rtype);
    }else{
        Type* ltype = left->GetType();
        if(rtype->IsEquivalentTo(Type::boolType) && !ltype->IsEquivalentTo(Type::boolType))
            ReportError::IncompatibleOperands(op, ltype, rtype);
        else if(!rtype->IsEquivalentTo(Type::boolType) && ltype->IsEquivalentTo(Type::boolType))
            ReportError::IncompatibleOperands(op, ltype, rtype);
    }
}

Type* LogicalExpr::GetType() {
    Type* rtype = right->GetType();
    if(left == NULL){
        if(!rtype->IsEquivalentTo(Type::boolType))
            return Type::errorType;
        return Type::boolType;
    }else{
        Type* ltype = left->GetType();
        if(rtype->IsEquivalentTo(Type::boolType) && !ltype->IsEquivalentTo(Type::boolType))
            return Type::errorType;
        else if(!rtype->IsEquivalentTo(Type::boolType) && ltype->IsEquivalentTo(Type::boolType))
            return Type::errorType;

        return Type::boolType;
    }
}

void AssignExpr::Check() {
    right->Check();
    left->Check();

    Type *rtype = right->GetType();
    Type *ltype = left->GetType();

    if(ltype->IsEquivalentTo(Type::errorType) || rtype->IsEquivalentTo(Type::errorType))
        return;

    if(!rtype->IsEquivalentTo(ltype))
        ReportError::IncompatibleOperands(op, ltype, rtype);
}

void This::Check() {
    Scope* s = GetParent()->GetScope();
    if (s && s->GetClassDecl())
        return;
    ReportError::ThisOutsideClassScope(this);
}

Type* This::GetType() {
    Scope *s = GetParent()->GetScope();
    if (s != NULL){
        ClassDecl *classDecl = s->GetClassDecl();
        if(classDecl != NULL){
            return classDecl->GetType();
        }else{
            return Type::errorType;
        }
    }
    return Type::errorType;
}

ArrayAccess::ArrayAccess(yyltype loc, Expr *b, Expr *s) : LValue(loc) {
    (base=b)->SetParent(this); 
    (subscript=s)->SetParent(this);
}

void ArrayAccess::Check() {
    base->Check();
    subscript->Check();

    if(!subscript->GetType()->IsEquivalentTo(Type::intType))
        ReportError::SubscriptNotInteger(subscript);

    //Checamos que base sea array
    if(dynamic_cast<ArrayType*>(base->GetType()) == NULL)
        ReportError::BracketsOnNonArray(base);
}

Type* ArrayAccess::GetType() {
   ArrayType* arrType = dynamic_cast<ArrayType*>(base->GetType()); 
   if(arrType)
        return arrType->GetElemType();
   return base->GetType();
}

FieldAccess::FieldAccess(Expr *b, Identifier *f) 
  : LValue(b? Join(b->GetLocation(), f->GetLocation()) : *f->GetLocation()) {
    Assert(f != NULL); // b can be be NULL (just means no explicit base)
    base = b; 
    if (base) base->SetParent(this); 
    (field=f)->SetParent(this);
}

void FieldAccess::Check() {
    if(base != NULL){

        Type* btype = base->GetType();
        NamedType* ntype = dynamic_cast<NamedType*>(btype);
        if(ntype != NULL){
            //Class.field
            //Revisamos que nos encontramos en class scope
            Scope *s = GetParent()->GetScope();
            if(s == NULL || s->GetClassDecl() == NULL){
                ReportError::InaccessibleField(field, btype);
                return;
            }
        }else{
            //type.field
            ReportError::FieldNotFoundInBase(field, btype);
            return;
        }
       
    }
}

Type* FieldAccess::GetType() {
    Decl *d = this->FindDecl(field);
    VarDecl *varDecl = dynamic_cast<VarDecl*>(d);
    if(varDecl!=NULL)
        return varDecl->GetDeclaredType();
    else
        return Type::errorType;
}

Call::Call(yyltype loc, Expr *b, Identifier *f, List<Expr*> *a) : Expr(loc)  {
    Assert(f != NULL && a != NULL); // b can be be NULL (just means no explicit base)
    base = b;
    if (base) base->SetParent(this);
    (field=f)->SetParent(this);
    (actuals=a)->SetParentAll(this);
}

void Call::Check() {
    if(base!= NULL)
        base->Check();

    field->Check();
    actuals->CheckAll();
}

Type* Call::GetType() {
    Decl* d = FindDecl(field);
    FnDecl* fn = dynamic_cast<FnDecl*>(d);
    if(fn != NULL) {
        fn->GetType();
    }
    return Type::errorType;
}
 

NewExpr::NewExpr(yyltype loc, NamedType *c) : Expr(loc) { 
  Assert(c != NULL);
  (cType=c)->SetParent(this);
}


NewArrayExpr::NewArrayExpr(yyltype loc, Expr *sz, Type *et) : Expr(loc) {
    Assert(sz != NULL && et != NULL);
    (size=sz)->SetParent(this); 
    (elemType=et)->SetParent(this);
}

void NewArrayExpr::Check() {
    size->Check();
    elemType->Check();

    if(!size->GetType()->IsEquivalentTo(Type::intType))
        ReportError::NewArraySizeNotInteger(size);
}

Type* NewArrayExpr::GetType() {
    return new ArrayType(elemType);
}
       
