/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:08:35 by ccarrace          #+#    #+#             */
/*   Updated: 2024/04/04 00:31:27 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {

public:
	//	Constructor
	Zombie(const std::string &name);

	// void setName(const std::string &name); --> setter not needed anymore
	void announce(void);

	// Destructor
	~Zombie();
	
private:

	std::string name;
	
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif