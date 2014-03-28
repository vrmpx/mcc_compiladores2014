/* File: parser.y
 * --------------
 * Yacc input file to generate the parser for the compiler.
 *
 * pp2: your job is to write a parser that will construct the parse tree
 *      and if no parse errors were found, print it.  The parser should 
 *      accept the language as described in specification, and as augmented 
 *      in the pp2 handout.
 */

%{

/* Just like lex, the text within this first region delimited by %{ and %}
 * is assumed to be C/C++ code and will be copied verbatim to the y.tab.c
 * file ahead of the definitions of the yyparse() function. Add other header
 * file inclusions or C++ variable declarations/prototypes that are needed
 * by your code here.
 */
#include "scanner.h" // for yylex
#include "parser.h"
#include "errors.h"

void yyerror(char *msg); // standard error-handling routine

%}

/* The section before the first %% is the Definitions section of the yacc
 * input file. Here is where you declare tokens and types, add precedence
 * and associativity options, and so on.
 */
 
/* yylval 
 * ------
 * Here we define the type of the yylval global variable that is used by
 * the scanner to store attibute information about the token just scanned
 * and thus communicate that information to the parser. 
 *
 * pp2: You will need to add new fields to this union as you add different 
 *      attributes to your non-terminal symbols.
 */
%union {
    int            integerConstant;
    bool           boolConstant;
    char*          stringConstant;
    double         doubleConstant;
    char           identifier[MaxIdentLen+1]; // +1 for terminating null
    Decl*          decl;
    FnDecl*        fnDecl;
    List< Decl* >*      declList;
    Type*               varType;
    VarDecl*            varDecl;
    InterfaceDecl*      interfaceDecl;
    List< Decl* >*      prototypeList;
    List< VarDecl* >*   varDeclList;
    StmtBlock*          stmtBlock;
    Stmt*               stmt;
    List< Stmt* >*      stmtList;
    Expr*               expr;
    List< Expr* >*      exprList;
    Call*               call;
    WhileStmt*          whileStmt;
    ForStmt*            forStmt;
    ReturnStmt*         returnStmt;
    IfStmt*             ifStmt;
    PrintStmt*          printStmt;
    ClassDecl*          classDecl;
    List< NamedType* >* interfaceList;
    NamedType*          namedType;

    Case*               caseStmt;
    List<Case *>*       caseList;
    Default*            defaultStmt;
    SwitchStmt*         switchStmt;

}


/* Tokens
 * ------
 * Here we tell yacc about all the token types that we are using.
 * Yacc will assign unique numbers to these and export the #define
 * in the generated y.tab.h header file.
 */
%token   T_Void T_Bool T_Int T_Double T_String T_Class 
%token   T_LessEqual T_GreaterEqual T_Equal T_NotEqual T_Dims
%token   T_And T_Or T_Null T_Extends T_This T_Interface T_Implements
%token   T_While T_For T_If T_Else T_Return T_Break
%token   T_New T_NewArray T_Print T_ReadInteger T_ReadLine
%token   T_Default T_Switch T_Case

%token   <identifier> T_Identifier
%token   <stringConstant> T_StringConstant 
%token   <integerConstant> T_IntConstant
%token   <doubleConstant> T_DoubleConstant
%token   <boolConstant> T_BoolConstant


/* Non-terminal types
 * ------------------
 * In order for yacc to assign/access the correct field of $$, $1, we
 * must to declare which field is appropriate for the non-terminal.
 * As an example, this first type declaration establishes that the DeclList
 * non-terminal uses the field named "declList" in the yylval union. This
 * means that when we are setting $$ for a reduction for DeclList ore reading
 * $n which corresponds to a DeclList nonterminal we are accessing the field
 * of the union named "declList" which is of type List<Decl*>.
 * pp2: You'll need to add many of these of your own.
 */
%type <declList>      DecP 
%type <decl>          Declaration
%type <varDecl>       VariableDecl
%type <varDecl>       Variable
%type <varDeclList>   VarPC
%type <varType>       Type
%type <fnDecl>        FunctionHead
%type <fnDecl>        FunctionDecl
%type <varDeclList>   Formals
%type <classDecl>     ClassDecl
%type <namedType>     Extends01
%type <interfaceList> Implements01
%type <interfaceList>   IdentifierPC
%type <declList>          FieldA
%type <decl>          Field
%type <interfaceDecl> InterfaceDecl
%type <prototypeList> PrototypeA
%type <decl>          Prototype
%type <stmtBlock>     StmtBlock
%type <varDeclList>   VariableDeclA
%type <stmtList>      StmtA
%type <stmt>          Stmt
%type <ifStmt>        IfStmt
%type <whileStmt>     WhileStmt
%type <forStmt>       ForStmt
%type <expr>          Expr01
%type <returnStmt>    ReturnStmt

