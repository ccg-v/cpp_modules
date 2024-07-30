/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 21:21:58 by ccarrace          #+#    #+#             */
/*   Updated: 2024/07/30 23:39:30 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>	//	std::rand()
#include <ctime>    // For std::time

/* --- Orthodox Canonical Form implementation ------------------------------- */

//	Default constructor
ShrubberyCreationForm::ShrubberyCreationForm() 
	: AForm("Default ShrubberryCreationForm", 145, 137), _target("Unknown") {
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

//	Copy constructor (1)
ShrubberyCreationForm::ShrubberyCreationForm (const ShrubberyCreationForm & source)
	: AForm(source), _target(source._target) {
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

//	Copy assignment operator
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm & source) {
	std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	if (this == &source)
		return (*this);
	AForm::operator=(source);  // Call the base class assignment operator to copy its members
	_target = source._target;
	return (*this);
}

//	Default destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm default destructor called" << std::endl;
}

/* --- Parameterized constructor -------------------------------------------- */

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
    std::cout << "ShrubberyCreationForm parameterized constructor called" << std::endl;
}


/* --- Member functions ----------------------------------------------------- */

void	ShrubberyCreationForm::performAction() const {
	std::ofstream ofs((_target + "_shrubbery").c_str(), std::ios::app); // convert std::string to const *char
	if (ofs) {
		std::srand(std::time(0));
		int	treeChoice = std::rand() % 3;
		if (treeChoice == 0)
			ofs << _tree1;
		else if (treeChoice ==1)
			ofs << _tree2;
		else
			ofs << _tree3;
	}
	ofs.close();
	std::cout << "\t" << _target << " ShrubberyCreationForm has been executed (grade "
			  << getGradeToExecute() << " needed)" << std::endl;
	std::cout << "\tPermission to create " << _target << " granted, check "
			  << _target << "_shrubbery document" << std::endl;		  
}

/* --- Static member variables initialization ------------------------------- */

const std::string	ShrubberyCreationForm::_tree1 =
	"\n"
	"                     ...\n"                  
	"              .....,,;:::,.',.\n"             
	"          .';cllllooooolc::cc;.\n"           
	"       .,:cooddxxxxxxkxdddoodlcc;'.\n"      
	"     .';::lloodxxxkkkOkkkkkkxkxxddl.\n"     
	"    .,:clccccllodxdoddoodkOOOOOOkxxo;\n"     
	"    .';:looooooddl:ldddddxxddxxxkkkkl'\n"    
	"   ..,;;:lcclloodllxxxxxxxxdxxxxxxxkdc,.\n"  
	"   ..,;;,;c:cllodxxkkxxkkdkkkOO0Oxccxd:'.\n"
	"     .....';:lc:lollooxOOkxddddkkd;''',,.\n"
	"         .,,,::.'cdddxdc;;cc:;'':l:.\n"     
	"         ........',ldd;\n"                  
	"                   ,oo'\n"                  
	"                   ;xd,\n"                  
	"___|___..__|/_ ....ckkc.... __.__.||.____\n"
	"\n";

const std::string	ShrubberyCreationForm::_tree2 =
	"\n"
	"                     ...\n"                    
	"                    ;oc'\n"                  
	"                   .okko.\n"                 
	"                   ;kkkk:\n"                 
	"                   :kkkkl.\n"                
	"                  .oxkkOd.\n"                
	"                  ;xkkkkx;\n"                
	"                  ;kOkkkk:\n"                
	"                 .cxxkkkkc\n"                
	"                 'dkxkkkkl.\n"               
	"                 'dxxxxxko.\n"               
	"                 ,xxxxkxxd'\n"               
	"                 :xxkkkkkxl.\n"              
	"                .dkxkkkkkkx;\n"              
	"                .oxxxkkkxxxl.\n"             
	"                ;ddxxxkkkxx:\n"              
	"               .okxxkxxxxxx;\n"              
	"               .oddxxxxxkkk:\n"              
	"               .lddxxxxkkkd'\n"              
	"               .oxxxxxxxxxo.\n"              
	"               .oxxxxxxxxkl.\n"              
	"               .okxxxxxxkkc\n"               
	"                :kkxxkOOx:.\n"               
	"                 :kOdool'v\n"                 
	"                  .;,|\n"                    
	"                    ||\n"                    
	"                    :|\n"                    
	"__.__..____|/______ || ____.._.____|/____\n"
	"\n";

const std::string	ShrubberyCreationForm::_tree3 =
	"\n"
	"                  ..         .\n"          
	"       ..'','...';:;'''''. .',,.\n"        
	"      ';,:c:,.',col:;;,,,'.';::'.\n"       
	"   ...,,;::lc;,;cdc;;;:;,;;;:c;,'.\n"      
	"  ,::;,,,;ldxoc;;c:;:::;;:::cc:;;,.\n"     
	" .;:;,''.,oxko;,;:c::cc;;:ccclc:cc;.\n"    
	"  ',;,'..;oxxc;,,;:clc:;::c:clcccc:.\n"    
	"  .,,,;;:lldkd:;clccooc:clllc::loc:,.\n"   
	"  .;,:cccclxxl;:llcloolcodlol;:lodc:;.\n"  
	"  .,';;,'.',;. .,;;looollc;::;;;:cc:,..\n" 
	"  ......        ..':ldx:...........,..\n"  
	"                  .cdkd.     .     ..\n"   
	"                  .,ldx;\n"                
	"                   .:coc.\n"               
	"__..|/...___..______.....________/.___||_\n"
	"\n";

/*
 *	(1) Initialization list vs. Copy assignment (*this = source)
 *
 * 	Copy assignment:
 * 
 * 	ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &source)
 *  	: AForm(source) { 	// Initialize base class
 *   		*this = source; // Use assignment operator to copy
 *   		std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
 *	}
 *
 * 	Initialization list;
 * 
 * 	ShrubberyCreationForm::ShrubberyCreationForm (const ShrubberyCreationForm & source)
 *		: AForm(source), _target(source._target) {
 *			std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
 * 
 * 	The copy assignment operator is used to assign values from one already-constructed 
 *	object to another already-constructed object. This process involves:
 *
 *	Existing Object:
 *      The destination object must already be constructed and initialized, but 
 *		potentially with default or previously set values.
 *
 *  Overwriting Values:
 *      The copy assignment operator then overwrites these existing values with the 
 * 		values from the source object. This can lead to intermediate states where
 * 		members are default-initialized or contain old values before they are overwritten.
 * 
 * 	Instead, initialization list initializes members directly when the object is created.
 * 	There’s no intermediate state where members are uninitialized or partially initialized.
 * 
 *	The copy assignment operator is not intended for initializing a new object; instead,
 *	it is designed for reassigning an existing object's state. When used correctly, it is
 *	a safe and essential part of managing objects, especially when dealing with dynamic
 *	resources or complex states. 
 */

/*
 *	(2) The std::string and char* (C-style strings) represent strings in C++ but in
 *		different ways and with different features. Key differences:
 *
 *		1. Memory Management:
 *
 *		 - std::string manages its own memory, reducing the risk of memory-related errors.
 *    	 - char* requires explicit memory management, increasing the risk of memory-related
 * 				errors.
 *
 *		2. Functionality:
 *
 *		 - std::string has a rich set of member functions for string manipulation.
 *		 - char* relies on C-style string manipulation functions, which are more limited
 *				and prone to errors.
 *
 *		3. Safety:
 *
 *		 - std::string provides bounds checking and automatic memory management, making 
 *				it safer.
 *		 - char* does not provide bounds checking and requires manual memory management, 
 *				making it more error-prone.
 */