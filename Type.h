
#ifndef COMPI_EX3_TYPE_H
#define COMPI_EX3_TYPE_H

#include <utility>
#include <vector>
#include <memory>

enum basictype {
    VOID_TYPE,
    INT_TYPE,
    BYTE_TYPE,
    STRING_TYPE,
    BOOL_TYPE
};

class Type {
public:
    bool is_const;
    bool is_function;
    enum basictype type;
    std::vector<Type> arguments;
    std::string toString();
    explicit Type(basictype t) : is_const(false), is_function(false), type(t) {}
    Type(bool is_const, basictype t) : is_const(is_const), is_function(false), type(t) {}
    Type(basictype t, std::vector<Type> args ) : is_const(false), is_function(true), type(t), arguments(std::move(args)) {}
    friend bool operator==(const Type& lhs, const Type& rhs);

};

class Symbol  {
public:
    std::string name;
    Type type;
    int offset;
    Symbol(std::string n, Type t, int ofs) : name(std::move(n)), type(std::move(t)), offset(ofs) {}
};
#endif //COMPI_EX3_TYPE_H


