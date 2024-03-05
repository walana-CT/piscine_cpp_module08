/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:43:38 by rficht            #+#    #+#             */
/*   Updated: 2024/03/05 09:43:51 by rficht           ###   ########.fr       */
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


void Span::fill (Span::Iterator first, Span::Iterator last, const int& val)
{
	unsigned int pos1 = first.getPos();
	unsigned int pos2 = last.getPos();
	int reversed = (pos1 > pos2);


	if (pos1 == pos2)
		return;
	
	while (first != last) {
		*first = val;
		if (!reversed)
			first++;
		else
			first--;
		
	}
}

Span::Iterator& Span::fill_n (Span::Iterator& it, unsigned int n, const int& val)
{
	
	unsigned int start = it.getPos();
	
	std::cout << "fill_n called start : " << start << " n : " << n << " val : " << val << std::endl;
	
	if (lenght == cur_index)
		return it;
	
	if (start + n > lenght)
		n = lenght - start;

	std::cout << "elem to add : " << n  << std::endl;

	cur_index = start + n;

	std::cout << "new index : " << cur_index  << std::endl;

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
	os << "Span: lenght: " << rhs.getLenght() << " address: " << rhs.getIndex() << std::endl;
	return os;
}