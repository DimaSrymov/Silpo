# Silpo
# 🛒 Store Order Management System

Simple C++ console application for managing store orders.

The project allows users to:
- view product catalog
- add products to an order
- remove products
- change quantity
- change order status
- save/load orders from file

---

# 📁 Project Structure

```text
StoreApp/
│
├── Product.h        # Product class
├── Order.h          # Order class
├── Source.cpp       # Main application
│
└── StoreAppTests/   # Unit tests
```

---

# 🚀 Features

## Product Management
- Add products to order
- Remove products from order
- Update quantity
- Prevent duplicate products

## Order Management
- Change order status
- Display current order
- Calculate total price

## File Support
- Save order to file
- Load order from file

## Testing
- Native Unit Tests included
- Tested order logic and file operations

---

#  Unit Tests

The project includes tests for:

- Adding products
- Removing products
- Updating quantity
- Changing status
- Saving/loading files
- Duplicate product handling

Example:

```cpp
TEST_METHOD(AddProduct_ShouldAddProduct)
{
    Order order;

    order.addProduct(Product(101, "Bread", 50.0, 2));

    auto products = order.getProducts();

    Assert::AreEqual((size_t)1, products.size());
}
```

---

#  How to Run

## Requirements

- Visual Studio 2022
- Desktop development with C++

## Build

1. Open solution in Visual Studio
2. Build Solution (`Ctrl + Shift + B`)
3. Run project (`Ctrl + F5`)

---

#  Run Tests

Open:

```text
Test → Run All Tests
```

or use **Test Explorer**.

---

#  Example Menu

```text
1. Show Catalog
2. Add product
3. Remove product
4. Change quantity
5. Change order status
6. Show order
7. Save order to file
8. Load order from file
9. Exit
```

---

Created as a C++ learning project using OOP and Unit Testing.
