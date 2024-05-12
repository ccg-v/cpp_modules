/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 22:53:15 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/12 14:38:45 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* 	This main simulates a battle between a ClapTrap and a ScavTrap. Due to the 
	subject requirements the attackDamage of boths fighters must be constant, so
	it will always be 0 for ClapTrap and 20 for ScavTrap. Thus, the combat will
	always be the same: ClapTrap will never hurt ScavTrap, while ScavTrap will 
	kill ClapTrap with one sole attack (ClapTrap's has just 10 hit points).

	To make it more real, I have added a 'dice()' function that randomly assigns
	a value from 0 to 6 to 'attackDamage' in each attack. If 'attackDamage' is 0
	or 6 no damage is caused to enemy, but at least value 6 allows the attacker 
	to repair himself.

	To enable this kind of combat simulation:
	
	1. In ClapTrap's 'attack()' function, replace constant 'attackDamage' 
		value 0 with a call to 'dice()' function ('ClapTrap.cpp' line 109)
	2. In ScavTrap's 'attack()' function, replace constant 'attackDamage' 
		value 20 with a call to 'dice()' function ('ScavTrap.cpp' line 73)
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
    std::string winner;
    ClapTrap    ClapTrap(Player1);
    ScavTrap    ScavTrap(Player2);

	std::cout << "Clap hit points / energy points / attack damage: "
			  << ClapTrap.getHitPoints() << "\t" << ClapTrap.getEnergyPoints() << "\t" << ClapTrap.getAttackDamage() 
			  << std::endl;
	std::cout << "Scav hit points / energy points / attack damage: "
			  << ScavTrap.getHitPoints() << "\t" << ScavTrap.getEnergyPoints() << "\t" << ScavTrap.getAttackDamage() 
			  << std::endl;

    while (ClapTrap.getHitPoints() > 0 && ScavTrap.getHitPoints() > 0) {
        
        // Player1's turn
        if (checkPointsLevels(ClapTrap.getHitPoints(), ScavTrap.getHitPoints(), 
                ClapTrap.getEnergyPoints(), ScavTrap.getEnergyPoints()) < 0)
            break;

        std::cout << std::endl;
        ClapTrap.attack(Player2);
        ScavTrap.takeDamage(ClapTrap.getAttackDamage());

        // Player2's turn
        if (checkPointsLevels(ClapTrap.getHitPoints(), ScavTrap.getHitPoints(), 
                ClapTrap.getEnergyPoints(), ScavTrap.getEnergyPoints()) < 0)
            break;

        std::cout << std::endl;
        ScavTrap.attack(Player1);
        ClapTrap.takeDamage(ScavTrap.getAttackDamage());
    }

    // Find winner's name after battle (loop) ends
    if (ClapTrap.getHitPoints() <= 0 && ScavTrap.getHitPoints() > 0)
        winner = ScavTrap.getName();
    else if (ScavTrap.getHitPoints() <= 0 && ClapTrap.getHitPoints() > 0)
        winner = ClapTrap.getName();
    
    // Announce winner's name (only in case battle doesn't end in a draw)
    if (winner != "") {
        std::cout << std::endl;
        std::cout << winner << " won the battle!!!" << std::endl;
        std::cout << std::endl;
    }
    
    return 0;
}
