/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:44:18 by nlewicki          #+#    #+#             */
/*   Updated: 2025/03/18 13:48:16 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		// Constructors
		MutantStack();
		MutantStack(MutantStack const &src);

		// Destructor
		~MutantStack();

		// Operator "=" overload
		MutantStack	&operator=(MutantStack const &src);

		// Member functions
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator	begin();
		iterator	end();

		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		const_iterator	begin() const;
		const_iterator	end() const;

		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		reverse_iterator	rbegin();
		reverse_iterator	rend();

		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator	rbegin() const;
		const_reverse_iterator	rend() const;
};

#include "MutantStack.tpp"

#endif
