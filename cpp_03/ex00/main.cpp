/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:48:49 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/08 01:02:01 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {

    ClapTrap ClapTrap1("Attacker");
    ClapTrap ClapTrap2("Defender");

    while (ClapTrap1.getHitPoints() > 0 && ClapTrap2.getHitPoints() > 0) {
        if (ClapTrap1.getHitPoints() <= 0 || ClapTrap2.getHitPoints() <= 0)
            break;

        ClapTrap1.attack("Defender");
        ClapTrap2.takeDamage(ClapTrap1.getAttackDamage());
        std::cout << std::endl;

        if (ClapTrap1.getHitPoints() <= 0 || ClapTrap2.getHitPoints() <= 0)
            break;

        ClapTrap2.attack("Attacker");
        ClapTrap1.takeDamage(ClapTrap2.getAttackDamage());
        std::cout << std::endl;
    }

    if (ClapTrap1.getHitPoints() <= 0)
        std::cout << "\t" << ClapTrap2.getName() << " won the battle!" << std::endl;
    else
        std::cout << "\t" << ClapTrap1.getName() << " won the battle!" << std::endl;

    return 0;
	
}
