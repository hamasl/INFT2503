#include "Commodity.hpp"

Commodity::Commodity(const string _name, const int _id, const double _price) : name(_name), id(_id), price(_price) {}

int Commodity::get_id() const {
    return id;
}

string Commodity::get_name() const {
    return name;
}

double Commodity::get_price() const {
    return price;
}

double Commodity::get_price(const double quantity) const {
    return price*quantity;
}

void Commodity::set_price(const double price) {
    this->price = price;
}

double Commodity::get_price_with_sales_tax(const double quantity) const {
    return price*(1.0+sales_tax)*quantity;
}