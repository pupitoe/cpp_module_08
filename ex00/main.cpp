/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:51:39 by tlassere          #+#    #+#             */
/*   Updated: 2024/06/14 13:03:56 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <list>
#include <deque>

int	main(void)
{
	std::vector<int> lst;
	std::list<int> tt;
	std::deque<int> other;

	tt.push_front(10);
	tt.push_front(69);
	tt.push_back(100);

	lst.push_back(150);
	lst.push_back(222222);

	other.push_back(5512);
	other.push_back(50512);
	other.push_back(55102);
	other.push_back(55120);

	if (easyfind(lst, 150) != lst.end())
		std::cout << "150 is find" << std::endl;
	if (easyfind(tt, 100) != tt.end())
		std::cout << "100 is find" << std::endl;
	if (easyfind(lst, 69) == lst.end())
		std::cout << "69 is not find" << std::endl;
	if (easyfind(other, 55102) != other.end())
		std::cout << "55102 is find" << std::endl;
}
