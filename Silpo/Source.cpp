#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>
#include "Order.h"

using namespace std;


vector<Product> catalog = {
    Product(101, "Bread", 50.00, 0),
    Product(102, "Potato", 25.99, 0),
    Product(103, "Butter", 85.00, 0),
    Product(104, "Fish", 300.00, 0),
    Product(105, "Cola 0.5l", 15.50, 0)
};

void printMenu() {
    cout << "\n--- Store Menu ---\n"
		<< "1. Show Catalog\n"
        << "2. Add product\n"
        << "3. Remove product from order\n"
        << "4. Change quantity in order\n"
        << "5. Change order status\n"
        << "6. Show order\n"
        << "7. Save order to file\n"
        << "8. Load order from file\n"
        << "9. Exit\n"
        << "Choose an action: ";
}

int main() {
    Order myOrder;
    int choice = 0;
    string filename = "order_data.txt";

    cout << "=== Welcome to the Silpo Store! ===\n";

    while (true) {
        printMenu();

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input error. Please enter a number from 1 to 8.\n";
            continue;
        }

        switch (choice) {

        case 1: {
            cout << "\n--- Product Catalog ---\n";
            for (const auto& item : catalog) {
                cout << "ID: " << item.id
                    << " | " << item.name
                    << " | Price: " << item.price << " UAH\n";
            }
            cout << "-----------------------\n";
            break;
        }
        case 2: {

            int id, qty;
            cout << "Enter the ID of the product you want to add: ";
            cin >> id;

            auto it = find_if(catalog.begin(), catalog.end(),
                [id](const Product& p) { return p.id == id; });

            if (it != catalog.end()) {
                cout << "Enter quantity: ";
                cin >> qty;

                if (qty > 0) {
                    Product selectedProduct = *it;
                    selectedProduct.quantity = qty;
                    myOrder.addProduct(selectedProduct);
                }
                else {
                    cout << "Quantity must be greater than 0.\n";
                }
            }
            else {
                cout << "Product with ID " << id << " not found in the catalog.\n";
            }
            break;
        }
        case 3: {
            int id;
            cout << "Enter product ID to remove from order: "; cin >> id;
            myOrder.removeProduct(id);
            break;
        }
        case 4: {
            int id, qty;
            cout << "Enter product ID in your order: "; cin >> id;
            cout << "Enter new quantity: "; cin >> qty;
            if (qty > 0) {
                myOrder.changeQuantity(id, qty);
            }
            else {
                cout << "Quantity must be greater than 0.\n";
            }
            break;
        }
        case 5: {
            string status;
            cout << "Enter new status (e.g., Shipped, Paid): ";
            cin >> ws; getline(cin, status);
            myOrder.changeStatus(status);
            break;
        }
        case 6: {
            myOrder.showOrder();
            break;
        }
        case 7: {
            myOrder.saveToFile(filename);
            break;
        }
        case 8: {
            myOrder.loadFromFile(filename);
            break;
        }
        case 9: {
            cout << "Exiting the program. Goodbye!\n";
            return 0;
        }
        default: {
            cout << "Unknown command. Please try again.\n";
            break;
        }
        }
    }
    return 0;
}