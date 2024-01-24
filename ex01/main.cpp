/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:23:56 by rficht            #+#    #+#             */
/*   Updated: 2024/01/24 10:10:10 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Span.hpp"

int main()
{
	Span sp = Span(5);
	

	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(42);
	}
	catch(const Span::SpanFullException& e)
	{
		std::cerr << e.what() << '\n';
	}
	



	return 0;
}
