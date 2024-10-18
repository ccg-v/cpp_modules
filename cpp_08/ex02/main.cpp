/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 22:57:43 by ccarrace          #+#    #+#             */
/*   Updated: 2024/10/18 19:33:31 by ccarrace         ###   ########.fr       */
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

	std::cout << "\n/* --- Using stack iterators to copy stack content in a vector"
			  << " ------------- */\n" << std::endl;

	std::vector<int> vec(mstack.size());

	MutantStack<int>::iterator stack_it = mstack.begin();
    MutantStack<int>::iterator stack_ite = mstack.end();
	std::vector<int>::iterator vec_it = vec.begin();

	while (stack_it != stack_ite)
	{
		std::cout << "...Copying " << *stack_it << " from stack to vector..." << std::endl;
		*vec_it = *stack_it;
		++stack_it;
		++vec_it;
	}
	std::cout << std::endl;	
	print_vector(vec);

	// // The stack content can be copied in the vector with just one line of code (1)
    // std::vector<int> vec(mstack.begin(), mstack.end());

	// print_vector(vec);

	/* --- Testing vector to compare results with stack --------------------- */

	std::cout << "\n/* --- Testing vector to compare with stack --------------"
			  << "----------------- */\n" << std::endl;
			  
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

/* --- Subject's main ------------------------------------------------------- */

// int main()
// {
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

// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();
	
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 	std::cout << *it << std::endl;
// 	++it;
// 	}
// 	std::stack<int> s(mstack);
// 	return 0;
// }

/*
 *	(1)	This single line copies all the content from the stack into a vector:
 *	
 *			std::vector<int> vec(mstack.begin(), mstack.end());
 *
 * 		It uses a Range Constructor of std::vector, that allows you to create
 * 		a vector by copying elements from an input range defined by two iterators
 * 		(begin and end). These iterators will access the elements in the underlying
 * 		container of the std::stck as if you were iterating over it directly.
 * 
 * 		However, I discarded this method to copy the stack into a vector and manually 
 * 		iterate and copy element by element instead, because I wanted to display a
 * 		message every time an element is copied.
 * 
 * 			std::cout << "...Copying X from stack to vector..." << std::endl;
 */	