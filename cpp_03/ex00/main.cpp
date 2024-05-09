/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:48:49 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/09 14:31:56 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void){

	ClapTrap a("Attacker");
	for (int i = 9; i > 0; i--)
		a.attack("a box");
	a.beRepaired(2);
	a.beRepaired(2);

	a.takeDamage(5);
	return 0;
}

/* In case you want to see a real battle simulation, uncomment the following main
    and don't forget to uncomment the following in 'ClapTrap.cpp' file:

    1. The dice() function in 'ClapTrap.cpp' file 
    2. The line that prints the result of the dice roll (line 101)
*/

// int checkPointsLevels ( int hitPts1, int hitPts2, int energyPts1, int energyPts2 ) {

//         if (hitPts1 <= 0 || hitPts2 <= 0)
//             return -1;
//         if (energyPts1 <= 0 && energyPts2 <= 0) {
//             std::cout << std::endl;
//             std::cout << "Fighters ran out of energy! Combat ends in a draw!"
//                       << std::endl;
//             std::cout << std::endl;
//             return -1;
//         }
//         return 0;
// }

// int main(void) {

// 	std::string Player1 = "Attacker";
// 	std::string Player2 = "Defender";
//     std::string winner;
//     ClapTrap    ClapTrap1(Player1);
//     ClapTrap    ClapTrap2(Player2);


//     while (ClapTrap1.getHitPoints() > 0 && ClapTrap2.getHitPoints() > 0) {
        
//         // Player1's turn
//         if (checkPointsLevels(ClapTrap1.getHitPoints(), ClapTrap2.getHitPoints(), 
//                 ClapTrap1.getEnergyPoints(), ClapTrap2.getEnergyPoints()) < 0)
//             break;

//         std::cout << std::endl;
//         ClapTrap1.attack(Player2);
//         ClapTrap2.takeDamage(ClapTrap1.getAttackDamage());

//         // Player2's turn
//         if (checkPointsLevels(ClapTrap1.getHitPoints(), ClapTrap2.getHitPoints(), 
//                 ClapTrap1.getEnergyPoints(), ClapTrap2.getEnergyPoints()) < 0)
//             break;

//         std::cout << std::endl;
//         ClapTrap2.attack(Player1);
//         ClapTrap1.takeDamage(ClapTrap2.getAttackDamage());
//     }

//     // Find winner's name after battle (loop) ends
//     if (ClapTrap1.getHitPoints() <= 0 && ClapTrap2.getHitPoints() > 0)
//         winner = ClapTrap2.getName();
//     else if (ClapTrap2.getHitPoints() <= 0 && ClapTrap1.getHitPoints() > 0)
//         winner = ClapTrap1.getName();
    
//     // Announce winner's name (only in case battle doesn't end in a draw)
//     if (winner != "") {
//         std::cout << std::endl;
//         std::cout << winner << " won the battle!!!" << std::endl;
//         std::cout << std::endl;
//     }
    
//     return 0;
// }
