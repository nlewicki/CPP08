/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:44:28 by nlewicki          #+#    #+#             */
/*   Updated: 2025/03/18 13:50:39 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

// Constructors
template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const &src) : std::stack<T>(src)
{
}

// Destructor
template <typename T>
MutantStack<T>::~MutantStack()
{
}

// Operator "=" overload
template <typename T>
MutantStack<T>	&MutantStack<T>::operator=(MutantStack const &src)
{
	if (this != &src)
		std::stack<T>::operator=(src);
	return *this;
}

// Member functions
template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin()
{
	return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end()
{
	return std::stack<T>::c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::begin() const
{
	return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::end() const
{
	return std::stack<T>::c.end();
}

template <typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rbegin()
{
	return std::stack<T>::c.rbegin();
}

template <typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rend()
{
	return std::stack<T>::c.rend();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::rbegin() const
{
	return std::stack<T>::c.rbegin();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::rend() const
{
	return std::stack<T>::c.rend();
}
