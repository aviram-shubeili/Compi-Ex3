
#ifndef COMPI_EX3_TYPE_H
#define COMPI_EX3_TYPE_H

enum basictype {
    VOID,
    INT,
    BYTE,
    NUM,
    STRING,
    BOOL
};

class Type {
public:
    bool is_const;
    enum basictype type;
    Type(bool ic, basictype t) : is_const(ic), type(t) {}

};

class FunctionType : Type {
public:
    std::vector<enum basictype> arguments;
    FunctionType(bool ic, basictype t, std::vector<enum basictype> args) : Type(ic,t), arguments(args) {}
};
#endif //COMPI_EX3_TYPE_H
