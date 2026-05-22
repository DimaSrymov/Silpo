#include "pch.h"
#include "CppUnitTest.h"
#include "../Silpo/Order.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(AddProduct_ShouldAddProduct)
        {
            Order order;

            Product p1(101, "Bread", 50.0, 2);

            order.addProduct(p1);

            auto products = order.getProducts();

            Assert::AreEqual((size_t)1, products.size());
            Assert::AreEqual(101, products[0].id);
            Assert::AreEqual(2, products[0].quantity);
        }
        TEST_METHOD(AddSameProduct_ShouldIncreaseQuantity)
        {
            Order order;

            order.addProduct(Product(101, "Bread", 50.0, 2));
            order.addProduct(Product(101, "Bread", 50.0, 3));

            auto products = order.getProducts();

            Assert::AreEqual((size_t)1, products.size());
            Assert::AreEqual(5, products[0].quantity);
        }
        TEST_METHOD(RemoveProduct_ShouldRemoveProduct)
        {
            Order order;

            order.addProduct(Product(101, "Bread", 50.0, 2));
            order.removeProduct(101);

            auto products = order.getProducts();

            Assert::AreEqual((size_t)0, products.size());
        }
        TEST_METHOD(ChangeQuantity_ShouldUpdateQuantity)
        {
            Order order;

            order.addProduct(Product(101, "Bread", 50.0, 2));
            order.changeQuantity(101, 7);

            auto products = order.getProducts();

            Assert::AreEqual(7, products[0].quantity);
        }
	};
}