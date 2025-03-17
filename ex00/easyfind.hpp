/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:58:20 by nlewicki          #+#    #+#             */
/*   Updated: 2025/03/17 12:25:24 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>
# include <exception>

class NotFoundException : public std::exception
{
	public:
		const char *what() const noexcept override  //'noexcept' instead of 'throw()' (modern C++) noexcept: specifies that the function does not throw any exceptions
		{
			return "Value not found";
		}
};

template <typename T>
typename T::iterator	easyfind(T &container, int value)
{
	auto it = std::find(container.begin(), container.end(), value); // auto instead of typename T::iterator (modern C++) auto: deduces the type of the variable from its initializer
	if (it == container.end())
		throw NotFoundException();
	return it;
};

#endif
