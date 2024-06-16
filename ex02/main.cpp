/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:06:50 by tlassere          #+#    #+#             */
/*   Updated: 2024/06/16 18:41:40 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <iostream>
#include "MutantStack.hpp"
#include <deque>

int	main(void)
{
	std::deque<std::string> hello;
	MutantStack<int> ss;
	MutantStack<int> ss2;
	
	ss2.t();
	ss2.push(45);
	ss.push(5);
	ss.push(6);
	std::cout << ss.top() << std::endl;
	ss2 = ss;
	ss2.t();

	std::deque<std::string>::iterator abb = hello.end();
	hello.push_back("hello");
	abb++;
	std::cout << *abb << std::endl;
	abb--;
	//hello.pop_back();
	std::cout << *abb << std::endl;

	MutantStack<int>::iterator bijour;
	
	
	bijour = ss2.begin();
	//while (bijour != ss2.end())
	//{
	//	std::cout << *bijour << std::endl;
	//	bijour++;
	//}
	return (0);
}
