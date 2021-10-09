#include <math.h>


template<typename Type>
bool equal(Type a, Type b){
    return a == b;
}

bool equal(double a, double b){
    //std::cout << "using double version with a: " << a.setprecision(6) <<
    return abs(a-b) < 0.00001
}