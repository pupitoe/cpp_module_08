/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:17:28 by tlassere          #+#    #+#             */
/*   Updated: 2024/06/16 22:45:52 by tlassere         ###   ########.fr       */
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
		class	iterator: public std::deque<T>::iterator
		{
			public:
				iterator(void);
				iterator(iterator const& it);
				~iterator(void);
				iterator& operator=(iterator const& it);
		};

		MutantStack(void);
		~MutantStack(void);
		MutantStack(MutantStack const& cpy);
		MutantStack& operator=(MutantStack const& cpy);	
		iterator	begin(void) const;
		iterator	end(void) const;
		void	t(void); // this is for test
};

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void) const
{
	return (MutantStack<T>::iterator::iterator(this->c.begin()));
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void) const
{
	return (MutantStack<T>::iterator::iterator(this->c.end()));
}

template<typename T>
MutantStack<T>::iterator::iterator(MutantStack<T>::iterator const& cpy):
	std::deque<T>::iterator(cpy)
{
	*this = cpy;
	return ;
}

template<typename T>
typename MutantStack<T>::iterator&	MutantStack<T>::iterator::operator=(MutantStack<T>::iterator const& cpy)
{
	this->_M_cur = cpy._M_cur;
	this->_M_first = cpy._M_first;
	this->_M_last = cpy._M_last;
	this->_M_node = cpy._M_node;
	return (*this);
}

template<typename T>
MutantStack<T>::iterator::iterator(void):
	std::deque<T>::iterator()
{
	return ;
}

template<typename T>
MutantStack<T>::iterator::~iterator(void)
{
	return ;
}

template<typename T> void MutantStack<T>::t(void)
{
	std::cout << this->c.size() << std::endl;
	if (this->c.empty() == 0)
	{
		std::cout << &this->c.back() << std::endl;
		std::cout << &this->c.back() << std::endl;
	}
	return ;
}

template<typename T> MutantStack<T>::MutantStack(void)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

template<typename T> MutantStack<T>::~MutantStack(void)
{
	std::cout << "Default destructor called" << std::endl;
	return ;
}

template<typename T> MutantStack<T>::MutantStack(MutantStack const& cpy)
{
	std::cout << "Default copy constructor called" << std::endl;
	*this = cpy;
	return ;
}

template<typename T> MutantStack<T>& MutantStack<T>::operator=(MutantStack const& cpy)
{
	std::cout << "Default copy signement operator called" << std::endl;
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

#endif
