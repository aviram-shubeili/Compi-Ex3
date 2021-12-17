
#ifndef COMPI_EX3_TYPE_H
#define COMPI_EX3_TYPE_H

#include <utility>
#include <vector>
#include <memory>

enum basictype {
    VOID_TYPE,
    INT_TYPE,
    BYTE_TYPE,
    NUM_TYPE,
    STRING_TYPE,
    BOOL_TYPE
};

class Type {
public:
    bool is_const;
    enum basictype type;
    Type(bool is_const, basictype t) : is_const(is_const), type(t) {}

};

class FunctionType : public Type {
public:
    std::vector<enum basictype> arguments;
    FunctionType(bool ic, basictype t, std::vector<enum basictype> args ) : Type(ic,t), arguments(std::move(args)) {}
    FunctionType(bool is_const, basictype t ) : Type(is_const,t), arguments(std::vector<enum basictype>()) {}
};

class Symbol  {
public:
    std::string name;
    std::shared_ptr<Type> type;
    int offset;
    Symbol(std::string n, Type* t, int ofs) : name(std::move(n)), type(t), offset(ofs) {}
};
#endif //COMPI_EX3_TYPE_H
