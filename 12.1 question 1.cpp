#include <iostream>
#include <limits>
#include <functional>

void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
int getNumber()
{
	while (true)
	{
		std::cout << "give a integer number: ";
		int number{};
		std::cin >> number;
		if (!std::cin)
		{
			std::cin.clear();
			ignoreLine();
			std::cout << "Error, try agian.\n";
		}
		else
		{
			ignoreLine();
			return number;
		}
	}
}
char getOperation()
{
	while (true)
	{
		std::cout << "Choose operation, -, +, / or *: ";
		char operation{};
		std::cin >> operation;
		switch (operation)
		{
		case '-':
		case '+':
		case '/':
		case '*':
			return operation;
		default:
			std::cout << "Operator not found.\n";
		}
	}
}
int add(int x, int y)
{
	return x + y;
}
int substract(int x, int y)
{
	return x - y;
}
double divide(double x, double y)
{
	return x / y;
}
int multiply(int x, int y)
{
	return x * y;
}
using ArithmeticFunction = std::function<double(double, double)>;
ArithmeticFunction getArithmeticFunction(char operation)
{
	switch (operation)
	{
		case '+': return &add;
		case '-': return &substract;
		case '/': return &divide;
		case '*': return &multiply;
	}
	return nullptr;
}
int main()
{
	double x{ static_cast<double>(getNumber()) };
	char o{ getOperation() };
	double y{ static_cast<double>(getNumber()) };
	std::function fn{ getArithmeticFunction(o) };
	std::cout << '\n';
	if(fn)
		std::cout << x << " " << o << " " << y << " = " << fn(x, y) << '\n';
	
	return 0;
}

