/* File: ast_stmt.h
 * ----------------
 * The Stmt class and its subclasses are used to represent
 * statements in the parse tree.  For each statment in the
 * language (for, if, return, etc.) there is a corresponding
 * node class for that construct. 
 *
 * pp3: You will need to extend the Stmt classes to implement
 * semantic analysis for rules pertaining to statements.
 */


#ifndef _H_ast_stmt
#define _H_ast_stmt

#include "list.h"
#include "ast.h"
#include "errors.h"
#include "hashtable.h"

class Decl;
class VarDecl;
class ClassDecl;
class FnDecl;
class Expr;


class Scope 
{
  protected:
    Scope *parent;
    Hashtable<Decl*> *table;
    ClassDecl *classDecl;
    FnDecl *fnDecl;

  public:
    Scope() : table(new Hashtable<Decl*>), parent(NULL), classDecl(NULL), fnDecl(NULL) {}
    
    Scope* GetParent() { return parent; }
    void SetParent(Scope *p) { parent = p; }

    ClassDecl* GetClassDecl() { return classDecl; }
    void SetClassDecl(ClassDecl* c){ classDecl = c; }

    FnDecl* GetFunctionDecl() { return fnDecl; }
    void SetFunctionDecl(FnDecl *f) { fnDecl = f; }


    Hashtable<Decl*>* GetTable() { return table; }
    void AddDecl(Decl* d);

};


class Program : public Node
{

  public:
     static Scope* globalScope;
     
  protected:
     List<Decl*> *decls;
     
  public:
     Program(List<Decl*> *declList);
     void Check();
     void BuildScope();
};

class Stmt : public Node
{
  protected:
    Scope *scope; 

  public:
     Stmt() : Node(), scope(new Scope)  {}
     Stmt(yyltype loc) : Node(loc), scope(new Scope)  {}
     virtual void BuildScope(Scope *parent);
};

class StmtBlock : public Stmt 
{
  protected:
    List<VarDecl*> *decls;
    List<Stmt*> *stmts;
    
  public:
    StmtBlock(List<VarDecl*> *variableDeclarations, List<Stmt*> *statements);
    void BuildScope(Scope *parent);
};

  
class ConditionalStmt : public Stmt
{
  protected:
    Expr *test;
    Stmt *body;
  
  public:
    ConditionalStmt(Expr *testExpr, Stmt *body);
    virtual void BuildScope(Scope *parent);
};

class LoopStmt : public ConditionalStmt 
{
  public:
    LoopStmt(Expr *testExpr, Stmt *body)
            : ConditionalStmt(testExpr, body) {}
};

class ForStmt : public LoopStmt 
{
  protected:
    Expr *init, *step;
  
  public:
    ForStmt(Expr *init, Expr *test, Expr *step, Stmt *body);
};

class WhileStmt : public LoopStmt 
{
  public:
    WhileStmt(Expr *test, Stmt *body) : LoopStmt(test, body) {}
};

class IfStmt : public ConditionalStmt 
{
  protected:
    Stmt *elseBody;
  
  public:
    IfStmt(Expr *test, Stmt *thenBody, Stmt *elseBody);
    void BuildScope(Scope *parent); 
};

class BreakStmt : public Stmt 
{
  public:
    BreakStmt(yyltype loc) : Stmt(loc) {}
};

class ReturnStmt : public Stmt  
{
  protected:
    Expr *expr;
  
  public:
    ReturnStmt(yyltype loc, Expr *expr);
    void BuildScope(Scope *parent);
};

class PrintStmt : public Stmt
{
  protected:
    List<Expr*> *args;
    
  public:
    PrintStmt(List<Expr*> *arguments);
    void BuildScope(Scope *parent);
};


#endif
