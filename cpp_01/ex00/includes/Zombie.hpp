/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:08:35 by ccarrace          #+#    #+#             */
/*   Updated: 2024/04/03 00:31:54 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {

public:

	void setName(const std::string &name);
	void announce(void);

	// Destructor
	~Zombie();
	
private:

	std::string name;
	
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif