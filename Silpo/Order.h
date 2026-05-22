#pragma once

#include "Product.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

class Order {
private:
    std::vector<Product> products;
    std::string status;

public:
    Order() : status("New") {}

    std::vector<Product> getProducts() const {
        return products;
    }

    std::string getStatus() const {
        return status;
    }

    void addProduct(const Product& p) {
        for (auto& item : products) {
            if (item.id == p.id) {
                item.quantity += p.quantity;
                std::cout << "Product quantity updated in order.\n";
                return;
            }
        }
        products.push_back(p);
        std::cout << "Product added to order successfully.\n";
    }

    void removeProduct(int id) {
        auto it = std::remove_if(products.begin(), products.end(),
            [id](const Product& p) { return p.id == id; });

        if (it != products.end()) {
            products.erase(it, products.end());
            std::cout << "Product removed from order.\n";
        }
        else {
            std::cout << "Product with this ID not found in the order.\n";
        }
    }

    void changeQuantity(int id, int newQuantity) {
        for (auto& p : products) {
            if (p.id == id) {
                p.quantity = newQuantity;
                std::cout << "Quantity changed successfully.\n";
                return;
            }
        }
        std::cout << "Product with this ID not found in the order.\n";
    }

    void changeStatus(const std::string& newStatus) {
        status = newStatus;
        std::cout << "Order status changed to: " << status << "\n";
    }

    void showOrder() const {
        std::cout << "\n=== CURRENT ORDER ===\n";
        std::cout << "Status: " << status << "\n";
        if (products.empty()) {
            std::cout << "The order is empty.\n";
            std::cout << "=====================\n";
            return;
        }

        double total = 0.0;
        for (const auto& p : products) {
            p.display();
            total += p.price * p.quantity;
        }
        std::cout << "---------------------\n";
        std::cout << "Total amount: $" << total << "\n";
        std::cout << "=====================\n";
    }

    void saveToFile(const std::string& filename) const {
        std::ofstream file(filename);
        if (file.is_open()) {
            file << status << "\n";
            file << products.size() << "\n";
            for (const auto& p : products) {
                file << p.id << "\n" << p.name << "\n" << p.price << "\n" << p.quantity << "\n";
            }
            file.close();
            std::cout << "Order saved to file '" << filename << "'.\n";
        }
        else {
            std::cout << "Error opening file for writing.\n";
        }
    }

    void loadFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (file.is_open()) {
            products.clear();
            std::getline(file, status);
            size_t size;
            if (file >> size) {
                for (size_t i = 0; i < size; ++i) {
                    Product p;
                    file >> p.id;
                    file.ignore();
                    std::getline(file, p.name);
                    file >> p.price >> p.quantity;
                    file.ignore();
                    products.push_back(p);
                }
            }
            file.close();
            std::cout << "Order loaded from file '" << filename << "'.\n";
        }
        else {
            std::cout << "Error opening file. It might not exist yet.\n";
        }
    }
};