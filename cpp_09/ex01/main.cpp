/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:51:31 by ccarrace          #+#    #+#             */
/*   Updated: 2024/10/30 19:58:43 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv) {

	try {
		if (argc == 2) {
			RPN rpn;
			int result = rpn.evaluateRPN(argv[1]);
			std::cout << "Result: " << result << std::endl;
			return 0;
		} else {
			throw std::runtime_error("Error: Wrong number of arguments");
		}
	} catch (const std::runtime_error & e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
}