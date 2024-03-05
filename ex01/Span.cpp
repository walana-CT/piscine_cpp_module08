/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:43:38 by rficht            #+#    #+#             */
/*   Updated: 2024/03/05 11:01:02 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : tab(new int[0]), lenght(0), cur_index(0)
{}

Span::Span(const unsigned int& lenght) : tab(new int[lenght]), lenght(lenght), cur_index(0)
{}

Span::~Span()
{
	delete[] tab;
}

void Span::addNumber(const int& nbr)
{
	if (this->lenght == this->cur_index)
		throw (SpanFullException());
	this->tab[cur_index] = nbr;
	this->cur_index++;
}

unsigned int Span::shortestSpan()
{
	unsigned int distance = std::numeric_limits<int>::max();
	if (cur_index <= 1)
		throw(Span::SpanTooFewElemException());
	
	for (size_t i = 0; i < cur_index - 1; i++)
		for (size_t j = i + 1; j < cur_index; j++)
			if (abs(tab[i] - tab[j]) < distance)
				distance = abs(tab[i] - tab[j]);
				
	return (distance);
}

unsigned int Span::longestSpan()
{
	unsigned int distance = 0;
	if (cur_index <= 1)
		throw(Span::SpanTooFewElemException());
	
	for (size_t i = 0; i < cur_index - 1; i++)
		for (size_t j = i + 1; j < cur_index; j++)
			if (abs(tab[i] - tab[j]) > distance)
				distance = abs(tab[i] - tab[j]);
				
	return (distance);
}

Span::Span(const Span& rhs) : tab(new int[rhs.getLenght()]), lenght(rhs.getLenght()), cur_index(rhs.getIndex())
{
	for (size_t i = 0; i < cur_index; i++)
		this->tab[i] = rhs.getTab()[i];
}

const int* Span::getTab() const
{	return (this->tab);	}


const unsigned int& Span::getLenght() const
{	return (this->lenght);	}

const unsigned int& Span::getIndex() const
{	return (this->cur_index);	}

Span& Span::operator = (const Span& rhs)
{
	if (this != &rhs)
	{
		if (this->tab)
			delete [] tab;
		tab = new int[rhs.getLenght()];
		lenght = rhs.getLenght();
		cur_index = rhs.getIndex();

		for (size_t i = 0; i < cur_index; i++)
			this->tab[i] = rhs.getTab()[i];
	}
	return (*this);
}


void Span::fill (Span::Iterator& first, Span::Iterator& last, const int& val)
{
	unsigned int pos1 = first.getPos();
	unsigned int pos2 = last.getPos();
	unsigned int n = 0;
	int reversed;

	if (pos1 < pos2)
		reversed = 0;
	else
		reversed = 1;

	if (pos1 == pos2)
		return;
	if (first.getPos() == this->lenght)
		first--;

	while (first != last && n++ < 10)
	{
		*first = val;
		if (!reversed)
			++first;
		else
			--first;
	}

	this->cur_index = (pos1 > pos2 ? pos1 : pos2);

	
}

Span::Iterator& Span::fill_n (Span::Iterator& it, unsigned int n, const int& val)
{
	
	unsigned int start = it.getPos();
	
	if (lenght == cur_index)
		return it;
	
	if (start + n > lenght)
		n = lenght - start;

	cur_index = start + n;

	while (n > 0) {
		*it = val;
		++it;
		--n;
	}
	
	return it;
}

Span::Iterator Span::begin() {
	return Span::Iterator(tab, *this);
}

Span::Iterator Span::current() {
	return Span::Iterator(tab + cur_index, *this);
}

Span::Iterator Span::end() {
	return Span::Iterator(tab + lenght, *this);
}


std::ostream& operator<<(std::ostream& os, const Span& rhs)
{
	os << "\tLenght: " << rhs.getLenght() << "\tCur pos: " << rhs.getIndex();
	return os;
}