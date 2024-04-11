/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adding_file_content.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 19:48:03 by ccarrace          #+#    #+#             */
/*   Updated: 2024/04/11 20:24:32 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>      // std::ofstream

int main () {

  std::ofstream ofs;
  ofs.open ("file.txt", std::ofstream::out | std::ofstream::app);

  ofs << "\n more lorem ipsum";

  ofs.close();

  return 0;
}