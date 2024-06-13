/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:51:39 by tlassere          #+#    #+#             */
/*   Updated: 2024/06/13 14:26:42 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <list>

int	main(void)
{
	std::vector<std::string> lst;
	std::list<int> tt;

	tt.push_front(10);
	tt.push_front(69);
	tt.push_back(100);

	lst.push_back("hello comment tu vas ?");
	lst.push_back("criscosmic est la ?");
	std::vector<std::string>::iterator	it;

	it = lst.begin();
	while (it != lst.end())
	{
		std::cout << *it << std::endl;
		it++;
	}
	std::list<int>::iterator it2;
	it2 = tt.begin();
	while (it2 != tt.end())
	{
		std::cout << *it2 << std::endl;
		it2++;
	}
}
