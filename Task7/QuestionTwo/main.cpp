#include "set.hpp"
#include <iostream>
int main(){
    Set set1;
    Set set2;

    set1 += 1;
    set1 += 1;
    set1 += 3;
    set1 += 4;
    std::cout << set1 << std::endl;

    set2 += 4;
    set2 += 7;
    std::cout << set2 << std::endl;

    std::cout << (set1|set2 )<< std::endl;

    return 0;
}