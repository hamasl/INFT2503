#include "set.hpp"
#include <iostream>
int main(){
    Set set1;
    Set set2;

    set1 += 1;
    set1 += 1;
    set1 += 4;
    set1 += 3;
    std::cout << "set1: " << set1 << std::endl;


    set2 += 4;
    set2 += 7;
    std::cout << "set2: " << set2 << std::endl;

    std::cout << "set1|set2: " << (set1|set2) << std::endl;

    Set set3 = set1;

    std::cout << "set3 (equal to set1): " << set3 << std::endl;

    return 0;
}