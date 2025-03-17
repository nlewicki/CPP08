/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:58:43 by nlewicki          #+#    #+#             */
/*   Updated: 2025/03/17 12:26:42 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

void testEasyFind()
{
	std::vector<int> vec = {10, 20, 30, 40, 50};
	std::list<int> lst = {5, 15, 25, 35, 45};
	std::deque<int> deq = {100, 200, 300, 400, 500};

	std::cout << "🔍 Testing easyfind() with different containers:\n\n";

	// Lambda to test easyfind on different containers
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
	testEasyFind();
	return 0;
}

// int main(void)
// {
// 	std::vector<int> vec_int({123, 4, 14, 2, 2414, 1});

// 	try
// 	{
// 		std::cout << *easyfind(vec_int, 2414) << std::endl;
// 		std::cout << *easyfind(vec_int, 1) << std::endl;
// 		std::cout << *easyfind(vec_int, 0) << std::endl;
// 	}
// 	catch (std::exception &e)
// 	{
// 		std::cout << "Not found" << std::endl;
// 	}
// 	return (0);
// }
