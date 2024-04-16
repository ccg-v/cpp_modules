/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 23:31:37 by ccarrace          #+#    #+#             */
/*   Updated: 2024/04/16 20:22:50 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl	harl;

	if (argc != 2) {
		std::cout << "Wrong arguments! Please enter one level "
				  "(DEBUG/INFO/WARNING/ERROR)" << std::endl;
		return -1;
	}

	std::string	level = argv[1];

	//	Convert in
	for (size_t i = 0; i < level.length(); i++) {
		level[i] = std::toupper(level[i]);
	};
	
	harl.complain(level);
	// std::cout << level << std::endl;
	
	return 0;
}
