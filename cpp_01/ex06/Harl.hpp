/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 22:45:09 by ccarrace          #+#    #+#             */
/*   Updated: 2024/04/16 19:18:48 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <cctype>

class	Harl {

	private:
		void	debug( void);
		void	info( void );
		void	warning( void );
		void	error( void );

	public:
		void	complain( std::string level);
};

#endif