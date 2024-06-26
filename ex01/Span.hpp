/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:07:10 by tlassere          #+#    #+#             */
/*   Updated: 2024/06/24 14:54:22 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iostream>
# include <exception>
# include <algorithm>
# include <iterator>
# define UINT32_MAX 4294967295U;

class	Span
{
	private:
		Span(void);
		Span& operator=(Span const& cpy);

		std::vector<unsigned int>	entity;
		unsigned int const			size;
		unsigned int				current;

		class ExeptionBadAddInList: public std::exception
		{
			public:
				const char	*what(void) const throw();
		};

		class ExeptionInvalidList: public std::exception
		{
			public:
				const char	*what(void) const throw();
		};

	public:
		Span(unsigned int entity);
		Span(Span const& cpy);
		~Span(void);

		void 	addNumber(unsigned int entity);
		void	addRangeNumber(std::vector<unsigned int>::iterator begin,
			std::vector<unsigned int>::iterator end);

		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);
};

#endif
