#include "commodity.hpp"

commodity::commodity(const string _name, const int _id, const double _price) : name(_name), id(_id), price(_price) {}

int commodity::get_id() const {
    return id;
}

string commodity::get_name() const {
    return name;
}

double commodity::get_price() const {
    return price;
}

double commodity::get_price(const double quantity) const {
    return price*quantity;
}

void commodity::set_price(const double price) {
    this->price = price;
}

double commodity::get_price_with_sales_tax(const double quantity) const {
    return price*(1.0+sales_tax)*quantity;
}