/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:19:25 by tlassere          #+#    #+#             */
/*   Updated: 2024/06/14 19:29:00tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>
#include <cstdlib>

int	main(void)
{
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		Span test(0);
		Span test2(3);

		try
		{
			test.addNumber(69);	
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			test2.addNumber(18);
			test2.addNumber(19);
			test2.addNumber(18);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			sp.addNumber(1212121212);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		Span more(10000);
		int				i;
		int				buffer;
		
		i = 0;
		buffer = 0;
		std::srand(time(NULL));
		while (i < 10000 && buffer < 1000)
		{
			buffer = 0;
			try
			{
				buffer++;
				more.addNumber(static_cast<unsigned int>(std::rand() + i));
				i++;
			}
			catch(const std::exception& )
			{
			}
		}
		std::cout << "short: " << more.shortestSpan() << std::endl;
		std::cout << "bigest: " << more.longestSpan() << std::endl;
	}
	return (0);
}
