/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 21:13:07 by ccarrace          #+#    #+#             */
/*   Updated: 2024/04/10 21:43:13 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>	// std::ifstream
#include <iostream>	// std::cout

// int	main(void)
// {
// 	// std::ifstream ifs;

// 	// ifs.open ("file.txt", std::ifstream::in);

// 	std::ifstream is("file.txt");

// 	if (is.is_open())
// 		std::cout << "File is open" << std::endl;
// 	else
// 		std::cout << "File is NOT open" << std::endl;

//   char c = is.get();

//   while (is.good()) {
//     std::cout << c;
//     c = is.get();
//   }

//   is.close();
// 	// ifs.close();

// 	return 0;
// }

int	main(void)
{
	std::ifstream ifs;

	ifs.open ("file.txt", std::ifstream::in);

	if (ifs.is_open())
		std::cout << "File is open" << std::endl;
	else
		std::cout << "File is NOT open" << std::endl;

  char c = ifs.get();

  while (ifs.good()) {
    std::cout << c;
    c = ifs.get();
  }

  ifs.close();

	return 0;
}