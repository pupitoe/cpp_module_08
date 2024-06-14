/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:06:50 by tlassere          #+#    #+#             */
/*   Updated: 2024/06/14 14:20:47 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void)
{
	return ;
}

Span::Span(Span const& cpy)
{
	this->entity = cpy.entity;
	return ;
}

Span&	Span::operator=(Span const&)
{
	return (*this);
}

Span::~Span(void)
{
	return ;
}

Span::Span(unsigned int entity)
{
	this->entity.push_back(entity);
}

const char	*Span::ExeptionIsInList::what(void) const throw()
{
	return ("This element is in the list");
}

const char	*Span::ExeptionInvalidList::what(void) const throw()
{
	return ("This do not content the minimum of list size");
}

void	Span::addNumber(unsigned int entity)
{
	std::vector<unsigned int>::iterator	it;

	it = this->entity.begin();
	while (it != this->entity.end())
	{
		if (*it == entity)
			throw	Span::ExeptionIsInList();
		it++;
	}
	this->entity.push_back(entity);
}

unsigned int	Span::shortestSpan(void)
{
	unsigned int	min;
	
	if (this->entity.capacity() < 2)
		throw Span::ExeptionInvalidList();
	min = UINT32_MAX;
	for (std::vector<unsigned int>::iterator it_main = this->entity.begin();
		it_main != this->entity.end(); it_main++)
	{
		for (std::vector<unsigned int>::iterator it_search =
			this->entity.begin(); it_search != this->entity.end(); it_search++)
		{
			if (*it_search < *it_main && *it_main - *it_search < min)
				min = *it_main - *it_search;
		}
	}
	return (min);
}
