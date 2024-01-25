/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:43:38 by rficht            #+#    #+#             */
/*   Updated: 2024/01/25 10:27:33 by rficht           ###   ########.fr       */
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