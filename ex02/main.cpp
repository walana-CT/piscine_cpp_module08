/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 08:37:12 by rficht            #+#    #+#             */
/*   Updated: 2024/03/05 11:52:04 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{


	std::cout << "\u001b[38;5;196m   mutant stack compared to a list \u001b[0m" << std::endl << std::endl;

	std::cout << "\u001b[38;5;202m   \u001b[0m" << std::endl << std::endl;	
	
	{
		MutantStack<int> mstack;
		std::list<int> mlist;

		mstack.push(5);
		mstack.push(17);
		mlist.push_back(5);
		mlist.push_back(17);
		std::cout << mlist.front() << std::endl;
		std::cout << mstack.top() << std::endl;
		mlist.pop_front();
		mstack.pop();
		std::cout << mlist.size() << std::endl;
		std::cout << mstack.size() << std::endl;


		
		mstack.push(3);
		mstack.push(5);
		mstack.push(12);
		mstack.push(17);
		mstack.push(26);
		mstack.push(42);
		mstack.push(0);









		
		MutantStack<int>::iterator mit = mstack.begin();
		MutantStack<int>::iterator mite = mstack.end();
		++mit;
		--mit;
		while (mit != mite)
		{
			std::cout << *mit << std::endl;
			++mit;
		}
		MutantStack<int>::const_iterator cmit = mstack.begin();
		MutantStack<int>::const_iterator cmite = mstack.end();
		std::cout << *cmit << std::endl;
		std::cout << *cmite << std::endl;


		


		mlist.push_back(3);
		mlist.push_back(5);
		mlist.push_back(737);
		mlist.push_back(0);
		std::list<int>::iterator lit = mlist.begin();
		std::list<int>::iterator lite = mlist.end();
		++lit;
		--lit;
		while (lit != lite)
		{
			std::cout << *lit << std::endl;
			++lit;
		}
			
	}

	std::cout << std::endl << std::endl;

	{

	}

return (0);

	
}