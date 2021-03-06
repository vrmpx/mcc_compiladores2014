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

bool Decl::IsEquivalentTo(Decl* d){
    return true;
}

VarDecl::VarDecl(Identifier *n, Type *t) : Decl(n) {
    Assert(n != NULL && t != NULL);
    (type=t)->SetParent(this);
}

void VarDecl::Check() {
    if(type->IsPrimitive())
        return;

    Scope *s = scope;
    Decl* d;
    while(s != NULL){
        if ((d = s->GetTable()->Lookup(type->Name())) != NULL){
            if(dynamic_cast<ClassDecl*>(d) == NULL && dynamic_cast<InterfaceDecl*>(d) == NULL)
                type->ReportNotDeclaredIdentifier(LookingForType);
            return;   
        }
        s = s->GetParent();
    }
    type->ReportNotDeclaredIdentifier(LookingForType);
}

bool VarDecl::IsEquivalentTo(Decl* d){
    VarDecl* other = dynamic_cast<VarDecl*>(d);

    if(other == NULL)
        return false;

    if(!type->IsEquivalentTo(other->type))
        return false;

    return true;
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
    for(int i = 0; i < members->NumElements(); i++)
        members->Nth(i)->Check();

    CheckExtends();
    CheckImplements();

    for (int i = 0; i < implements->NumElements(); i++)
        CheckImplemented(implements->Nth(i));

    CheckExtended(extends);

}

void ClassDecl::CheckExtends() {
    if(extends == NULL)
        return;

    Decl* lookup = scope->GetParent()->GetTable()->Lookup(extends->Name());
    if(dynamic_cast<ClassDecl*>(lookup) == NULL)
        extends->ReportNotDeclaredIdentifier(LookingForClass);
}

void ClassDecl::CheckExtended(NamedType *ext){
    if(ext == NULL)
        return;

    Decl* lookup = scope->GetParent()->GetTable()->Lookup(ext->Name());
    ClassDecl* c = dynamic_cast<ClassDecl*>(lookup);

    if(c == NULL)
        return;

    CheckExtended(c->extends);
    CheckOverrides(c->GetScope());
}

void ClassDecl::CheckImplements() {
    Scope *s = scope->GetParent();

    for (int i = 0, n = implements->NumElements(); i < n; ++i) {
        NamedType *nth = implements->Nth(i);
        Decl *lookup = s->GetTable()->Lookup(implements->Nth(i)->Name());

        if (dynamic_cast<InterfaceDecl*>(lookup) == NULL)
            nth->ReportNotDeclaredIdentifier(LookingForInterface);
    }
}

void ClassDecl::CheckImplemented(NamedType *imp){
    Decl* lookup = scope->GetParent()->GetTable()->Lookup(imp->Name());
    InterfaceDecl* intDecl = dynamic_cast<InterfaceDecl*>(lookup);

    if(intDecl == NULL)
        return;

    CheckOverrides(intDecl->GetScope());
}

void ClassDecl::CheckOverrides(Scope *other){
    Iterator<Decl*> iter = scope->GetTable()->GetIterator();
    Decl *d;

    while((d = iter.GetNextValue()) != NULL){
        Decl* lookup = other->GetTable()->Lookup(d->Name());

        if(lookup != NULL && dynamic_cast<VarDecl*>(lookup) != NULL)
            ReportError::DeclConflict(d, lookup);

        if(lookup != NULL && dynamic_cast<FnDecl*>(lookup) != NULL)
            if(!d->IsEquivalentTo(lookup))
                ReportError::OverrideMismatch(d);
    }
}

InterfaceDecl::InterfaceDecl(Identifier *n, List<Decl*> *m) : Decl(n) {
    Assert(n != NULL && m != NULL);
    (members=m)->SetParentAll(this);
}

void InterfaceDecl::BuildScope(Scope* parent){
    scope->SetParent(parent);

    for(int i = 0; i < members->NumElements(); i++)
        scope->AddDecl(members->Nth(i));

    for(int i = 0; i < members->NumElements(); i++)
        members->Nth(i)->BuildScope(scope);

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

bool FnDecl::IsEquivalentTo(Decl* d){
    FnDecl* other = dynamic_cast<FnDecl*>(d);

    if(other == NULL)
        return false;

    if(!returnType->IsEquivalentTo(other->returnType))
        return false;

    if(formals->NumElements() != other->formals->NumElements())
        return false;

    for(int i = 0; i < formals->NumElements(); i++)
        if(!formals->Nth(i)->IsEquivalentTo(other->formals->Nth(i)))
            return false;

    return true;
}

void FnDecl::BuildScope(Scope *parent) {
    scope->SetParent(parent);
    scope->SetFunctionDecl(this);

    for(int i = 0; i < formals->NumElements(); i++)
        scope->AddDecl(formals->Nth(i));

    for(int i = 0; i < formals->NumElements(); i++)
        formals->Nth(i)->BuildScope(scope);

    if(body != NULL)
        body->BuildScope(scope);
}

void FnDecl::Check() {
   for (int i = 0; i < formals->NumElements(); i++)
        formals->Nth(i)->Check();

    if (body != NULL)
        body->Check();
}
