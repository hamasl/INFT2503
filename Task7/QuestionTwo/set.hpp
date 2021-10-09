#include <vector>

#pragma once


class Set{
public:
    Set();
    Set &operator+=(int num);
    Set &operator=(const Set &other);
    std::ostream &operator<<(std::ostream &out);
    friend std::ostream &operator<<(std::ostream &out, const Set &s);
    Set operator|(Set &other);
private:
    std::vector<int> set;
};