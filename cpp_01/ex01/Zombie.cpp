/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 23:15:45 by ccarrace          #+#    #+#             */
/*   Updated: 2024/04/03 23:34:49 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Student {
   private:
      std::string _login;
   
   public:
      // Constructor declaration
      Student();
      
      // Destructor declaration
      ~Student();
};

// Constructor definition
Student::Student() {
    _login = "default";
    std::cout << "Student with default login is born" << std::endl;
}

// Destructor definition
Student::~Student() {
    std::cout << "Student " << _login << " died" << std::endl;
}

int main() {
    Student *students = new Student[42];
    delete [] students;
    return 0;
}

