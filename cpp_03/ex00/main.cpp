/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:48:49 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/12 14:39:41 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*	This main simulates a battle between two ClapTraps. Due to the subject 
	requirements, the attackDamage of both ClapTraps is constant and zero,
	which means their attacks cause no damage to the enemy. The combat goes 
	on until they both run out of energy points, ending in a draw.

	To make it more real, I have added a 'dice()' function that randomly
	assigns a value from 0 to 6 to 'attackDamage' in each attack. If 
	'attackDamage' is 0 or 6 no damage is caused to enemy, but at least
	value 6 allows the attacker to repair himself.  
	
	To enable this kind of combat simulation, in 'attack()' function replace 
	the mandatory constant value of 'attackDamage' (0) with a call to 'dice()'
	(line 103 of 'ClapTrap.cpp' file)

	In this case, a draw can only happen if both fighters run out of energy 
	points, which is not easy because one of them will probably lose all his 
	hit points earlier. To force the situation, replace the default energy 
	points (10) in the overload constructor with a lower value (e.g. 3).
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

	std::string Player1 = "Attacker";
	std::string Player2 = "Defender";
    std::string winner;
    ClapTrap    ClapTrap1(Player1);
    ClapTrap    ClapTrap2(Player2);


    while (ClapTrap1.getHitPoints() > 0 && ClapTrap2.getHitPoints() > 0) {
        
        // Player1's turn
        if (checkPointsLevels(ClapTrap1.getHitPoints(), ClapTrap2.getHitPoints(), 
                ClapTrap1.getEnergyPoints(), ClapTrap2.getEnergyPoints()) < 0)
            break;

        std::cout << std::endl;
        ClapTrap1.attack(Player2);
        ClapTrap2.takeDamage(ClapTrap1.getAttackDamage());

        // Player2's turn
        if (checkPointsLevels(ClapTrap1.getHitPoints(), ClapTrap2.getHitPoints(), 
                ClapTrap1.getEnergyPoints(), ClapTrap2.getEnergyPoints()) < 0)
            break;

        std::cout << std::endl;
        ClapTrap2.attack(Player1);
        ClapTrap1.takeDamage(ClapTrap2.getAttackDamage());
    }

    // Find winner's name after battle (loop) ends
    if (ClapTrap1.getHitPoints() <= 0 && ClapTrap2.getHitPoints() > 0)
        winner = ClapTrap2.getName();
    else if (ClapTrap2.getHitPoints() <= 0 && ClapTrap1.getHitPoints() > 0)
        winner = ClapTrap1.getName();
    
    // Announce winner's name (only in case battle doesn't end in a draw)
    if (winner != "") {
        std::cout << std::endl;
        std::cout << winner << " won the battle!!!" << std::endl;
        std::cout << std::endl;
    }
    
    return 0;
}
