/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:43:41 by rficht            #+#    #+#             */
/*   Updated: 2024/03/05 15:52:29 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP


# include <iostream>
# include <limits>
# include <vector>
# include <stdlib.h>
# include <algorithm>


class Span
{
private:
	std::vector<int>	_vect;
	unsigned int		_lenght;

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


	
	
};

std::ostream& operator<<(std::ostream& os, const Span& rhs);


#endif
