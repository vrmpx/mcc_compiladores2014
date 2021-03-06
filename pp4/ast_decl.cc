/* File: ast_decl.cc
 * -----------------
 * Implementation of Decl node classes.
 */
#include "ast_decl.h"
#include "ast_type.h"
#include "ast_stmt.h"
#include "scope.h"
#include "errors.h"
#include <stdio.h>
using namespace std;

        
         
Decl::Decl(Identifier *n) : Node(*n->GetLocation()) {
    Assert(n != NULL);
    (id=n)->SetParent(this); 
}

bool Decl::ConflictsWithPrevious(Decl *prev) {
    ReportError::DeclConflict(this, prev);
    return true;
}

VarDecl::VarDecl(Identifier *n, Type *t) : Decl(n) {
    Assert(n != NULL && t != NULL);
    (type=t)->SetParent(this);
}
  
void VarDecl::Check() { type->Check(); }

ClassDecl::ClassDecl(Identifier *n, NamedType *ex, List<NamedType*> *imp, List<Decl*> *m) : Decl(n) {
    // extends can be NULL, impl & mem may be empty lists but cannot be NULL
    Assert(n != NULL && imp != NULL && m != NULL);     
    extends = ex;
    if (extends) extends->SetParent(this);
    (implements=imp)->SetParentAll(this);
    (members=m)->SetParentAll(this);
    cType = new NamedType(n);
    cType->SetParent(this);
    convImp = NULL;
}

void ClassDecl::Check() {
    if (extends && !extends->IsClass()) {
        ReportError::IdentifierNotDeclared(extends->GetId(), LookingForClass);
        extends = NULL;
    }
    for (int i = 0; i < implements->NumElements(); i++) {
        NamedType *in = implements->Nth(i);
        if (!in->IsInterface()) {
            ReportError::IdentifierNotDeclared(in->GetId(), LookingForInterface);
            implements->RemoveAt(i--);
        }else{
            // cout << "CheckImplemented(" << in->GetId() << ")" << endl;
            //Find decl in scope
            InterfaceDecl *interfaceDecl = dynamic_cast<InterfaceDecl*>(this->FindDecl(in->GetId()));
            if (in != NULL)
                CheckImplemented(interfaceDecl, this, in);
        }
    }
    PrepareScope();
    members->CheckAll();
}

void ClassDecl::CheckImplemented(InterfaceDecl* in, ClassDecl* actual, NamedType *intype){
    List<Decl*> *declsToImplement = in->GetMembers();
    List<Decl*> *declsImplemented = actual->GetMembers();
    bool found;
    for(int i = 0; i < declsToImplement->NumElements(); i++){
        found = false;

        //Buscamos en el actual
        for(int j = 0; j < declsImplemented->NumElements() && !found; j++){
            if(strcmp(declsImplemented->Nth(j)->GetName(), declsToImplement->Nth(i)->GetName()) == 0)
                found = true;
        }

        //Recorrimos todos los metodos de la clase y no encontramos el bueno
        if(!found){
            //Checamos el papa
            if(actual->GetExtends() != NULL){
                //Find decl in scope
                ClassDecl *d = dynamic_cast<ClassDecl*>(this->FindDecl(actual->GetExtends()->GetId()));
                CheckImplemented(in, d, intype);
            }else{
                //No encontramos nada...
                ReportError::InterfaceNotImplemented(this, intype);
            }
        }
    }
}

// This is not done very cleanly. I should sit down and sort this out. Right now
// I was using the copy-in strategy from the old compiler, but I think the link to
// parent may be the better way now.
Scope *ClassDecl::PrepareScope()
{
    if (nodeScope) return nodeScope;
    nodeScope = new Scope();
    nodeScope->SetClassDecl(this);

    if (extends) {
        ClassDecl *ext = dynamic_cast<ClassDecl*>(parent->FindDecl(extends->GetId())); 
        if (ext) nodeScope->CopyFromScope(ext->PrepareScope(), this);
    }
    convImp = new List<InterfaceDecl*>;
    for (int i = 0; i < implements->NumElements(); i++) {
        NamedType *in = implements->Nth(i);
        InterfaceDecl *id = dynamic_cast<InterfaceDecl*>(in->FindDecl(in->GetId()));
        if (id) {
        nodeScope->CopyFromScope(id->PrepareScope(), NULL);
            convImp->Append(id);
      }
    }
    members->DeclareAll(nodeScope);
    return nodeScope;
}

bool ClassDecl::Extends(Type* other) {
    if(!extends)
        return false;

    NamedType* nt = dynamic_cast<NamedType*>(other);
    return (nt && nt->IsEquivalentTo(extends));
}

bool ClassDecl::Implements(Type *other) {
    NamedType* nt = dynamic_cast<NamedType*>(other);
    if (nt == NULL || !nt->IsInterface())
        return false;

    // cout << "nt is interface" << endl;

    //find decl for type
    InterfaceDecl* interf = dynamic_cast<InterfaceDecl*>(this->FindDecl(nt->GetId()));

    // cout << interf << endl;

    return Implements(interf, this);
}

bool ClassDecl::Implements(InterfaceDecl* interf, ClassDecl *actual) {
    List<InterfaceDecl*> *imps = actual->GetImplements();
    for (int i = 0; i < imps->NumElements(); i++){
        // cout << "Checking: " << imps->Nth(i)->GetName() << endl;
        if(strcmp(imps->Nth(i)->GetName(), interf->GetName()) == 0)
            return true;
    }
    if(actual->GetExtends() != NULL){
        //Checamos en el padre
        ClassDecl *padre = dynamic_cast<ClassDecl*>(this->FindDecl(actual->GetExtends()->GetId()));
        // cout << "Nuevo padre: " << padre << endl;
        return Implements(interf, padre);
    }else{
        //No se encontro y regresamos false
        // cout << "Returning false" << endl;
        return false;
    }
}


InterfaceDecl::InterfaceDecl(Identifier *n, List<Decl*> *m) : Decl(n) {
    Assert(n != NULL && m != NULL);
    (members=m)->SetParentAll(this);
}

void InterfaceDecl::Check() {
    PrepareScope();
    members->CheckAll();
}
  
Scope *InterfaceDecl::PrepareScope() {
    if (nodeScope) return nodeScope;
    nodeScope = new Scope();  
    members->DeclareAll(nodeScope);
    return nodeScope;
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

void FnDecl::Check() {
    returnType->Check();
    if (body) {
        nodeScope = new Scope();
        formals->DeclareAll(nodeScope);
        formals->CheckAll();
	body->Check();
    }
}

bool FnDecl::ConflictsWithPrevious(Decl *prev) {
 // special case error for method override
    if (IsMethodDecl() && prev->IsMethodDecl() && parent != prev->GetParent()) { 
        if (!MatchesPrototype(dynamic_cast<FnDecl*>(prev))) {
            ReportError::OverrideMismatch(this);
            return true;
        }
        return false;
    }
    ReportError::DeclConflict(this, prev);
    return true;
}

bool FnDecl::IsMethodDecl() 
  { return dynamic_cast<ClassDecl*>(parent) != NULL || dynamic_cast<InterfaceDecl*>(parent) != NULL; }

bool FnDecl::MatchesPrototype(FnDecl *other) {
    if (!returnType->IsEquivalentTo(other->returnType)) return false;
    if (formals->NumElements() != other->formals->NumElements())
        return false;
    for (int i = 0; i < formals->NumElements(); i++)
        if (!formals->Nth(i)->GetDeclaredType()->IsEquivalentTo(other->formals->Nth(i)->GetDeclaredType()))
            return false;
    return true;
}



