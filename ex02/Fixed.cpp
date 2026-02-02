/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenne <jenne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 13:43:23 by jenne             #+#    #+#             */
/*   Updated: 2026/02/02 19:29:43 by jenne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Default constructor
Fixed::Fixed(): _rawBits(0)
{
    // std::cout   << "Default constructor called" << std::endl;
}

//Destructor
Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}

//Copy constructor
Fixed::Fixed(const Fixed &copy)
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

//Assignment operator
Fixed   &Fixed::operator=(const Fixed &copy)
{
    if (this != &copy)
    {
        _rawBits = copy._rawBits;
        // std::cout << "Copy assignment operator called" << std::endl;
    }
    return *this;
}

//Constructor for int
Fixed::Fixed(const int myInt)
{
    // std::cout   << "Int constructor called" << std::endl;
    _rawBits = myInt << _fractionalBits;
}

//Constructor for float
Fixed::Fixed(const float myFloat)
{
    // std::cout   << "Float constructor called" <<std::endl;
    _rawBits = roundf(myFloat * (1 << _fractionalBits));
}

//compare oparators 
bool Fixed::operator>(const Fixed &other) const
{
    return (this->_rawBits > other._rawBits);
}
bool Fixed::operator<(const Fixed &other) const
{
    return (this->_rawBits < other._rawBits);
}
bool Fixed::operator>=(const Fixed &other) const
{
    return (this->_rawBits >= other._rawBits);
}
bool Fixed::operator<=(const Fixed &other) const
{
    return (this->_rawBits <= other._rawBits);
}
bool Fixed::operator!=(const Fixed &other) const
{
    return (this->_rawBits != other._rawBits);
}
bool Fixed::operator==(const Fixed &other) const
{
    return (this->_rawBits == other._rawBits);
}

//compare functions
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return a;
    else
        return b;
}
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a< b)
        return a;
    else    
        return b;
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return a;
    else
        return b;
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a< b)
        return a;
    else    
        return b;
}


//Arithmetic functions
Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed res;
    res.setRawBits(this->_rawBits + other._rawBits);
    return (res);
}
Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed res;
    res.setRawBits(this->_rawBits - other._rawBits);
    return (res);
}
Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed res;
    long tmp = ((long)this->_rawBits << _fractionalBits) / other._rawBits;
    res.setRawBits(tmp);
    return res;
}
Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed res;
    long tmp = (long)this->_rawBits * (long)other._rawBits;
    res.setRawBits(tmp >> _fractionalBits);
    return (res);
}
Fixed &Fixed::operator--()
{
    _rawBits--;
    return(*this);
}
Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    _rawBits--;
    return (temp);                                                                                                                           
}
Fixed &Fixed::operator++()
{
    _rawBits++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    _rawBits++;
    return (temp);
}
//end of Aritmetic functions

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
    // std::cout << "getRawBits member function called" << std::endl;
    return _rawBits;
}

void Fixed::setRawBits(int const newBits)
{
    _rawBits = newBits;
    // std::cout << "setRawBits member function called" << std::endl;
}


// 1/256 ≈ 0.00390625
// Real number	   Calculation (_rawBits)	  Stored _rawBits	toFloat()	            toInt()
// 1.0	                 1 * 256	            256	            256/256 = 1.0	        256>>8 = 1
// 2.5	               2.5 * 256 = 640	        640	            640/256 = 2.5       	640>>8 = 2
// 42.4219	        42.4219*256 ≈10843	       10843	        10843/256 ≈42.421875	10843>>8 =42

// Divide by 256 to get the float back
// Shift by 8 to get only the dollar part