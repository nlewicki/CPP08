/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:44:36 by nlewicki          #+#    #+#             */
/*   Updated: 2025/03/18 14:06:47 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	MutantStack<int> mstack;
	std::list<int> l; // comparing to the list as it is a container that has iterators in STL

	std::cout << "	Functional test" << std::endl;
	mstack.push(5);
	l.push_back(5);
	mstack.push(17);
	l.push_back(17);
	std::cout << "Top element of the mstack: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size of the mstack: " << mstack.size() << std::endl;
	std::cout << "Top element of the list " << l.back() << std::endl;
	l.pop_front();
	std::cout << "Size of the list: " << l.size() << std::endl;
	std::cout << std::endl;
	std::cout << "	Iterator test" << std::endl;
	mstack.push(3);
	l.push_back(3);
	mstack.push(5);
	l.push_back(5);
	mstack.push(737);
	l.push_back(737);
	mstack.push(134);
	l.push_back(134);
	mstack.push(0);
	l.push_back(0);
	MutantStack<int>::iterator it = mstack.begin();
	std::list<int>::iterator itl = l.begin();
	MutantStack<int>::iterator ite = mstack.end();
	std::list<int>::iterator itle = l.end();
	++it;
	--it;
	while (it != ite && itl != itle)
	{
		std::cout << "Mstack element " << *it << std::endl;
		std::cout << "List element " << *itl << std::endl;
		++it;
		++itl;
	}
	std::cout << std::endl;
	std::cout << "	Copy test" << std::endl;
	std::stack<int> s(mstack);
	std::cout << "Top element of the stack: " << s.top() << std::endl;
	int i = 0;
	for(MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << i << ": " << *it << std::endl, i++;
	return (0);
}
