/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:43:41 by rficht            #+#    #+#             */
/*   Updated: 2024/01/30 08:33:49 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP


# include <iostream>
# include <limits>
# include <stdlib.h>


class Span
{
protected:
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
	void addNumbers(const int& nbr);
	unsigned int shortestSpan();
	unsigned int longestSpan();

	const int * getTab() const;
	const unsigned int& getLenght() const;
	const unsigned int& getIndex() const;


	class Iterator {
		private:
			int* current;

		public:
			Iterator(int* ptr) : current(ptr) {}

			int& operator*() const;
			
		Iterator& operator++() {
			++current;
			return *this;
		}

		Iterator operator++(int) {
			Iterator temp = *this;
			++current;
			return temp;
		}

			bool operator==(const Iterator& other) const;
			
			bool operator!=(const Iterator& other) const;
		};

	Iterator begin();
	Iterator end();
	
};

#endif
