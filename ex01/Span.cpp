/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:43:38 by rficht            #+#    #+#             */
/*   Updated: 2024/03/07 10:15:41 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _vect(), _lenght(0)
{}

Span::Span(const unsigned int& lenght) : _vect(), _lenght(lenght)
{
	this->_vect.reserve(_lenght);
}

Span::Span(std::vector<int>::iterator first, std::vector<int>::iterator last) : _vect(first, last), _lenght(std::distance(first, last))
{}

Span::~Span()
{}

void Span::addNumber(const int& nbr)
{

	if (_vect.size() == _vect.capacity())
		throw(SpanFullException());
	this->_vect.push_back(nbr);
}

unsigned int Span::shortestSpan()
{
	if (_vect.size() < 2)
		throw(SpanTooFewElemException());
		
	std::vector<int> vectCopy(this->_vect);
	unsigned int result = std::numeric_limits<int>::max();
	std::vector<int>::iterator it1 = vectCopy.begin();	
	std::vector<int>::iterator it2 = vectCopy.begin();

	std::sort(vectCopy.begin(), vectCopy.end());
	it2++;
	
	while (it2 != vectCopy.end())
	{
		unsigned int curComp = abs(it1++ - it2++);  
		if (result > curComp)
			result = curComp;		
	}
	return (result);
}

unsigned int Span::longestSpan()
{
	std::vector<int> vectCopy(this->_vect);
	
	if (_vect.size() < 2)
		throw(SpanTooFewElemException());
	std::sort(vectCopy.begin(), vectCopy.end());
	return (abs(vectCopy.front() - vectCopy.back()));
}

Span::Span(const Span& rhs) : _vect(rhs.getVect()), _lenght(rhs.getLenght())
{}

const std::vector<int>& Span::getVect() const
{	return (this->_vect);	}

const unsigned int& Span::getLenght() const
{	return (this->_lenght);	}

Span& Span::operator = (const Span& rhs)
{
	this->_vect = rhs.getVect();
	return (*this);
}

std::vector<int>::iterator Span::begin() {
	return (this->_vect.begin());
}

std::vector<int>::iterator Span::end() {
	return (this->_vect.end());
}


std::ostream& operator<<(std::ostream& os, const Span& rhs)
{
	os << "Size: " << rhs.getVect().size() << " Capacity: " <<  rhs.getVect().capacity();
	return os;
}