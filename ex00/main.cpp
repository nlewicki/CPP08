/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:58:43 by nlewicki          #+#    #+#             */
/*   Updated: 2025/07/24 10:36:28 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

void test()
{
	std::vector<int> vec = {10, 20, 30, 40, 50};
	std::list<int> lst = {5, 15, 25, 35, 45};
	std::deque<int> deq = {100, 200, 300, 400, 500};

	auto runTest = [](auto &container, int value, const std::string &containerName) {
		try
		{
			auto it = easyfind(container, value);
			std::cout << "✅ Found " << value << " in " << containerName << " at position: " << std::distance(container.begin(), it) << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "❌ " << value << " not found in " << containerName << std::endl;
		}
	};

	// Test with vector
	runTest(vec, 30, "vector");
	runTest(vec, 50, "vector");
	runTest(vec, 99, "vector"); // Not found

	// Test with list
	runTest(lst, 15, "list");
	runTest(lst, 45, "list");
	runTest(lst, 100, "list"); // Not found

	// Test with deque
	runTest(deq, 300, "deque");
	runTest(deq, 500, "deque");
	runTest(deq, 999, "deque"); // Not found
}

int main()
{
	test();
	return 0;
}

