/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:23:56 by rficht            #+#    #+#             */
/*   Updated: 2024/03/05 11:36:01 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Span.hpp"

int main()
{
	std::cout << "\u001b[38;5;196m   testing span class \u001b[0m" << std::endl << std::endl;
	
	{
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
		catch(const Span::SpanFullException& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		std::cout << sp1.shortestSpan() << std::endl;
		std::cout << sp1.longestSpan() << std::endl << std::endl;
		
		std::cout << "\u001b[1m test 2:\u001b[0m trying to call member functions on an empty span." << std::endl;			
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
 		std::cout << std::endl;
		std::cout << "\u001b[1m test 3:\u001b[0m testing with a big span" << std::endl;	

		Span bigSp = Span(10000);
		
		for (size_t i = 0; i < 10000; i++)
		{
			bigSp.addNumber(i);
		}
		
		std::cout << bigSp.longestSpan() << std::endl;
		std::cout << bigSp.shortestSpan() << std::endl << std::endl;
	}


	std::cout << "\u001b[38;5;196m   testing iterartors \u001b[0m" << std::endl << std::endl;

	std::cout << "\u001b[38;5;202m  testing fill_n \u001b[0m" << std::endl << std::endl;	

	{
		std::cout << "\u001b[1m test 1:\u001b[0m fill a span" << std::endl;

		Span sp = Span(5);
		Span::Iterator it = sp.begin();
		std::cout << "before : " << sp << std::endl;
		sp.fill_n(it, 5, 42);
		std::cout << "after : " << sp << std::endl << std::endl;
	
	}


	{
		
		std::cout << "\u001b[1m test 2:\u001b[0m fill a span with more elem than possible (stop at end)" << std::endl;		
		
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		Span::Iterator it = sp.current();
		std::cout << "before : " << sp << std::endl;
		sp.fill_n(it, 5, 42);
		std::cout << "after : " << sp << std::endl << std::endl;

	}


	{
		std::cout << "\u001b[1m test 3:\u001b[0m adding elems to span" << std::endl;	
		
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		Span::Iterator it = sp.current();
		std::cout << "before : " << sp << std::endl;
		sp.fill_n(it, 2, 6);
		std::cout << "after : " << sp << std::endl << std::endl;
	}

	{	
		std::cout << "\u001b[1m test 4:\u001b[0m trying to add elems at the end" << std::endl;
		
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(5);
		sp.addNumber(4);
		sp.addNumber(3);
		sp.addNumber(2);
		Span::Iterator it = sp.current();
		std::cout << "before : " << sp << std::endl;
		sp.fill_n(it, 2, 6);
		std::cout << "after : " << sp << std::endl << std::endl;
	}
	
		std::cout << "\u001b[38;5;202m  testing fill\u001b[0m" << std::endl << std::endl;
	
	{	
		std::cout << "\u001b[1m test1:\u001b[0m fill an empty span" << std::endl;
		
		Span sp = Span(5);
		Span::Iterator first = sp.begin();
		Span::Iterator last = sp.end();		
		std::cout << "before : " << sp << std::endl;
		sp.fill(first, last, 6);
		std::cout << "after : " << sp << std::endl << std::endl;
	}
	
	{	
		std::cout << "\u001b[1m test 2:\u001b[0m fill an empty span reversed" << std::endl;
		Span sp = Span(5);
		Span::Iterator first = sp.begin();
		Span::Iterator last = sp.end();		
		std::cout << "before : " << sp << std::endl;
		sp.fill(last, first, 6);
		std::cout << "after : " << sp << std::endl << std::endl;
	}

	{	
		std::cout << "\u001b[1m test 3:\u001b[0m fill with 2x same iterrator" << std::endl;
		Span sp = Span(5);
		Span::Iterator first = sp.begin();	
		std::cout << "before : " << sp << std::endl;
		sp.fill(first, first, 6);
		std::cout << "after : " << sp << std::endl << std::endl;
	}	


	return 0;
}
