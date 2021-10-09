#include <iostream>

template <typename Type1, typename Type2>
class Pair{
public:
    const Type1 first;
    const Type2 second;
    Pair(Type1 _first, Type2 _second): first(_first), second(_second){};
    Pair operator+(const Pair &other){
        return Pair(this->first+other.first, this->second+other.second);
    }
    bool operator>(const Pair &other){
        auto sum1 = this->first + this->second;
        auto sum2 = other.first + other.second;
        return sum1 > sum2;
    }
};


int main() {
    Pair<double, int> p1(3.5, 14);
    Pair<double, int> p2(2.1, 7);
    std::cout << "p1: " << p1.first << ", " << p1.second << std::endl;
    std::cout << "p2: " << p2.first << ", " << p2.second << std::endl;

    if (p1 > p2)
        std::cout << "p1 er størst" << std::endl;
    else
        std::cout << "p2 er størst" << std::endl;

    auto sum = p1 + p2;
    std::cout << "Sum: " << sum.first << ", " << sum.second << std::endl;
}

/* Utskrift:
p1: 3.5, 14
p2: 2.1, 7
p1 er størst
Sum: 5.6, 21
*/
