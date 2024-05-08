/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:48:49 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/09 00:48:46 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {

	std::string Player1 = "Attacker";
	std::string Player2 = "Defender";
    std::string winner;
    ClapTrap    ClapTrap1(Player1);
    ClapTrap    ClapTrap2(Player2);


    while (ClapTrap1.getHitPoints() > 0 && ClapTrap2.getHitPoints() > 0) {
        
        if (ClapTrap1.getHitPoints() <= 0 || ClapTrap2.getHitPoints() <= 0)
            break;
        if (ClapTrap1.getEnergyPoints() <= 0 && ClapTrap2.getEnergyPoints() <= 0) {
            std::cout << std::endl;
            std::cout << "Fighters ran out of energy! Combat ends in a stalemate!"
                      << std::endl;
            std::cout << std::endl;
            break;
        }

        std::cout << std::endl;
        ClapTrap1.attack(Player2);
        ClapTrap2.takeDamage(ClapTrap1.getAttackDamage());

        if (ClapTrap1.getHitPoints() <= 0 || ClapTrap2.getHitPoints() <= 0)
            break;
        if (ClapTrap1.getEnergyPoints() <= 0 && ClapTrap2.getEnergyPoints() <= 0) {
            std::cout << std::endl;
            std::cout << "Fighters ran out of energy! Combat ends in a stalemate!"
                      << std::endl;
            std::cout << std::endl;
            break;
        }

        std::cout << std::endl;
        ClapTrap2.attack(Player1);
        ClapTrap1.takeDamage(ClapTrap2.getAttackDamage());
        
    }

    if (ClapTrap1.getHitPoints() <= 0 && ClapTrap2.getHitPoints() > 0)
        winner = ClapTrap2.getName();
    else if (ClapTrap2.getHitPoints() <= 0 && ClapTrap1.getHitPoints() > 0)
        winner = ClapTrap1.getName();
    
    if (winner != "") {
        std::cout << std::endl;
        std::cout << winner << " won the battle!!!" << std::endl;
        std::cout << std::endl;
    }
    
    return 0;
	
}
