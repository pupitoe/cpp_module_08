/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:51:01 by tlassere          #+#    #+#             */
/*   Updated: 2024/06/13 14:41:52 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

template<typename T> T<int>::iterator easyfind(T const container,
	int const value)
{
	T<int>::iterator	it;

	it = container.begin();
	while (it != container.end() && *it != value)
	{
		it++;
	}
	return (it);
}

#endif
