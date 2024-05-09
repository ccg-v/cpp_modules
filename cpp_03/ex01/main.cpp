/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 22:53:15 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/09 23:58:57 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// int main( void ) {
// 	ScavTrap a;

// 	return 0;
// }

/* In case you want to see a real battle simulation, uncomment the following main
    and don't forget to uncomment the following in 'ClapTrap.cpp' file:

    1. The dice() function in 'ClapTrap.cpp' file 
    2. The line that prints the result of the dice roll (line 101)
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

	std::string Player1 = "Clappy";
	std::string Player2 = "Scavy";
    std::string winner;
    ClapTrap    ClapTrap(Player1);
    ScavTrap    ScavTrap(Player2);

	std::cout << "Clappy hit points / energy points / attack damage: "
			  << ClapTrap.getHitPoints() << "\t" << ClapTrap.getEnergyPoints() << "\t" << ClapTrap.getAttackDamage() 
			  << std::endl;
	std::cout << "Scavvy hit points / energy points / attack damage: "
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
