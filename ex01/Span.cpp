/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:33:34 by nlewicki          #+#    #+#             */
/*   Updated: 2025/07/24 10:53:08 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _n(100)
{
}

Span::Span(unsigned int n) : _n(n)
{
}

Span::Span(Span const &src)
{
	if (this != &src)
	{
		_n = src._n;
		_v = src._v;
	}
}

Span::~Span()
{
}

Span	&Span::operator=(Span const &src)
{
	if (this != &src)
	{
		_n = src._n;
		_v = src._v;
	}
	return *this;
}

void	Span::addNumber(int n)
{
	if (_v.size() >= _n)
		throw FullException();
	_v.push_back(n);
}

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_v.size() + std::distance(begin, end) > _n)
		throw FullException();
	_v.insert(_v.end(), begin, end);
}

int Span::shortestSpan(void)
{
	if (_v.size() <= 1)
		throw NoSpanException();
	std::sort(_v.begin(), _v.end());
	long long min = LLONG_MAX;
	for (std::vector<int>::iterator it = _v.begin(); it != _v.end() - 1; it++)
	{
		// Use absolute value to handle negative differences
		long long diff = std::abs(static_cast<long long>(*(it + 1)) - static_cast<long long>(*it));
		if (diff < min)
			min = diff;
	}
	return static_cast<int>(min);
}

int Span::longestSpan(void)
{
	if (_v.size() <= 1)
		throw NoSpanException();

	// Find min and max manually
	int min_val = *std::min_element(_v.begin(), _v.end());
	int max_val = *std::max_element(_v.begin(), _v.end());

	// Calculate the absolute difference using long long
	long long span = std::abs(static_cast<long long>(max_val) - static_cast<long long>(min_val));

	// Check if the span exceeds INT_MAX
	if (span > static_cast<long long>(INT_MAX))
		return INT_MAX; // Return INT_MAX if the span is too large

	return static_cast<int>(span);
}

const char	*Span::FullException::what() const noexcept
{
	return "Span is full";
}

const char	*Span::NoSpanException::what() const noexcept
{
	return "No span to find";
}
