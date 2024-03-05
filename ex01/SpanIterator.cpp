/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpanIterator.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:18:06 by rficht            #+#    #+#             */
/*   Updated: 2024/03/05 09:43:02 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Span.hpp"

Span::Iterator::Iterator(int* ptr, Span& classRef) : current(ptr), classRef(classRef)
{}

int& Span::Iterator::operator*() const {
	return *current;
}

int* Span::Iterator::getCurrent() const
{	return(this->current);	}

Span& Span::Iterator::getClassRef() const
{	return(this->classRef);	}

Span::Iterator::Iterator(const Iterator& rhs) : current(rhs.current), classRef(rhs.classRef)
{}

Span::Iterator & Span::Iterator::operator = (Span::Iterator const & rhs)
{
	if (this != &rhs)
	{
		this->current = rhs.getCurrent();
		this->classRef = rhs.getClassRef();
	}
	return *this;
}

Span::Iterator& Span::Iterator::operator++() {
	if (&classRef.tab[classRef.cur_index] == current)
		current = &classRef.tab[0];
	else
		++current;
	return *this;
}

Span::Iterator Span::Iterator::operator++(int) {
	Iterator temp = *this;
	if (&classRef.tab[classRef.cur_index] == current)
		current = &classRef.tab[0];
	else
		++current;
	return temp;
}


Span::Iterator& Span::Iterator::operator--() {
	if (current == &classRef.tab[0])
		current = &classRef.tab[classRef.getLenght() - 1];
	else
		--current;
	return *this;
}

Span::Iterator Span::Iterator::operator--(int) {
	if (current == &classRef.tab[0])
		current = &classRef.tab[classRef.getLenght() - 1];
	else
		--current;
	return *this;
}

bool Span::Iterator::operator==(const Iterator& other) const {
	return current == other.current;
}

bool Span::Iterator::operator!=(const Iterator& other) const {
	return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Span::Iterator& rhs)
{
	os << "content: " << *rhs.getCurrent() << " address: " << rhs.getCurrent();
	return os;
}


unsigned int Span::Iterator::getPos()
{
	unsigned int pos = 0;

	std::cout << "get Pos called cur index: " << classRef.cur_index << std::endl;


	while (pos < classRef.lenght && current != &classRef.tab[pos])
	{
		pos++;
		std::cout << pos << std::endl;
	}

	if (pos == classRef.lenght)
	{
		std::cout << "Error: getPos didn't found any result" << std::endl;
		return 0;
	}
	else
	{
		std::cout << "Success: found pos" << pos << std::endl;
		return pos;		
	}
}