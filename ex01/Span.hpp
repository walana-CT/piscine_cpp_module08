/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:43:41 by rficht            #+#    #+#             */
/*   Updated: 2024/01/24 10:10:33 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP


# include <iostream>
//# include <string>


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
			{	return ("Span is full");	}
	};


	void addNumber(const int& nbr);
};

#endif