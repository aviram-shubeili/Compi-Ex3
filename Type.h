
#ifndef COMPI_EX3_TYPE_H
#define COMPI_EX3_TYPE_H

#include <utility>
#include <vector>

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
    Type(bool ic, basictype t) : is_const(ic), type(t) {}

};

class FunctionType : public Type {
public:
    std::vector<enum basictype> arguments;
    FunctionType(bool ic, basictype t, std::vector<enum basictype> args ) : Type(ic,t), arguments(std::move(args)) {}
    FunctionType(bool ic, basictype t ) : Type(ic,t), arguments(std::vector<enum basictype>()) {}
};
#endif //COMPI_EX3_TYPE_H
