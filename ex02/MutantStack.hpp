/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 08:36:46 by rficht            #+#    #+#             */
/*   Updated: 2024/03/07 16:08:56 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <deque>
#include <list>
#include <vector>

template <typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:

	MutantStack(){};
	~MutantStack(){};
	MutantStack(const MutantStack& rhs): std::stack<T, Container>(rhs)
	{}

	MutantStack& operator = (const MutantStack& rhs)
	{
		if (this != &rhs)
			static_cast<std::stack<T, Container>&>(*this) = rhs;
		return(*this);
	}

	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;

	iterator begin() 
	{	return this->c.begin();	}

	iterator end() 
	{	return this->c.end();	}

	const_iterator begin() const 
	{	return this->c.begin();	}

	const_iterator end() const 
	{	return this->c.end();	}

	iterator operator--(){
		return --(this->c);
	}	

    iterator operator--(int) {
        iterator temp = this->c;
        --(this->c);
        return temp;
    }
};

