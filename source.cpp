#include "source.hpp"
#include <memory>
#include <cassert>
using namespace std;

void Initialize() {
    offsetStack.push(0);
    symbolMapStack.push(SymbolMap());
    insertSymbol("print", new FunctionType(false, VOID_TYPE, {STRING_TYPE} ));
    insertSymbol("printi", new FunctionType(false, VOID_TYPE, {INT_TYPE} ));
}

void addTable() {
    symbolMapStack.push(SymbolMap());
    assert(not offsetStack.empty());
    offsetStack.push((offsetStack.top()));
}

void insertSymbol(string name, Type* type ) {
    Symbol s = Symbol(name,type ,offsetStack.top()++);
    symbolMapStack.top().insert(make_pair(s.name, s));
}