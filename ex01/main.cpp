/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:32:39 by nlewicki          #+#    #+#             */
/*   Updated: 2025/03/18 13:40:14 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <climits>

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"

void testBasicFunctionality()
{
	std::cout << GREEN << "\n--- Basic Functionality Test ---" << RESET << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

void testExceptions()
{
	std::cout << GREEN << "\n--- Exception Handling Test ---" << RESET << std::endl;
	Span sp1 = Span(3);
	sp1.addNumber(1);
	sp1.addNumber(2);
	sp1.addNumber(3);
	try
	{
		std::cout << "Attempting to add number to full Span..." << std::endl;
		sp1.addNumber(4);
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	Span sp2 = Span(5);
	try
	{
		std::cout << "Attempting to find shortest span in empty Span..." << std::endl;
		sp2.shortestSpan();
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	Span sp3 = Span(5);
	sp3.addNumber(42);
	try
	{
		std::cout << "Attempting to find longest span with only one element..." << std::endl;
		sp3.longestSpan();
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testLargeSpan()
{
	std::cout << GREEN << "\n--- Large Span Test (10,000 numbers) ---" << RESET << std::endl;
	Span largeSpan = Span(10000);
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	std::cout << "Adding 10,000 random numbers..." << std::endl;
	for (int i = 0; i < 10000; ++i)
	{
		largeSpan.addNumber(std::rand());
	}
	std::cout << "Shortest span: " << largeSpan.shortestSpan() << std::endl;
	std::cout << "Longest span: " << largeSpan.longestSpan() << std::endl;
}

void testIteratorRange()
{
	std::cout << GREEN << "\n--- Iterator Range Test ---" << RESET << std::endl;
	std::vector<int> numbers;
	for (int i = 1; i <= 1000; ++i)
	{
		numbers.push_back(i);
	}
	Span iterSpan = Span(1000);
	std::cout << "Adding 1,000 numbers using iterator range..." << std::endl;
	iterSpan.addNumber(numbers.begin(), numbers.end());
	std::cout << "Shortest span: " << iterSpan.shortestSpan() << std::endl;
	std::cout << "Longest span: " << iterSpan.longestSpan() << std::endl;

	Span smallSpan = Span(10);
	try
	{
		std::cout << "Attempting to add too many numbers via iterator..." << std::endl;
		smallSpan.addNumber(numbers.begin(), numbers.end());
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testEdgeCases()
{
	std::cout << GREEN << "\n--- Edge Cases Test ---" << RESET << std::endl;
	Span edgeSpan = Span(5);
	edgeSpan.addNumber(INT_MIN);
	edgeSpan.addNumber(INT_MAX);
	edgeSpan.addNumber(0);
	std::cout << "Span with INT_MIN, INT_MAX, and 0:" << std::endl;
	std::cout << "Shortest span: " << edgeSpan.shortestSpan() << std::endl;
	std::cout << "Longest span: " << edgeSpan.longestSpan() << std::endl;

	Span dupSpan = Span(5);
	dupSpan.addNumber(42);
	dupSpan.addNumber(42);
	dupSpan.addNumber(42);
	std::cout << std::endl;
	std::cout << "Span with duplicate values:" << std::endl;
	std::cout << "Shortest span: " << dupSpan.shortestSpan() << std::endl;
	std::cout << "Longest span: " << dupSpan.longestSpan() << std::endl;
}

int main()
{
	testBasicFunctionality();
	testExceptions();
	testLargeSpan();
	testIteratorRange();
	testEdgeCases();

	return 0;
}
