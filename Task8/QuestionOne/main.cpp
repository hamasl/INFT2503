#include <math.h>
#include <iomanip>
#include <iostream>

template<typename Type>
bool equal(Type a, Type b){
    std::cout << "calling template version of equal" << std::endl;
    return a == b;
}

bool equal(double a, double b){
    std::cout << "calling double version of equal" << std::endl;
    return abs(a-b) < 0.00001;
}


int main(){
    bool res;
    int a = 3;
    int b = 4;
    std::cout << "Integers:" << std::endl;
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    res = equal(a,b);
    std::cout << "a == b: " << res << std::endl;
    b = a;
    std::cout << "b is now " << b << std::endl;
    res = equal(a,b);
    std::cout << "a == b: " << res << std::endl;

    std::cout << std::endl << std::endl;

    std::cout << "Strings:" << std::endl;
    std::string c = "testing testing";
    std::string d = "testing";
    std::cout << "c is '" << c << "'" << std::endl;
    std::cout << "d is '" << d << "'" << std::endl;
    res = equal(c,d);
    std::cout << "c == d: " << res << std::endl;
    d = c;
    std::cout << "d is now '" << d << "'" << std::endl;
    res = equal(c,d);
    std::cout << "c == d: " << res << std::endl;

    std::cout << std::endl << std::endl;


    std::cout << "Doubles:" << std::endl;
    double e = 1;
    double f = 1.00001;
    std::cout << "e is " << e << std::endl;
    std::cout << "f is " << f << std::endl;
    res = equal(e,f);
    std::cout << "e == f: " << res << std::endl;
    f = 1.00000001;
    std::cout << "f is now " << std::setprecision(9) << f << std::endl;
    res = equal(e,f);
    std::cout << "e == f: " << res << std::endl;
    return 0;
}
