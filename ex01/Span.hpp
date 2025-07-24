/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlewicki <nlewicki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:33:44 by nlewicki          #+#    #+#             */
/*   Updated: 2025/07/24 10:52:44 by nlewicki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>

class Span
{
	private:
		unsigned int		_n;
		std::vector<int>	_v;

	public:
		// Constructors
		Span();
		Span(unsigned int n);
		Span(Span const &src);

		// Destructor
		~Span();

		// Operator "=" overload
		Span	&operator=(Span const &src);

		// Add number to vector
		void	addNumber(int n);
		void	addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int		shortestSpan(void);
		int		longestSpan(void);

		// Exceptions
		class FullException : public std::exception
		{
			public:
				const char	*what() const noexcept override;
		};

		class NoSpanException : public std::exception
		{
			public:
				const char *what() const noexcept override;
		};
};

#endif