%type <caseStmt>    Case
%type <caseList>    CaseP
%type <defaultStmt>    Default01
%type <switchStmt>    SwitchStmt

%type <printStmt>     PrintStmt
%type <exprList>      ExprPC
%type <expr>          Expr
%type <expr>          LValue
%type <call>          Call
%type <exprList>      Actuals
%type <expr>          Constant

%left     '='
%left      T_Or
%left      T_And 
%nonassoc  T_Equal T_NotEqual
%nonassoc  '<' '>' T_LessEqual T_GreaterEqual
%left      '+' '-'
%left      '*' '/' '%'  
%nonassoc  T_UnaryMinus '!' 
%nonassoc  '.' '['
%nonassoc  T_Lower_Than_Else
%nonassoc  T_Else


%%
/* Rules
 * -----
 * All productions and actions should be placed between the start and stop
 * %% markers which delimit the Rules section.
   
 */

Program   :    DecP            { 
                                      @1; 
                                      /* pp2: The @1 is needed to convince 
                                       * yacc to set up yylloc. You can remove 
                                       * it once you have other uses of @n*/
                                      Program *program = new Program($1);
                                      // if no errors, advance to next phase
                                      if(ReportError::NumErrors() == 0) 
                                        program->Print(0);
                                }
          ;

DecP      :    DecP Declaration        { ($$=$1)->Append($2); }
          |    Declaration             { ($$ = new List<Decl*>)->Append($1); }
          ;

Declaration      :    VariableDecl          { $$ = $1; }
                 |    InterfaceDecl         { $$ = $1; }
                 |    ClassDecl             { $$ = $1; }
                 |    FunctionDecl          { $$ = $1; }
                 ;

VariableDecl  :  Variable ';' { $$ = $1; }
              ;

Variable  :    Type T_Identifier  { 
                                    Identifier *varName = new Identifier(@2, $2);
                                    $$ = new VarDecl( varName, $1 );
                                  }
          ;

VarPC     :   VarPC ',' Variable            { ($$ = $1)->Append($3); }
          |   Variable                      { ($$ = new List<VarDecl *>) -> Append($1); }
          ; 

Type      :    T_Int          { $$ = Type::intType; }
          |    T_Double       { $$ = Type::doubleType; }
          |    T_Bool         { $$ = Type::boolType; }
          |    T_String       { $$ = Type::stringType; }
          |    T_Identifier   {
                                Identifier *id = new Identifier(@1, $1);
                                $$ = new NamedType(id);
                              }
          |    Type T_Dims    { $$ = new ArrayType(@1, $1); }
          ;

FunctionHead  : Type T_Identifier '(' Formals ')'               {
                                                                    Identifier *id = new Identifier(@2, $2);
                                                                    $$ = new FnDecl(id, $1, $4);
                                                                }
              | T_Void T_Identifier '(' Formals ')'             {
                                                                    Identifier *id = new Identifier(@2, $2);
                                                                    $$ = new FnDecl(id, Type::voidType, $4);
                                                                }
              ;

FunctionDecl  : FunctionHead StmtBlock     { ($$=$1)->SetFunctionBody($2); }
              ;

Formals   :  VarPC                                        { $$ = $1; }
          |                                               { $$ = new List<VarDecl *>; }
          ;

ClassDecl : T_Class T_Identifier Extends01 Implements01 '{' FieldA '}'      {
                                                                                Identifier *id = new Identifier(@2, $2);
                                                                                $$ = new ClassDecl(id, $3, $4, $6);
                                                                            }

Extends01 : T_Extends T_Identifier                                         { Identifier *id = new Identifier(@2,$2); $$ = new NamedType(id); }
          |                                                                { $$ = NULL; }
          ;

Implements01 : T_Implements IdentifierPC                                   { $$ = $2; }
             |                                                             { $$ = new List<NamedType *>();}
             ;


