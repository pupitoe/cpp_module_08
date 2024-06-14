/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:06:50 by tlassere          #+#    #+#             */
/*   Updated: 2024/06/14 20:21:49 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <iostream>
#include "MutantStack.hpp"

int	main(void)
{
	std::stack<int> st;
	MutantStack<int> ss;
	
	st.push(19);
	st.push(1648);
	st.pop();
	std::cout << st.top() << std::endl;
	ss.push(5);
	return (0);
}
