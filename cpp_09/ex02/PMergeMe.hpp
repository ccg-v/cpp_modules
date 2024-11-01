/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:47:04 by ccarrace          #+#    #+#             */
/*   Updated: 2024/11/01 21:44:10 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <list>

class PMergeMe {

	private:

		std::vector<int>	_vec;
		std::list<int>		_lst;
		
	public:

	/* --- Orthodox Canonical Form ---------------------------------------------- */

	PMergeMe();										// Default constructor
	PMergeMe(const PMergeMe & source);				// Copy constructor
	PMergeMe & operator=(const PMergeMe & source);	// Copy assignment operator
	~PMergeMe();									// Default destructor
};

#endif