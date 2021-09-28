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
    out << "{";
    for(size_t i = 0; i < set.size(); ++i){
        out << set[i];
        if(i < set.size()-1) out << ", ";
    }
    out << "}";
    return out;
}

/*std::ostream &operator<<(std::ostream &out, const Set &s){
    std::ostream o = s << out;
    return o;
}*/

Set Set::operator|(Set &other){
    Set s;
    for(auto num : (*this).set){
        if(std::find(other.set.begin(), other.set.end(), num) != other.set.end()){
            s += num;
        }
    }
    return s;
}

