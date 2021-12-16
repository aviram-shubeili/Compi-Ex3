
#ifndef COMPI_EX3_ENGINE_H
#define COMPI_EX3_ENGINE_H
#include "source.hpp"

class Engine {
public:
    static SymbolMapStack symbolMapStack;
    static OffsetStack offsetStack;
    static void Initialize();
};

#endif //COMPI_EX3_ENGINE_H
