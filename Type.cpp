#include "Type.h"

// TODO do we need this?
//template<typename Base, typename T>
//inline bool instanceof(const T*) {
//    return std::is_base_of<Base, T>::value;
//}
//
//bool isFunction(const Type& t) {
//    return instanceof<FunctionType>(&t);
//}

bool operator==(const Type& lhs, const Type& rhs) {
    // TODO: do we need to know if its a function or not or do we care only of the type and const
//    if((isFunction(*lhs) and not isFunction(*rhs)) or
//       (not isFunction(*lhs) and isFunction(*rhs))    )
//    {
//        return false;
//    }

    return (lhs.is_const == rhs.is_const) and (lhs.type == rhs.type);

}