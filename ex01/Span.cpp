/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:06:50 by tlassere          #+#    #+#             */
/*   Updated: 2024/06/14 14:39:21tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void): size(0)
{
	return ;
}

Span::Span(Span const& cpy): size(cpy.size)
{
	this->entity = cpy.entity;
	this->current = cpy.current;
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

Span::Span(unsigned int size): size(size)
{
	this->current = 0;
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

	if (this->current == this->size)
			throw	Span::ExeptionIsInList();
	it = this->entity.begin();
	while (it != this->entity.end())
	{
		if (*it == entity)
			throw	Span::ExeptionIsInList();
		it++;
	}
	this->entity.push_back(entity);
	this->current++;
}

unsigned int	Span::shortestSpan(void)
{
	unsigned int	min;
	unsigned int	buffer;
	std::vector<unsigned int>::iterator	it_next;
	std::vector<unsigned int>::iterator	it_main;

	if (this->entity.capacity() < 2)
		throw Span::ExeptionInvalidList();
	min = UINT32_MAX;
	it_next = this->entity.begin();
	it_next++;
	it_main = this->entity.begin();
	while (it_next != this->entity.end())
	{
		buffer = (*it_next > *it_main)? *it_next - *it_main :
			*it_main - *it_next;
		if (buffer < min)
			min = buffer;
		it_main++;
		it_next++;
	}
	return (min);
}

unsigned int	Span::longestSpan(void)
{
	unsigned int	max;
	unsigned int	buffer;
	std::vector<unsigned int>::iterator	it_next; 
	std::vector<unsigned int>::iterator	it_main; 
	
	if (this->entity.capacity() < 2)
		throw Span::ExeptionInvalidList();
	max = 0;
	it_next = this->entity.begin();
	it_next++;
	it_main = this->entity.begin();
	while (it_next != this->entity.end())
	{
		buffer = (*it_next > *it_main)? *it_next - *it_main :
			*it_main - *it_next;
		if (buffer > max)
			max = buffer;
		it_main++;
		it_next++;
	}
	return (max);
}
