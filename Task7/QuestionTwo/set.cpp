#include "set.hpp"
#include <iostream>

Set &Set::operator+=(int num){
    if(std::find(set.begin(), set.end(), num) == set.end()){
        set.push_back(num);
    }
    return *this;
}

Set &Set::operator=(const Set &other){
    this->set = other.set;
    return *this;
}

std::ostream &Set::operator<<(std::ostream &out){
    out << (*this);
    return out;
}

std::ostream &operator<<(std::ostream &out, const Set &s){
    out << "{";
    for(size_t i = 0; i < s.set.size(); ++i){
        out << s.set[i];
        if(i < s.set.size()-1) out << ", ";
    }
    out << "}";
    return out;
}

Set Set::operator|(Set &other){
    Set s = *this;
    for(auto num : other.set){
        s += num;
    }
    return s;
}