IdentifierPC : IdentifierPC ',' T_Identifier                               { ($$ = $1)->Append(new NamedType(new Identifier(@3, $3))); }
             | T_Identifier                                                { ($$ = new List<NamedType*>)->Append(new NamedType(new Identifier(@1, $1))); }
             ;

FieldA   : Field FieldA     { ($$ = $2)->InsertAt($1, 0); }
         |                  { $$ = new List< Decl* >(); }
         ;

Field : VariableDecl              { $$ = $1; }
      | FunctionDecl              { $$ = $1; }
      ;

InterfaceDecl : T_Interface T_Identifier '{' PrototypeA '}'    {
                                                                  Identifier *id = new Identifier(@2, $2);
                                                                  $$ = new InterfaceDecl (id, $4);
                                                               }
              ;

PrototypeA : Prototype PrototypeA     { ($$ = $2)->InsertAt($1, 0); }
           |                          { $$ = new List< Decl* >(); }
           ;

Prototype : Type T_Identifier '(' Formals ')' ';'          {
                                                                  Identifier *id = new Identifier(@2, $2);
                                                                  $$ = new FnDecl(id, $1, $4);
                                                           }
          | T_Void T_Identifier '(' Formals ')' ';'        { $$ = new FnDecl(new Identifier(@2,$2), Type::voidType, $4); }
          ;

StmtBlock : '{' VariableDeclA StmtA '}' {  $$ = new StmtBlock($2, $3); }
          ;

VariableDeclA : VariableDeclA VariableDecl { ($$ = $1)->Append($2); }
              |                            { $$ = new List< VarDecl* >(); }
              ;

StmtA  : Stmt StmtA       { ($$ = $2)->InsertAt($1, 0); }
       |                  { $$ = new List< Stmt* >(); }
       ;


Stmt  : Expr01 ';'              { $$ = $1; }
      | StmtBlock               { $$ = $1; }
      | IfStmt                  { $$ = $1; }
      | WhileStmt               { $$ = $1; }
      | ForStmt                 { $$ = $1; }
      | T_Break ';'             { $$ = new BreakStmt(@1); }
      | ReturnStmt              { $$ = $1; }
      | PrintStmt               { $$ = $1; }
      | SwitchStmt              { $$ = $1; }
      ;


IfStmt  : T_If '(' Expr ')' Stmt              { $$ = new IfStmt($3, $5, NULL); }
        | T_If '(' Expr ')' Stmt T_Else Stmt  { $$ = new IfStmt($3, $5, $7); }


WhileStmt : T_While '(' Expr ')' Stmt { $$ = new WhileStmt($3, $5); }

ForStmt   : T_For '(' Expr01 ';' Expr ';' Expr01 ')' Stmt { $$ = new ForStmt($3, $5, $7, $9); }
          ;

Expr01    :   Expr                            { $$ = $1; }
          |                                   { $$ = new EmptyExpr(); }
          ;

ReturnStmt  : T_Return Expr01 ';' { $$ = new ReturnStmt(@1, $2); }
            ;


Case        : T_Case T_IntConstant ':' StmtA                        {
                                                                      IntConstant *i = new IntConstant(@2, $2);
                                                                      $$ = new Case(i, $4);
                                                                    }
            ;

CaseP       :  CaseP Case                     { ($$ = $1)->Append($2); }
            |  Case                           { ($$ = new List<Case*>)->Append($1); }
            ;

Default01   :  T_Default ':' StmtA             { $$ = new Default($3); }
            |                                 { $$ = NULL; }
            ;

SwitchStmt  : T_Switch '(' Expr ')' '{' CaseP Default01 '}'         { $$ = new SwitchStmt($3, $6, $7); }
            ;

PrintStmt   : T_Print '(' ExprPC ')' ';' { $$ = new PrintStmt($3); }
            ;

ExprPC      :  ExprPC ',' Expr                {($$ = $1) -> Append($3);}
            |  Expr                           { ($$ = new List<Expr *>) -> Append($1); }
            ;

