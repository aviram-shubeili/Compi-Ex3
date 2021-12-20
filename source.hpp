#include <stack>
#include <map>
#include <memory>
#include <utility>
#include "SymbolsRepo.h"
#include "Type.h"

#define DONT_CARE -1

enum reloptype {
    EQUALS,
    NOT_EQUALS,
    SMALLER,
    BIGGER,
    SMALLER_EQUALS,
    BIGGER_EQUALS
};
enum binoptype {
    PLUS,
    MINUS,
    MUL,
    DIV
};

class Node {
public:
    int lineno;
    explicit Node(int num) : lineno(num) {}
};
class TypeNode : public Node {
public:
    basictype type;
    TypeNode(basictype t, int lineno) : Node(lineno), type(t) {}
};
class FormalsNode : public Node {
public:
    std::vector<Symbol> arguments;
    FormalsNode(int num, std::vector<Symbol> args);
    FormalsNode() : Node(DONT_CARE) {}
};
class FormalsListNode : public Node {
public:
    std::vector<Symbol> args;
    explicit FormalsListNode(int num) : Node(num) {}
    FormalsListNode(int num, std::vector<Symbol> args) : Node(num), args(std::move(args)) {}
    void addArgument(int lineno, Symbol arg);
};
class FormalDeclNode : public Node {
public:
    Symbol arg;
    FormalDeclNode(int lineno, bool is_const, basictype type, std::string name);
};
class TypeAnnotationNode : public Node {
public:
    bool is_const;
    explicit TypeAnnotationNode(bool is_const, int lineno = DONT_CARE) : Node(lineno), is_const(is_const) {}
};
class Relop : public Node {
public:
    enum reloptype type;
    Relop(std::string value, int num) : Node(num){
        if(value == "<") type = SMALLER;
        else if(value == ">") type = BIGGER;
        else if(value == ">=") type = BIGGER_EQUALS;
        else if(value == "<=") type = SMALLER_EQUALS;
        else if(value == "==") type = EQUALS;
        else if(value == "!=") type = NOT_EQUALS;
        else throw std::invalid_argument("wrong Relop");
    }
};
class Binop : public Node {
public:
    enum binoptype type;
    Binop(std::string value, int num) : Node(num) {
        if (value == "+") type = PLUS;
        else if (value == "-") type = MINUS;
        else if (value == "*") type = MUL;
        else if (value == "/") type = DIV;
        else throw std::invalid_argument("wrong Binop");
    }
};
class IdNode : public Node {
public:
    std::string name;
    IdNode(std::string text, int num) : Node(num), name(text) {}
};

class Num : public Node {
private:
    std::string value;
public:
    Num(std::string text, int num) : Node(num), value(text) {}
    long long getNumber() {
        return std::stoll(value);
    }
};

class String : public Node {
public:
    std::string value;
    String(std::string text, int num) : Node(num), value(text) {}
};

#define YYSTYPE Node*




//typedef std::stack<int> OffsetStack ;
//typedef std::map<std::string, Symbol> SymbolMap;
//typedef std::stack<SymbolMap> SymbolMapStack;
//extern SymbolMapStack symbolMapStack;
//extern OffsetStack offsetStack;



