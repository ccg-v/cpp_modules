/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 22:57:43 by ccarrace          #+#    #+#             */
/*   Updated: 2024/10/14 00:16:35 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
#include <vector>
#include <cstdlib>	// for rand()

// int	main(void) {
// 	MutantStack<int> mstack;

// 	mstack.push(5);
// 	mstack.push(17);

// 	std::cout << mstack.top() << std::endl;

// 	mstack.pop();
	
// 	std::cout << mstack.size() << std::endl;

// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	//[...]
// 	mstack.push(0);

//     MutantStack<int>::iterator it = mstack.begin();
//     MutantStack<int>::iterator ite = mstack.end();

// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 	std::cout << *it << std::endl;
// 	++it;
// 	}
// 	std::stack<int> s(mstack);

// 	std::cout << "\nRunning a std::list to compare results...\n" << std::endl;

// 	std::list<int> lst;

// 	lst.push_back(5);
// 	lst.push_back(17);

// 	std::cout << lst.back() << std::endl;

// 	lst.pop_back();
	
// 	std::cout << lst.size() << std::endl;

// 	lst.push_back(3);
// 	lst.push_back(5);
// 	lst.push_back(737);
// 	//[...]
// 	lst.push_back(0);

//     std::list<int>::iterator lst_it = lst.begin();
//     std::list<int>::iterator lst_ite = lst.end();

// 	++lst_it;
// 	--lst_it;
// 	while (lst_it != lst_ite)
// 	{
// 	std::cout << *lst_it << std::endl;
// 	++lst_it;
// 	}

// 	return 0;
// }

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

	std::cout << "\n/* --- Copying stack content in a vector... ------------- */\n"
			  << std::endl;

    // Use the underlying container to directly copy into a vector
    std::vector<int> vec(mstack.begin(), mstack.end());
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
}