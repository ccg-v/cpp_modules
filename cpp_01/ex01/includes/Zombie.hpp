/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 21:27:20 by ccarrace          #+#    #+#             */
/*   Updated: 2024/04/04 23:22:50 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {

	public:
		//	Default constructor;
		Zombie();

		//	Constructor with 'name' argument
		Zombie(const std::string &name);
		
		void announce(void);

	private:
		std::string name;
		
};

Zombie *zombieHorde(int N, std::string name);

#endif