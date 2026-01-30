/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenne <jenne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 16:34:07 by jenne             #+#    #+#             */
/*   Updated: 2026/01/30 17:19:50 by jenne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Default constructor
Fixed::Fixed(): _rawBits(0)
{
    std::cout   << "Default constructor called" << std::endl;
}

//Destructor
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

//Copy constructor
Fixed::Fixed(const Fixed &copy) : _rawBits(copy._rawBits)
{
    std::cout << "Copy constructor called" << std::endl;
}

//Assignment operator
Fixed   &Fixed::operator=(const Fixed &copy)
{
    if (this != &copy)
    {
        _rawBits = copy._rawBits;
        std::cout << "Copy assignment operator called" << std::endl;
    }
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _rawBits;
}

void Fixed::setRawBits(int const newBits)
{
    _rawBits = newBits;
    std::cout << "setRawBits member function called" << std::endl;
}