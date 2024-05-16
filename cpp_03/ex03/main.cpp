/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 22:53:15 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/17 00:54:59 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/* 	This main simulates a battle between a ClapTrap and a FragTrap. Due to the 
	subject requirements the attackDamage of boths fighters must be constant, so
	it will always be 0 for ClapTrap and 20 for FragTrap. Thus, the combat will
	always be the same: ClapTrap will never hurt FragTrap, while FragTrap will 
	kill ClapTrap with one sole attack (ClapTrap's has just 10 hit points).

	To make it more real, I have added a 'dice()' function that randomly assigns
	a value from 0 to 6 to 'attackDamage' in each attack. If 'attackDamage' is 0
	or 6 no damage is caused to enemy, but at least value 6 allows the attacker 
	to repair himself.

	To enable this kind of combat simulation:
	
	1. In ClapTrap's 'attack()' function, replace constant 'attackDamage' 
		value 0 with a call to 'dice()' function ('ClapTrap.cpp' line 109)
	2. In FragTrap's 'attack()' function, replace constant 'attackDamage' 
		value 30 with a call to 'dice()' function ('FragTrap.cpp' line 73)
*/

int checkPointsLevels ( int hitPts1, int hitPts2, int energyPts1, int energyPts2 ) {

        if (hitPts1 <= 0 || hitPts2 <= 0)
            return -1;
        if (energyPts1 <= 0 && energyPts2 <= 0) {
            std::cout << std::endl;
            std::cout << "Fighters ran out of energy! Combat ends in a draw!"
                      << std::endl;
            std::cout << std::endl;
            return -1;
        }
        return 0;
}

int main(void) {

	std::string Player1 = "Clap";
	std::string Player2 = "Scav";
	std::string Player3 = "Frag";
	std::string Player4 = "Diam";
    std::string winner;

	ClapTrap	ClapTrap(Player1);
	ScavTrap	ScavTrap(Player2);
    FragTrap	FragTrap(Player3);
	DiamondTrap	DiamondTrap(Player4);

	std::cout << std::endl;

	std::cout << ClapTrap.getName() << " hit points / energy points / attack damage: "
			  << ClapTrap.getHitPoints() << "\t" << ClapTrap.getEnergyPoints() << "\t" << ClapTrap.getAttackDamage() 
			  << std::endl;


	std::cout << ScavTrap.getName() << " hit points / energy points / attack damage: "
			  << ScavTrap.getHitPoints() << "\t" << ScavTrap.getEnergyPoints() << "\t" << ScavTrap.getAttackDamage() 
			  << std::endl;

	std::cout << FragTrap.getName() << " hit points / energy points / attack damage: "
			  << FragTrap.getHitPoints() << "\t" << FragTrap.getEnergyPoints() << "\t" << FragTrap.getAttackDamage() 
			  << std::endl;

	std::cout << DiamondTrap.getName() << " hit points / energy points / attack damage: "
			  << DiamondTrap.getHitPoints() << "\t" << DiamondTrap.getEnergyPoints() << "\t" << DiamondTrap.getAttackDamage() 
			  << std::endl;

	// // Accessing base class variables from derived class to show that the values have been replaced
	// std::cout << std::endl;
	// std::cout << DiamondTrap.ClapTrap::getName() << " hit points / energy points / attack damage: "
	// 		  << DiamondTrap.ClapTrap::getHitPoints() << "\t" << DiamondTrap.ClapTrap::getEnergyPoints() << "\t" << DiamondTrap.ClapTrap::getAttackDamage() 
	// 		  << std::endl;

	// std::cout << DiamondTrap.ScavTrap::getName() << " hit points / energy points / attack damage: "
	// 		  << DiamondTrap.ScavTrap::getHitPoints() << "\t" << DiamondTrap.ScavTrap::getEnergyPoints() << "\t" << DiamondTrap.ScavTrap::getAttackDamage() 
	// 		  << std::endl;

	// std::cout << DiamondTrap.FragTrap::getName() << " hit points / energy points / attack damage: "
	// 		  << DiamondTrap.FragTrap::getHitPoints() << "\t" << DiamondTrap.FragTrap::getEnergyPoints() << "\t" << DiamondTrap.FragTrap::getAttackDamage() 
	// 		  << std::endl;	

	// std::cout << DiamondTrap.getName() << " hit points / energy points / attack damage: "
	// 		  << DiamondTrap.FragTrap::getHitPoints() << "\t" << DiamondTrap.ScavTrap::getEnergyPoints() << "\t" << DiamondTrap.FragTrap::getAttackDamage() 
	// 		  << std::endl;

// return 0;

    while (FragTrap.getHitPoints() > 0 && DiamondTrap.getHitPoints() > 0) {
        
        // Player1's turn
        if (checkPointsLevels(FragTrap.getHitPoints(), DiamondTrap.getHitPoints(), 
                FragTrap.getEnergyPoints(), DiamondTrap.ScavTrap::getEnergyPoints()) < 0)
            break;

        std::cout << std::endl;
        DiamondTrap.attack(Player3);
        FragTrap.takeDamage(DiamondTrap.getAttackDamage());

        // Player2's turn
        if (checkPointsLevels(FragTrap.getHitPoints(), DiamondTrap.getHitPoints(), 
                FragTrap.getEnergyPoints(), DiamondTrap.ScavTrap::getEnergyPoints()) < 0)
            break;

        std::cout << std::endl;
        FragTrap.attack(Player4);
        DiamondTrap.takeDamage(FragTrap.getAttackDamage());
    }

    // Find winner's name after battle (loop) ends
    if (FragTrap.getHitPoints() <= 0 && DiamondTrap.getHitPoints() > 0)
        winner = DiamondTrap.getName();
    else if (DiamondTrap.getHitPoints() <= 0 && FragTrap.getHitPoints() > 0)
        winner = FragTrap.getName();
    
    // Announce winner's name (only in case battle doesn't end in a draw)
    if (winner != "") {
        std::cout << std::endl;
        std::cout << winner << " won the battle!!!" << std::endl;
        std::cout << std::endl;
    }
	
	// Display the ClapTrap's personal messages
	// ScavTrap.guardGate();
	DiamondTrap.ScavTrap::guardGate();
	// FragTrap.highFivesGuys();
	DiamondTrap.FragTrap::highFivesGuys();
	DiamondTrap.whoAmI();
	
    return 0;
}
