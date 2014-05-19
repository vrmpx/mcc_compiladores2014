/* File: ast_expr.cc
 * -----------------
 * Implementation of expression node classes.
 */
#include "ast_expr.h"
#include "ast_type.h"
#include "ast_decl.h"
#include <string.h>

#include "errors.h"

#include <stdio.h>
 using namespace std;


ClassDecl* GetClassFromScope(Node* node){
    ClassDecl* c;
    while(node != NULL){
        if((c = dynamic_cast<ClassDecl*>(node)) != NULL)
            return c;
        node = node->GetParent();
    }
    return NULL;
}

Decl* FindDeclInClass(ClassDecl* classDecl, Identifier* field){
    Scope *s = classDecl->GetScope();

    if(s == NULL)
        return NULL;
    
    //Buscamos la definicion de la funcion en su clase
    return s->Lookup(field);
}

bool Expr::IsBool() {
    return GetType()->IsEquivalentTo(Type::boolType);
}

Type* Expr::GetType() {
    return Type::nullType;
}


Type* EmptyExpr::GetType() {
    return Type::voidType;
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
    if(left!=NULL)
        left->Check();
    right->Check();
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

Type* This::GetType() {
    ClassDecl* c = GetClassFromScope(this);
    if(c != NULL)
        return c->GetType();
    return Type::errorType;
}

ArrayAccess::ArrayAccess(yyltype loc, Expr *b, Expr *s) : LValue(loc) {
    (base=b)->SetParent(this); 
    (subscript=s)->SetParent(this);
}

void ArrayAccess::Check() {
    base->Check();
    subscript->Check();
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
    if(base!=NULL)
        base->Check();
    field->Check();
}

Type* FieldAccess::GetType() {
    if ( base != NULL) {
        //Obtenemos la clase de base
        NamedType* ntype = dynamic_cast<NamedType*>(base->GetType());
        if (ntype != NULL){

            // cout << "FieldAccess::"<<field->GetName() << "::Check With Base " << ntype->GetId() << endl;

            ClassDecl* d = dynamic_cast<ClassDecl*>(this->FindDecl(ntype->GetId()));
            if ( d != NULL ){
                //Buscamos la declaracion del campo en la clase
                Decl* lookup = FindDeclInClass(d, field);
                if ( lookup != NULL ){
                    return lookup->GetType();
                }
            }
        }
        return Type::errorType;
    } else {
        Decl* d = this->FindDecl(field);
        if(d == NULL || dynamic_cast<VarDecl*>(d) == NULL)
            return Type::errorType;

        return d->GetType();
    }
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

    if (base != NULL){
         //Obtenemos la clase de base
        NamedType* ntype = dynamic_cast<NamedType*>(base->GetType());
        if (ntype != NULL){

            // cout << "FieldAccess::"<<field->GetName() << "::Check With Base " << ntype->GetId() << endl;

            ClassDecl* d = dynamic_cast<ClassDecl*>(this->FindDecl(ntype->GetId()));
            if ( d != NULL ){
                //Buscamos la declaracion del campo en la clase
                Decl* lookup = FindDeclInClass(d, field);
                if ( lookup != NULL ){
                    return lookup->GetType();
                }
            }
        }
    } else { 
        Decl* d = FindDecl(field);
        FnDecl* fn = dynamic_cast<FnDecl*>(d);
        if(fn != NULL) {
            return fn->GetType();
        }
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
}

Type* NewArrayExpr::GetType() {
    return new ArrayType(elemType);
}

Type* ReadLineExpr::GetType() {
    return Type::stringType;
}

Type* ReadIntegerExpr::GetType() {
    return Type::intType;
}
       
