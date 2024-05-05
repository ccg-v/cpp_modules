/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:48:49 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/06 00:41:54 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main( void ) {

	ClapTrap newClapTrap("Attacker");
	ClapTrap otherClapTrap("Defender");

	newClapTrap.attack("Defender");
	otherClapTrap.attack("Attacker");
	
	return (0);
}