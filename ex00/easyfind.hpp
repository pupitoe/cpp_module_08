/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:51:01 by tlassere          #+#    #+#             */
/*   Updated: 2024/06/14 12:51:07 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

template<typename T>
typename T::iterator easyfind(T& container, int const value)
{
	typename T::iterator	it;

	it = container.begin();
	while (it != container.end() && *it != value)
		it++;
	return (it);
}

#endif
