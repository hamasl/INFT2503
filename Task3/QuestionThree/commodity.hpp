#ifndef TASK3_COMMODITY_H
#define TASK3_COMMODITY_H



#pragma once
#include <string>


using namespace std;
const double sales_tax = 0.2;
class commodity{
public:
    commodity(const string _name, const int _id, const double _price);
    string get_name() const;
    int get_id() const;
    double get_price() const;
    double get_price(const double quantity) const;
    void set_price(const double price);
    double get_price_with_sales_tax(const double quantity) const;

private:
    //Using const since no setters are requested from the task. Just to guarantee immutability as a best practice
    const string name;
    const int id;
    double price;
};

#endif //TASK3_COMMODITY_H