Expr  : LValue '=' Expr                   { $$ = new AssignExpr($1, new Operator(@2, "="), $3); }
      | Constant                          { $$ = $1; }
      | LValue                            { $$ = $1; }
      | T_This                            { $$ = new This(@1); }
      | Call                              { $$ = $1; }
      | '(' Expr ')'                      { $$ = $2; }
      | Expr '+' Expr                     { $$ = new ArithmeticExpr($1, new Operator(@2, "+"), $3); }
      | Expr '-' Expr                     { $$ = new ArithmeticExpr($1, new Operator(@2, "-"), $3); }
      | Expr '*' Expr                     { $$ = new ArithmeticExpr($1, new Operator(@2, "*"), $3); }
      | Expr '/' Expr                     { $$ = new ArithmeticExpr($1, new Operator(@2, "/"), $3); }
      | Expr '%' Expr                     { $$ = new ArithmeticExpr($1, new Operator(@2, "%"), $3); }
      | '-' Expr %prec T_UnaryMinus       { $$ = new ArithmeticExpr(new Operator(@1, "-"), $2); }
      | Expr '<' Expr                     { $$ = new RelationalExpr($1, new Operator(@2, "<"), $3); }
      | Expr T_LessEqual Expr             { $$ = new RelationalExpr($1, new Operator(@2, "<="), $3); }
      | Expr '>' Expr                     { $$ = new RelationalExpr($1, new Operator(@2, ">"), $3); }
      | Expr T_GreaterEqual Expr          { $$ = new RelationalExpr($1, new Operator(@2, ">="), $3); }
      | Expr T_Equal Expr                 { $$ = new EqualityExpr($1, new Operator(@2, "=="), $3); }
      | Expr T_NotEqual Expr              { $$ = new EqualityExpr($1, new Operator(@2, "!="), $3); }
      | Expr T_And Expr                   { $$ = new LogicalExpr($1, new Operator(@2, "&&"), $3); }
      | Expr T_Or Expr                    { $$ = new LogicalExpr($1, new Operator(@2, "||"), $3); }
      | '!' Expr                          { $$ = new LogicalExpr(new Operator(@1, "!"), $2); }
      | T_ReadInteger '(' ')'             { $$ = new ReadIntegerExpr(@1); }
      | T_ReadLine '(' ')'                { $$ = new ReadLineExpr(@1); }
      | T_New '(' T_Identifier ')'        { 
                                            NamedType* newt = new NamedType(new Identifier(@3, $3));
                                            $$ = new NewExpr(@1, newt);
                                          }
      | T_NewArray '(' Expr ',' Type ')'  { $$ = new NewArrayExpr(@1, $3, $5);  }
      ;


LValue  : T_Identifier           { $$ = new FieldAccess(NULL, new Identifier(@1, $1)); }
        | Expr '.' T_Identifier  { $$ = new FieldAccess($1, new Identifier(@3, $3)); }
        | Expr '[' Expr ']'      { $$ = new ArrayAccess(@1, $1, $3); }
        ;

Call  : T_Identifier '(' Actuals ')' {
                                    $$ = new Call(@1, NULL, new Identifier(@1, $1), $3);
                                  }
      | Expr '.' T_Identifier '(' Actuals ')' {
                                    $$ = new Call(@1, $1, new Identifier(@3, $3), $5);
                                  }
      ;


Actuals : ExprPC             { $$ = $1; }
        |                    { $$ = new List< Expr* >(); }
        ;

Constant  : T_IntConstant         { $$ = new IntConstant(@1, $1); }
          | T_DoubleConstant      { $$ = new DoubleConstant(@1, $1); }
          | T_BoolConstant        { $$ = new BoolConstant(@1, $1); }
          | T_StringConstant      { $$ = new StringConstant(@1, $1); }
          | T_Null                { $$ = new NullConstant(@1); }
          ;


%%

/* The closing %% above marks the end of the Rules section and the beginning
 * of the User Subroutines section. All text from here to the end of the
 * file is copied verbatim to the end of the generated y.tab.c file.
 * This section is where you put definitions of helper functions.
 */

/* Function: InitParser
 * --------------------
 * This function will be called before any calls to yyparse().  It is designed
 * to give you an opportunity to do anything that must be done to initialize
 * the parser (set global variables, configure starting state, etc.). One
 * thing it already does for you is assign the value of the global variable
 * yydebug that controls whether yacc prints debugging information about
 * parser actions (shift/reduce) and contents of state stack during parser.
 * If set to false, no information is printed. Setting it to true will give
 * you a running trail that might be helpful when debugging your parser.
 * Please be sure the variable is set to false when submitting your final
 * version.
 */
void InitParser()
{
   PrintDebug("parser", "Initializing parser");
   yydebug = false  ;
}
