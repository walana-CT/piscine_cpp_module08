/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 08:37:12 by rficht            #+#    #+#             */
/*   Updated: 2024/03/07 16:08:03 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{


	std::cout << "\u001b[38;5;196m   mutant stack compared to a list \u001b[0m" << std::endl << std::endl;

	std::cout << "\u001b[38;5;202m Step 1:\u001b[0m adding 2 elems and displaying front" << std::endl << std::endl;	
	
	MutantStack<int> mstack;
	std::list<int> clist;
	mstack.push(5);
	mstack.push(17);
	clist.push_back(5);
	clist.push_back(17);
	
	std::cout <<  "\u001b[1mMonster stack:\u001b[0m" << std::endl;
	std::cout << mstack.top() << std::endl;
	std::cout <<  "\u001b[1mlist:\u001b[0m" << std::endl;
	std::cout << clist.back() << std::endl;

	std::cout << std::endl <<  "\u001b[38;5;202m Step 2:\u001b[0m poping front elem and display the size" << std::endl << std::endl;
		
	mstack.pop();
	clist.pop_back();
	
	std::cout <<  "\u001b[1mMonster stack:\u001b[0m" << std::endl;
	std::cout << mstack.size() << std::endl;
	std::cout <<  "\u001b[1mlist:\u001b[0m" << std::endl;
	std::cout << clist.size() << std::endl;
	
	std::cout << std::endl <<  "\u001b[38;5;202m Step 3:\u001b[0m iterate trough the elements" << std::endl << std::endl;	

	std::cout <<  "\u001b[1mMonster stack:\u001b[0m" << std::endl;
	{
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
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

		std::cout <<  "\u001b[1mlist:\u001b[0m" << std::endl;
		clist.push_back(3);
		clist.push_back(5);
		clist.push_back(737);
		clist.push_back(0);
		std::list<int>::iterator lit = clist.begin();
		std::list<int>::iterator lite = clist.end();
		++lit;
		--lit;
		while (lit != lite)
		{
			std::cout << *lit << std::endl;
			++lit;
		}

		std::cout << std::endl << "\u001b[38;5;202m Step 4:\u001b[0m iterate backward" << std::endl << std::endl;

		std::cout <<  "\u001b[1mMonster stack:\u001b[0m" << std::endl;
		while (mit-- != mstack.begin())
			std::cout << *mit << std::endl;
		std::cout <<  "\u001b[1mlist:\u001b[0m" << std::endl;
		while (lit-- != clist.begin())
			std::cout << *lit << std::endl;
	}
	std::cout << std::endl << "\u001b[38;5;202m Step 5:\u001b[0m testing = operator" << std::endl << std::endl;
	
	{
		MutantStack<int> monsterCpy = mstack;
		 
		MutantStack<int>::iterator mit = mstack.begin();
		MutantStack<int>::iterator mite = mstack.end();
		++mit;
		--mit;
		while (mit != mite)
		{
			std::cout << *mit << std::endl;
			++mit;
		}
	}
	return (0);	
}

