/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:17:28 by tlassere          #+#    #+#             */
/*   Updated: 2024/06/16 18:52:57 by tlassere         ###   ########.fr       */
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
		class	iterator: public std::iterator
		<
			std::bidirectional_iterator_tag, // the category of iterator
			T, // the type used
			const T *, // the pointer returned
			T // the reference returned
		>
		{
			private:
				typename std::deque<T>::iterator	it;
				//iterator::iterator(void);

	
			public:
				iterator(typename std::deque<T>::iterator it);
		};

		MutantStack(void);
		~MutantStack(void);
		MutantStack(MutantStack const& cpy);
		MutantStack& operator=(MutantStack const& cpy);	
		MutantStack::iterator	begin(void) const;
		//iterator	end(void) const;
		void	t(void); // this is for test
};


template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void) const
{
	return (MutantStack<T>::iterator(this->c.begin()));
}

template<typename T> typename MutantStack<T>::iterator::iterator(typename std::deque<T>::iterator it) 
{
	this->it = iterator;
}


//template<typename T>
//typename MutantStack<T>::iterator MutantStack<T>::end(void) const
//{
//	return (this->c.end());
//}

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
