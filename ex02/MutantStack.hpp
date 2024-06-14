/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:17:28 by tlassere          #+#    #+#             */
/*   Updated: 2024/06/14 20:27:50 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template<typename T> class MutantStack: public std::stack<T>
{
};


#endif
