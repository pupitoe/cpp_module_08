/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:17:28 by tlassere          #+#    #+#             */
/*   Updated: 2024/06/24 13:54:58 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <algorithm>
# include <deque>

template<typename T> class MutantStack: public std::stack<T>
{
	public:
		MutantStack(void);
		~MutantStack(void);
		MutantStack(MutantStack const& cpy);
		MutantStack& operator=(MutantStack const& cpy);	

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator	begin(void);
		iterator	end(void);
};

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
	try
	{
		this->c = cpy.c;
	}
	catch(const std::exception&)
	{
	}
	return (*this);
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void) 
{
	return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void)
{
	return (this->c.end());
}

#endif
