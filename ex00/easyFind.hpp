/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:24:17 by rficht            #+#    #+#             */
/*   Updated: 2024/01/20 16:37:40 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <vector>
#include <list>
#include <iostream>


/**
 * @param cont generic contenaire (non associative) filled with int
 * @param val the searched value
 * @return postion of the first found elem corres ponding val. return cont.end() if it couldn't be found
 *
*/
template <typename T>
typename T::iterator easyFind(T& cont, const int& val)
{
	typename T::iterator it = std::find(cont.begin(), cont.end(), val);

	return it;
}

#endif