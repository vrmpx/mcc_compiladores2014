/* File: ast_decl.h
 * ----------------
 * In our parse tree, Decl nodes are used to represent and
 * manage declarations. There are 4 subclasses of the base class,
 * specialized for declarations of variables, functions, classes,
 * and interfaces.
 *
 * pp3: You will need to extend the Decl classes to implement 
 * semantic processing including detection of declaration conflicts 
 * and managing scoping issues.
 */

#ifndef _H_ast_decl
#define _H_ast_decl

#include "ast.h"
#include "list.h"
#include "ast_stmt.h"

class Type;
class NamedType;
class Identifier;
class Stmt;
class Scope;

class Decl : public Node 
{
  protected:
    Identifier *id;
    Scope *scope;
  
  public:
    Decl(Identifier *name);
    friend std::ostream& operator<<(std::ostream& out, Decl *d) { return out << d->id; }

    const char* Name() { return id->Name(); }
    virtual void BuildScope(Scope *parent);
    virtual void Check() = 0;
    virtual bool IsEquivalentTo(Decl* other);

};

class VarDecl : public Decl 
{
  protected:
    Type *type;
    
  public:
    VarDecl(Identifier *name, Type *type);
    bool IsEquivalentTo(Decl* other);
    void Check();
};

class ClassDecl : public Decl 
{
  protected:
    List<Decl*> *members;
    NamedType *extends;
    List<NamedType*> *implements;

  public:
    ClassDecl(Identifier *name, NamedType *extends, 
              List<NamedType*> *implements, List<Decl*> *members);

    void BuildScope(Scope *parent);
    void Check();

  private:
    void CheckExtends();
    void CheckExtendedMembers(NamedType *extType);
    void CheckOverride(Scope *other);
    void CheckImplements();
};

class InterfaceDecl : public Decl 
{
  protected:
    List<Decl*> *members;
    
  public:
    InterfaceDecl(Identifier *name, List<Decl*> *members);

    void BuildScope(Scope *parent);
    void Check();
};

class FnDecl : public Decl 
{
  protected:
    List<VarDecl*> *formals;
    Type *returnType;
    Stmt *body;
    
  public:
    FnDecl(Identifier *name, Type *returnType, List<VarDecl*> *formals);
    void SetFunctionBody(Stmt *b);

    Type* GetReturnType() {return returnType; }
    void BuildScope(Scope *parent);
    void Check();
    bool IsEquivalentTo(Decl* other);
};

#endif
