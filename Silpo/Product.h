#pragma once

#include <string>
#include <iostream>

class Product {
public:
    int id;
    std::string name;
    double price;
    int quantity;

    Product(int id = 0, std::string name = "", double price = 0.0, int quantity = 0)
        : id(id), name(name), price(price), quantity(quantity) {
    }

    void display() const {
        std::cout << "ID: " << id
            << " | Name: " << name
            << " | Price: UAH" << price
            << " | Qty: " << quantity << std::endl;
    }
};