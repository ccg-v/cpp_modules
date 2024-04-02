/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 23:22:20 by ccarrace          #+#    #+#             */
/*   Updated: 2024/04/03 00:32:25 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {

  Zombie *heapZombie = newZombie("heap_zombie");
  randomChump("stack_zombie");
  delete heapZombie;
  
  return 0;
  
}