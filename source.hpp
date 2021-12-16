#include <string>
#include <stdexcept>
#include <stack>
#include <map>
#include <memory>
#include "Type.h"

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

struct Node {
    int lineno;
    Node(int num) : lineno(num) {}
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
class Id : public Node {
public:
    std::string value;
    Id(std::string text, int num) : Node(num), value(text) {}
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

class Symbol  {
public:
    std::string name;
    std::shared_ptr<Type> type;
    int offset;
};

typedef OffsetStack = std::stack<int>;
typedef SymbolMap = std::map<std::string, Symbol>;
typedef SymbolMapStack = std::stack<SymbolMap>;
#define YYSTYPE Node*
