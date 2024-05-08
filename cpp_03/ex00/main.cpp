/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:48:49 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/08 18:23:22 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {

    ClapTrap    ClapTrap1("Attacker");
    ClapTrap    ClapTrap2("Defender");
    std::string winner;

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
        ClapTrap1.attack("Defender");
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
        ClapTrap2.attack("Attacker");
        ClapTrap1.takeDamage(ClapTrap2.getAttackDamage());
        
    }

    if (ClapTrap1.getHitPoints() <= 0 && ClapTrap2.getHitPoints() > 0)
        winner = ClapTrap2.getName();
    else if (ClapTrap2.getHitPoints() <= 0 && ClapTrap1.getHitPoints() > 0)
        winner = ClapTrap1.getName();
    
    if (winner != "") {
        std::cout << std::endl;
        std::cout << winner << " won the battle!" << std::endl;
        std::cout << std::endl;
    }
    
    return 0;
	
}
