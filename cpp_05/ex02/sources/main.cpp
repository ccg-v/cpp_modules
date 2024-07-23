/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:05:54 by ccarrace          #+#    #+#             */
/*   Updated: 2024/07/23 23:47:18 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {

    std::cout << std::endl;
	std::cout << "/* --- ShrubberyCreationForm process-------- /*" << std::endl;
    std::cout << std::endl;
	
	Bureaucrat 				officer1("Bob", 100);
	ShrubberyCreationForm	form1("Garden");

	officer1.signForm(form1);
	form1.execute(officer1);

    std::cout << std::endl;	
    return 0;
}
