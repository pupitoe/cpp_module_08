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

const char	*Span::ExeptionBadAddInList::what(void) const throw()
{
	return ("Bad add in list");
}

const char	*Span::ExeptionInvalidList::what(void) const throw()
{
	return ("This do not content the minimum of list size");
}

void	Span::addNumber(unsigned int entity)
{
	std::vector<unsigned int>::iterator	it;

	if (this->current == this->size)
			throw	Span::ExeptionBadAddInList();
	it = std::find(this->entity.begin(), this->entity.end(), entity);
	if (it != this->entity.end())
			throw	Span::ExeptionBadAddInList();
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

static bool	ft_find_occurence(std::vector<unsigned int> const& container)
{
	bool	is_occurence;

	is_occurence = false;
	for (std::vector<unsigned int>::const_iterator it = container.begin();
		it != container.end(); it++)
	{
		for (std::vector<unsigned int>::const_iterator itcmp = it + 1;
			itcmp != container.end(); itcmp++)
		{
			if (*it == *itcmp)
				is_occurence = true;
		}
	}
	return (is_occurence);
}

void	Span::addRangeNumber(std::vector<unsigned int>::iterator begin,
	std::vector<unsigned int>::iterator end)
{
	std::vector<unsigned int>	buffer;

	buffer = this->entity;
	std::copy(begin, end, std::back_inserter(buffer)); // to add in back list
	if (buffer.size() > this->size)
		throw	Span::ExeptionBadAddInList();
	if (ft_find_occurence(buffer))
		throw	Span::ExeptionBadAddInList();
	this->current = buffer.size();
	this->entity = buffer;
}
