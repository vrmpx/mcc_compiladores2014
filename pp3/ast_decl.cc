/* File: ast_decl.cc
 * -----------------
 * Implementation of Decl node classes.
 */
#include "ast_decl.h"
#include "ast_type.h"
#include "ast_stmt.h"
        
         
Decl::Decl(Identifier *n) : Node(*n->GetLocation()), scope(new Scope) {
    Assert(n != NULL);
    (id=n)->SetParent(this); 
}

void Decl::BuildScope(Scope *parent){
    scope->SetParent(parent);
}

bool Decl::IsEquivalentTo(Decl* other) {
    return true;
}

VarDecl::VarDecl(Identifier *n, Type *t) : Decl(n) {
    Assert(n != NULL && t != NULL);
    (type=t)->SetParent(this);
}

bool VarDecl::IsEquivalentTo(Decl* other){
    VarDecl* varDecl = dynamic_cast<VarDecl*>(other);
    if(varDecl == NULL)
        return false;

    return type->IsEquivalentTo(varDecl->type);
}

void VarDecl::Check() {
    if(type->IsPrimitive())
        return;

    Scope *s = scope;
    Decl *d = NULL;
    while (s != NULL) {
        if ((d = s->table->Lookup(type->Name())) != NULL) {
            if (dynamic_cast<ClassDecl*>(d) == NULL &&
                dynamic_cast<InterfaceDecl*>(d) == NULL)
                type->ReportNotDeclaredIdentifier(LookingForType);

            return;
        }
        s = s->GetParent();
    }

    type->ReportNotDeclaredIdentifier(LookingForType);
}

ClassDecl::ClassDecl(Identifier *n, NamedType *ex, List<NamedType*> *imp, List<Decl*> *m) : Decl(n) {
    // extends can be NULL, impl & mem may be empty lists but cannot be NULL
    Assert(n != NULL && imp != NULL && m != NULL);     
    extends = ex;
    if (extends) extends->SetParent(this);
    (implements=imp)->SetParentAll(this);
    (members=m)->SetParentAll(this);
}

void ClassDecl::BuildScope(Scope *parent){
    scope->SetParent(parent);
    scope->SetClassDecl(this);

    for(int i = 0; i < members->NumElements(); i++)
        scope->AddDecl(members->Nth(i));

    for(int i = 0; i < members->NumElements(); i++)
        members->Nth(i)->BuildScope(scope);
}

void ClassDecl::Check() {
    CheckExtends();

    for(int i = 0; i < members->NumElements(); i++)
        members->Nth(i)->Check();
}

void ClassDecl::CheckExtends() {
    if (extends == NULL)
        return;

    Decl *lookup = scope->GetParent()->table->Lookup(extends->Name());
    if(dynamic_cast<ClassDecl *>(lookup) == NULL)
        extends->ReportNotDeclaredIdentifier(LookingForClass);
}

void ClassDecl::CheckExtendedMembers(NamedType *extType){
    if(extType == NULL)
        return;

    Decl* lookup = scope->GetParent()->table->Lookup(extType->Name());
    ClassDecl* extDecl = dynamic_cast<ClassDecl*>(lookup);

    if(extDecl == NULL)
        return;

    CheckExtendedMembers(extDecl->extends);
    CheckOverride(extDecl->scope);
}

void ClassDecl::CheckOverride(Scope *other){
    Iterator<Decl*> iter = scope->table->GetIterator();
    Decl *d;

    while((d = iter.GetNextValue()) != NULL){
        Decl *lookup = other->table->Lookup(d->Name());

        if(lookup == NULL)
            continue;

        if(dynamic_cast<VarDecl*>(lookup) != NULL)
            ReportError::DeclConflict(d, lookup);

        if(dynamic_cast<FnDecl*>(lookup) != NULL && !d->IsEquivalentTo(lookup))
            ReportError::OverrideMismatch(d);
    }
}

InterfaceDecl::InterfaceDecl(Identifier *n, List<Decl*> *m) : Decl(n) {
    Assert(n != NULL && m != NULL);
    (members=m)->SetParentAll(this);
}

void InterfaceDecl::BuildScope(Scope *parent) {
    scope->SetParent(parent);

    for(int i = 0; i < members->NumElements(); i++)
        scope->AddDecl(members->Nth(i));

    for(int i = 0; i < members->NumElements(); i++)
        members->Nth(i)->BuildScope(scope);
}

void InterfaceDecl::Check() {
    for(int i = 0; i < members->NumElements(); i++)
        members->Nth(i)->Check();
}

	
FnDecl::FnDecl(Identifier *n, Type *r, List<VarDecl*> *d) : Decl(n) {
    Assert(n != NULL && r!= NULL && d != NULL);
    (returnType=r)->SetParent(this);
    (formals=d)->SetParentAll(this);
    body = NULL;
}

void FnDecl::SetFunctionBody(Stmt *b) { 
    (body=b)->SetParent(this);
}

void FnDecl::BuildScope(Scope *parent){
    scope->SetParent(parent);
    scope->SetFunctionDecl(this);

    for(int i = 0; i < formals->NumElements(); i++)
        scope->AddDecl(formals->Nth(i));

    for(int i = 0; i < formals->NumElements(); i++)
        formals->Nth(i)->BuildScope(scope);

    if(body != NULL)
        body->BuildScope(scope);
}

bool FnDecl::IsEquivalentTo(Decl* other){
    FnDecl* fnDecl = dynamic_cast<FnDecl*>(other);
    if(fnDecl == NULL)
        return false;

    if(!returnType->IsEquivalentTo(fnDecl->returnType))
        return false;

    if(formals->NumElements() != fnDecl->formals->NumElements())
        return false;

    for(int i = 0; i < formals->NumElements(); i++){
        if(!formals->Nth(i)->IsEquivalentTo(fnDecl->formals->Nth(i)))
            return false;
    }
    return true;
}

void FnDecl::Check(){
    for (int i = 0; i < formals->NumElements(); i++)
        formals->Nth(i)->Check();

    if(body != NULL)
        body->Check();
}