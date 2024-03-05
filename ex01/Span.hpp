/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:43:41 by rficht            #+#    #+#             */
/*   Updated: 2024/03/05 11:06:16 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP


# include <iostream>
# include <limits>
# include <stdlib.h>


class Span
{
private:
	int*				tab;
	unsigned int		lenght;
	unsigned int		cur_index;

public:
	Span();
	~Span();
	Span(const unsigned int& lenght);
	Span(const Span& rhs);

	Span& operator = (const Span& rhs);
	 
	class SpanFullException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{	return ("span is full");	}
	};

	class SpanTooFewElemException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{	return ("you need at least 2 elements to calculate span");	}
	};
	
	void addNumber(const int& nbr);
	unsigned int shortestSpan();
	unsigned int longestSpan();

	const int * getTab() const;
	const unsigned int& getLenght() const;
	const unsigned int& getIndex() const;


	class Iterator {
		private:
			int* current;
			Span& classRef;

		public:	

			Iterator(int* ptr, Span& classRef);
			Iterator(const Iterator& rhs);


			int* getCurrent() const;
			Span& getClassRef() const;

			Span::Iterator & operator = (Span::Iterator const & rhs);			
			int& operator*() const;
			Iterator& operator++();
			Iterator operator++(int);
			Iterator& operator--();
			Iterator operator--(int);
			bool operator==(const Iterator& other) const;
			bool operator!=(const Iterator& other) const;

			unsigned int getPos();
		};

	void fill (Span::Iterator& first, Span::Iterator& last, const int& val);
	Span::Iterator& fill_n (Span::Iterator& first, unsigned int n, const int& val);
	
	Iterator begin();
	Iterator end();
	Iterator current();
	
};

std::ostream& operator<<(std::ostream& os, const Span::Iterator& rhs);
std::ostream& operator<<(std::ostream& os, const Span& rhs);


#endif
