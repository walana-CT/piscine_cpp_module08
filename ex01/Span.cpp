/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:43:38 by rficht            #+#    #+#             */
/*   Updated: 2024/01/24 10:51:20 by rficht           ###   ########.fr       */
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