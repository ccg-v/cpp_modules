/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:13:00 by ccarrace          #+#    #+#             */
/*   Updated: 2024/11/02 14:03:42 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <iostream>
#include <sstream>
#include <vector>
#include <cstdlib>

int main(int argc, char* argv[]) {

    PmergeMe pmergeme;

    for (int i = 1; i < argc; ++i) {
        std::istringstream argStream(argv[i]);
        int number;

        // Split quoted arguments
        while (argStream >> number) {
            pmergeme.getVector().push_back(number);
			pmergeme.getList().push_back(number);
        }
    }

	printContainer(pmergeme.getVector());
	printContainer(pmergeme.getList());

    return 0;
}
