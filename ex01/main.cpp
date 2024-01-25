/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:23:56 by rficht            #+#    #+#             */
/*   Updated: 2024/01/24 11:14:10 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Span.hpp"

int main()
{
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
	catch(const Span::SpanFullException& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << sp1.shortestSpan() << std::endl;
	std::cout << sp1.longestSpan() << std::endl;

	sp1.addNumber(9);
	sp1.addNumber(9);
	
	Span sp2 = Span(5);

	try
	{	
		sp2.longestSpan();
		sp2.shortestSpan();
	}
	catch(const Span::SpanTooFewElemException& e)
	{	std::cerr << e.what() << '\n';	}
	
	sp2.addNumber(11);
	
	try
	{	
		sp2.longestSpan();
		sp2.shortestSpan();
	}
	catch(const Span::SpanTooFewElemException& e)
	{	std::cerr << e.what() << '\n';	}
	
	sp2.addNumber(98);

	try
	{	
		std::cout << sp2.longestSpan() << std::endl;
		std::cout << sp2.shortestSpan() << std::endl;
	}
	catch(const Span::SpanTooFewElemException& e)
	{	std::cerr << e.what() << '\n';	}

	return 0;
}
