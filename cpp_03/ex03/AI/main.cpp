#include "DiamondTrap.hpp"

int main(void) {
    std::string Player1 = "Diam";
    std::string Player2 = "Frag";
    std::string Player3 = "Scav";
    std::string Player4 = "Clap";

    ClapTrap ClapTrap(Player4);
    ScavTrap ScavTrap(Player3);
    FragTrap FragTrap(Player2);
    DiamondTrap DiamondTrap(Player1);

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

    return 0;
}

