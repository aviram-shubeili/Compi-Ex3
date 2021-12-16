#include "source.hpp"
#include <memory>

using namespace std;

void Initialize() {
    Symbol printFunc = Symbol("print",new FunctionType(false, VOID_TYPE, {STRING_TYPE} ),0);
    Symbol printiFunc = Symbol("printi",new FunctionType(false, VOID_TYPE, {INT_TYPE} ),1);
    offsetStack.push(0);
    SymbolMap globalSymbolMap;
    globalSymbolMap.insert(make_pair(printFunc.name, printFunc));
    globalSymbolMap.insert(make_pair(printiFunc.name, printiFunc));
    symbolMapStack.push(globalSymbolMap);
}

