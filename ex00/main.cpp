/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:23:56 by rficht            #+#    #+#             */
/*   Updated: 2024/03/07 16:10:07 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"easyFind.hpp"

int main()
{
	int lst[] = {5, 2 ,6 ,3 ,7};

	std::list<int> cont1(lst, lst + sizeof(lst) / sizeof(int) );
	std::vector<int> cont2(lst, lst + sizeof(lst) / sizeof(int) );

	std::cout << "pos found: " <<  std::distance(cont1.begin(), easyFind(cont1, 15)) << std::endl;
	std::cout << "pos found: " <<  std::distance(cont2.begin(), easyFind(cont2, 2)) << std::endl;

	return 0;
}
