/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenne <jenne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 17:35:44 by jenne             #+#    #+#             */
/*   Updated: 2026/02/01 20:11:28 by jenne            ###   ########.fr       */
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
Fixed::Fixed(const Fixed &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
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

//Constructor for int
Fixed::Fixed(const int myInt)
{
    std::cout   << "Int constructor called" << std::endl;
    _rawBits = myInt << _fractionalBits;
}

//Constructor for float
Fixed::Fixed(const float myFloat)
{
    std::cout   << "Float constructor called" <<std::endl;
    _rawBits = roundf(myFloat * (1 << _fractionalBits));
}
float   Fixed::toFloat(void) const
{
    return ((float)_rawBits / (1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
    return (_rawBits >> _fractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
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


// 1/256 ≈ 0.00390625
// Real number	   Calculation (_rawBits)	  Stored _rawBits	toFloat()	            toInt()
// 1.0	                 1 * 256	            256	            256/256 = 1.0	        256>>8 = 1
// 2.5	               2.5 * 256 = 640	        640	            640/256 = 2.5       	640>>8 = 2
// 42.4219	        42.4219*256 ≈10843	       10843	        10843/256 ≈42.421875	10843>>8 =42