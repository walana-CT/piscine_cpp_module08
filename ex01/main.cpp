/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:23:56 by rficht            #+#    #+#             */
/*   Updated: 2024/03/07 09:45:45 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Span.hpp"

int main()
{
	std::cout << "\u001b[38;5;196m   testing span class \u001b[0m" << std::endl << std::endl;
	
	std::cout << "\u001b[1m test 1:\u001b[0m adding elems to span to add to much to see how it reacts. display span of created stucture." << std::endl;
		
	Span sp1 = Span(5);
	try
	{
		sp1.addNumber(6);
		sp1.addNumber(3);
		sp1.addNumber(17);
		sp1.addNumber(9);
		sp1.addNumber(11);
		sp1.addNumber(42);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "Longest span:" << sp1.longestSpan() << std::endl;
	std::cout << "Shortest span:" << sp1.shortestSpan() << std::endl << std::endl;

	std::cout << "\u001b[1m test 2:\u001b[0m trying to call longestSpan() and shortestSpan() on a too small span." << std::endl;

	Span sp2 = Span(5);

	try
	{	
		sp2.longestSpan();	
	}
	catch(const std::exception& e)
	{	
		std::cerr << e.what() << '\n';	
	}
	try
	{	
		sp2.shortestSpan();	
	}
	catch(const std::exception& e)
	{	
		std::cerr << e.what() << '\n';	
	}

	Span sp3 = Span(5);
	sp3.addNumber(6);

	try
	{	
		sp3.longestSpan();	
	}
	catch(const std::exception& e)
	{	
		std::cerr << e.what() << '\n';	
	}
	try
	{	
		sp3.shortestSpan();	
	}
	catch(const std::exception& e)
	{	
		std::cerr << e.what() << '\n';	
	}

	std::cout << std::endl << "\u001b[1m test 3:\u001b[0m testing a big big span." << std::endl;
	
	Span spBig = Span(30000);
	
	for (size_t i = 0; i < spBig.getLenght(); i++)
	{
		spBig.addNumber(i * 3);
	}

	std::cout << "Longest span:" << spBig.longestSpan() << std::endl;
	std::cout << "Shortest span:" << spBig.shortestSpan() << std::endl;


	std::cout << std::endl << "\u001b[1m test 4:\u001b[0m creating a span using iterators." << std::endl;

	Span sp1Cpy = Span(sp1.begin(), sp1.end());
		
	std::cout << "original's properties: " << sp1 << std::endl;	
	std::cout << "copy's properties: " << sp1Cpy << std::endl;


	
	return 0;
}
