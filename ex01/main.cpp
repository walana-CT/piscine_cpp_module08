/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:23:56 by rficht            #+#    #+#             */
/*   Updated: 2024/03/05 17:41:42 by rficht           ###   ########.fr       */
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


	return 0;
}
