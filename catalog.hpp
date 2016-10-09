
/
// catalog.hpp
// CSUF CPSC 131, Fall 2016, Project 1
//
// Classes that define a catalog of supermarket products.

#pragma once

#include <stdexcept>
#include <string>

using namespace std;

// A product represents one particular kind of product, such as apples
// or cereal.
class Product {
public:
	// Create a product with a given code, name, and price.
	//
	// code is intended to be a UPC code (bar code) or PLU code in a
	// string.
	//
	// name may be any string.
	//
	// price is in units of dollars. It must be positive, or else this
	// function throws std::invalid_argument.
	Product(const std::string& code,
		const std::string& name,
		double price) {
		// TODO: implement this function properly
		throw std::logic_error("not implemented yet");
		// 10/8/16
		if (price < 0)
			throw std::invalid_argument("price cannot be negative");
	}

	~Product() { }

	// Accessors.
	const std::string& getCode() const { return code; }
	const std::string& getName() const { return name; }
	double getPrice() const { return price; }
	friend Catalog;

private:
	std::string code, name;
	double price;
};

// A catalog represents a collection of all of the products available
// at a store.
class Catalog {
public:
	// Create a new catalog.
	//
	// maxProducts is the maximum number of products that can be
	// stored. It must be positive, or else this function throws
	// std::invalid_argument.
	Catalog(int maxProducts) {
		// TODO: implement this function properly
		throw std::logic_error("not implemented yet");
		// 10/8/16
		if (maxProducts < 0)
			throw std::invalid_argument("max cannot be negative");
		maxP = maxProducts;
		ptr = new int[maxP];
	}

	~Catalog() {
		// TODO: implement this function properly
		throw std::logic_error("not implemented yet");
		// 10/8/16
		delete[] ptr;
	}

	// Accessors.
	int getMaxProducts() const {
		// TODO: implement this function properly
		throw std::logic_error("not implemented yet");
		// 10/8/16
		return maxP;
	}

	int getNumProducts() const {
		// TODO: implement this function properly
		throw std::logic_error("not implemented yet");
		// 10/8/16
		return numP;
	}

	// Return true when the catalog cannot fit any more products.
	bool isFull() const {
		// TODO: implement this function properly
		throw std::logic_error("not implemented yet");
		// 10/8/16
		if (numP == maxP)
			return true;
		else return false;
	}

	// Add a new product to the catalog with a given code and name.
	//
	// code, name, and price have the same meaning as in a Product. If
	// price is invalid, throw std::invalid_argument.
	//
	// If this catalog is already full, throw overflow_error.
	//
	// Code must be different from all the product codes already in the
	// database. If it's not, throw std::invalid_argument.
	void addProduct(const std::string& code,
		const std::string& name,
		double price) {
		// TODO: implement this function properly
		// 10/8/16
    numP++;
		if (numP > maxP)
			throw std::overflow_error("reached maximum products");
		throw std::logic_error("not implemented yet");
		for (int i = 0; i < maxP; i++) {
			if (code == ptr[i].getCode())
				throw std::invalid_argument("codes cannot be the same");
		}
		Product newProduct(code, name, price);
	}

	// Find a product by its code.
	//
	// code is a product code.
	//
	// Returns a const reference to the product with the matching code.
	//
	// Throw std::invalid_argument if no product with that code exists
	// in the catalog.
	const Product& findCode(const std::string& code) const {
		// TODO: implement this function properly
		throw std::logic_error("not implemented yet");
		// 10/8/16
		for (int i = 0; i < maxP; i++) {
			if (code == ptr[i].getCode())
				return ptr[i];
			else
				throw std::invalid_argument("no product matches");
		}
	}

private:
	// TODO: add data members
	// 10/8/16
	int maxP; // maximum amount of product
	int numP; // current amount of product
	Product * ptr; 
};

