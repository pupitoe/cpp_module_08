/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:17:28 by tlassere          #+#    #+#             */
/*   Updated: 2024/06/17 00:25:04 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iterator>
# include <algorithm>
# include <deque>

template<typename T> class MutantStack: public std::stack<T>
{
	public:
		class	iterator: public std::deque<T>::const_iterator
		{
			public:
				iterator(void);
				iterator(iterator const& it);
				iterator(typename std::deque<T>::const_iterator const& cpy);
				~iterator(void);
				iterator& operator=(iterator const& it);
		};

		MutantStack(void);
		~MutantStack(void);
		MutantStack(MutantStack const& cpy);
		MutantStack& operator=(MutantStack const& cpy);	
		iterator	begin(void) const;
		iterator	end(void) const;
};

template<typename T>
MutantStack<T>::iterator::iterator(typename std::deque<T>::const_iterator
	const& cpy): std::deque<T>::const_iterator(cpy)
{
	return ;
}

template<typename T>
MutantStack<T>::iterator::iterator(MutantStack<T>::iterator const& cpy):
	std::deque<T>::const_iterator(cpy)
{
	*this = cpy;
	return ;
}

template<typename T>
typename MutantStack<T>::iterator&
	MutantStack<T>::iterator::operator=(MutantStack<T>::iterator const& cpy)
{
	this->_M_cur = cpy._M_cur;
	this->_M_first = cpy._M_first;
	this->_M_last = cpy._M_last;
	this->_M_node = cpy._M_node;
	return (*this);
}

template<typename T>
MutantStack<T>::iterator::iterator(void):
	std::deque<T>::const_iterator()
{
	return ;
}

template<typename T>
MutantStack<T>::iterator::~iterator(void)
{
	return ;
}



template<typename T> MutantStack<T>::MutantStack(void)
{
	return ;
}

template<typename T> MutantStack<T>::~MutantStack(void)
{
	return ;
}

template<typename T> MutantStack<T>::MutantStack(MutantStack const& cpy)
{
	*this = cpy;
	return ;
}

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(MutantStack const& cpy)
{
	this->c.clear();
	try
	{
		this->c.resize(cpy.size());
		std::copy(cpy.c.begin(), cpy.c.end(), this->c.begin());
	}
	catch(const std::exception&)
	{
	}
	return (*this);
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void) const
{
	return (MutantStack<T>::iterator(this->c.begin()));
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void) const
{
	return (MutantStack<T>::iterator(this->c.end()));
}

#endif
