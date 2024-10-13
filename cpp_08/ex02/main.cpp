/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 22:57:43 by ccarrace          #+#    #+#             */
/*   Updated: 2024/10/13 14:16:21 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int	main(void) {
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "stack top is " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

    // MutantStack<int>::iterator it = mstack.begin();
    // MutantStack<int>::iterator ite = mstack.end();

	// ++it;
	// --it;
	// while (it != ite)
	// {
	// std::cout << *it << std::endl;
	// ++it;
	// }
	// std::stack<int> s(mstack);

	std::cout << mstack << std::endl;	
	
	return 0;
}