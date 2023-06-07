#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#include "Vector.h"

struct Item {
	int price;
	int weight;
};

void readFile(const char *filename, int &maxWeight, Vector<Item>& items) {
	std::ifstream fs;
	fs.open(filename);
	fs >> maxWeight;

	while (!fs.eof()) 
	{
		int price, weight;
		fs >> price >> weight;

		Item item = { price, weight };
		items.pushBack(item);
	}
	fs.close();
}

void findMostValuableItems(int maxWeight, int n, const Vector<Item>& items) {
	int table[items.size() + 1][maxWeight + 1];

	for (int i = 0; i <= items.size(); i++) {
		for (int w = 0; w <= maxWeight; w++) {
			if (i == 0 || w == 0)
				table[i][w] = 0;
			else if (items[i - 1].weight <= w)
				table[i][w] = std::max(items[i - 1].price + table[i - 1][w - items[i - 1].weight],
										table[i - 1][w]);
			else 
				table[i][w] = table[i - 1][w];
		}
	}
	int maxPrice = table[items.size()][maxWeight];

	for (int i = items.size(); i > 0; i--) {
		if (table[i - 1][maxWeight] >= maxPrice)
			continue;
		
		maxPrice -= items[i - 1].price;
		maxWeight -= items[i - 1].weight;
		std::cout << items[i - 1].price << " " << items[i - 1].weight << std::endl;
	}
}

int main() {
	int maxWeight;
	Vector<Item> items;

	readFile("test1.txt", maxWeight, items);
	findMostValuableItems(maxWeight, items.size(), items);
	items.removeAll();

	std::cout << "***" << std::endl;

	readFile("test2.txt", maxWeight, items);
	findMostValuableItems(maxWeight, items.size(), items);
	items.removeAll();

	std::cout << "***" << std::endl;

	readFile("test3.txt", maxWeight, items);
	findMostValuableItems(maxWeight, items.size(), items);
	items.removeAll();

	return 0;
}