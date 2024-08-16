/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarExceptions.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 21:24:01 by ccarrace          #+#    #+#             */
/*   Updated: 2024/08/16 21:36:51 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarExceptions.hpp"

const char *NonDisplayableException::what() const throw() {
    return "non displayable";
}

const char *ImpossibleConversionException::what() const throw() {
    return "impossible";
}

const char *PositiveInfException::what() const throw() {
    return "+inf";
}

const char *NegativeInfException::what() const throw() {
    return "-inf";
}

const char *PositiveInffException::what() const throw() {
    return "+inff";
}

const char *NegativeInffException::what() const throw() {
    return "-inff";
}
