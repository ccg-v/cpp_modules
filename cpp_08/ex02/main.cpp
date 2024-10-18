/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 22:57:43 by ccarrace          #+#    #+#             */
/*   Updated: 2024/10/18 13:55:53 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
#include <vector>
#include <cstdlib>	// for rand()

void	print_vector(std::vector<int> vec) {
	
	std::vector<int>::iterator vec_it = vec.begin();
    std::vector<int>::iterator vec_ite = vec.end();
	std::cout << "Vector content: { ";
	while (vec_it != vec_ite)
	{
	std::cout << *vec_it << " ";
	++vec_it;
	}
	std::cout << "}" << std::endl;	
}

int	main() {

	MutantStack<int> mstack;

	for (int i = 0; i < 5; i++) {
		int random_num = rand() % 100;
		mstack.push(random_num);
		std::cout << random_num << " added" << std::endl;
	}

	// Printing the stack content with the operator<< assignment overload
	std::cout << "\nStack content: " << mstack << std::endl;

	// Testing std::stack methods
	std::cout << "Top element in stack is: " << mstack.top() << std::endl;
	std::cout << "Size of stack is: " << mstack.size() << std::endl;
	std::cout << "Pushing '42'.." << std::endl;
	mstack.push(42);
	std::cout << "Stack content: " << mstack << std::endl;
	std::cout << "Removing top element with pop()..." << std::endl;
	mstack.pop();
	std::cout << "Stack content: " << mstack << std::endl;
	if (mstack.empty())
		std::cout << "The stack is empty" << std::endl;
	else
		std::cout << "The stack is NOT empty" << std::endl;

	/* --- Copying stack content in a vector -------------------------------- */

	std::cout << "\n/* --- Using stack iterators to copy content in a vector ------------- */\n"
			  << std::endl;

    // // Use the underlying container to directly copy into a vector
    // std::vector<int> vec(mstack.begin(), mstack.end());

	// print_vector(vec);

	std::vector<int> vec(mstack.size());

	MutantStack<int>::iterator stack_it = mstack.begin();
    MutantStack<int>::iterator stack_ite = mstack.end();
	std::vector<int>::iterator vec_it = vec.begin();
 
	while (stack_it != stack_ite)
	{
	std::cout << "Copying " << *stack_it << std::endl;
	*vec_it = *stack_it;
	++stack_it;
	++vec_it;
	}
	print_vector(vec);
	
	// Testing std::vector methods
	std::cout << "Top element in vector is: " << vec.back() << std::endl;
	std::cout << "Size of vector is: " << vec.size() << std::endl;
	std::cout << "Pushing '42'.." << std::endl;
	vec.push_back(42);
	print_vector(vec);
	std::cout << "Removing top element with pop()..." << std::endl;
	vec.pop_back();
	print_vector(vec);
	if (vec.empty())
		std::cout << "The vector is empty" << std::endl;
	else
		std::cout << "The vector is NOT empty" << std::endl;

	return 0;
}