/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:23:56 by rficht            #+#    #+#             */
/*   Updated: 2024/03/05 09:32:23 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Span.hpp"

int main()
{
	/*Span sp1 = Span(5);
	

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

	Span test = Span(10);

	std::cout << test.begin() << std::endl;
	test.fill(test.begin(), test.end(), 42);
	
	
	std::cout << test.longestSpan() << std::endl;
	std::cout << test.shortestSpan() << std::endl;*/


	std::cout << "testing iterartors" << std::endl;

	std::cout << "testing fill_n" << std::endl;	

	{
		
		Span sp = Span(5);
		
		Span::Iterator it = sp.begin();

		std::cout << "before : " << sp << std::endl;

		sp.fill_n(it, 5, 42);

		std::cout << "after : " << sp << std::endl;
	
	}


	{
		
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);

		Span::Iterator it = sp.current();

		std::cout << "before : " << sp << std::endl;

		sp.fill_n(it, 5, 42);

		std::cout << "after : " << sp << std::endl;
	
	}


	{
		
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);

		Span::Iterator it = sp.current();

		std::cout << "before : " << sp << std::endl;

		sp.fill_n(it, 2, 6);

		std::cout << "after : " << sp << std::endl;
	
	}




	{	
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(5);
		sp.addNumber(4);
		sp.addNumber(3);
		sp.addNumber(2);
		
		Span::Iterator it = sp.current();

		std::cout << "before : " << sp << std::endl;

		sp.fill_n(it, 2, 6);

		std::cout << "after : " << sp << std::endl;
	}
	

	

	


	return 0;
}
