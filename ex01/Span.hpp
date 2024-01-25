/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:43:41 by rficht            #+#    #+#             */
/*   Updated: 2024/01/24 10:48:46 by rficht           ###   ########.fr       */
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
	const unsigned int	lenght;
	unsigned int		cur_index;

public:
	Span();
	~Span();
	Span(const unsigned int& lenght);


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
	
};

#endif