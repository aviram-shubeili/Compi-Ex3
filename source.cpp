#include "source.hpp"
#include <memory>
#include <cassert>
#include <algorithm>

void FormalsListNode::addArgument(int lineno, Symbol arg) {
    for(int i = 0 ; i < args.size() ; i++) {
        if(arg.name == args[i].name) {
            output::errorDef(lineno, arg.name);
            exit(0);
        }
    }
    args.push_back(arg);
//    args.back().offset = (-args.size());
}

FormalsNode::FormalsNode(int num, std::vector<Symbol> args) : Node(num) {

    std::reverse(args.begin(),args.end());
    for(int i = 0 ; i < args.size() ; i++)
    {
        args[i].offset = -(i+1);
    }
    arguments = args;
}

FormalDeclNode::FormalDeclNode(int lineno, bool is_const, basictype type, std::string name) : Node(lineno),
                                                                                              arg(Symbol(name, Type(is_const,type),DONT_CARE)) {}

void ExpListNode::addExp(basictype type) {
    types.push_back(type);
}
