/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenne <jenne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 13:42:57 by jenne             #+#    #+#             */
/*   Updated: 2026/02/02 19:34:34 by jenne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <cmath>

class Fixed
{
private:
    int _rawBits;
    static const int _fractionalBits = 8;
public:
    Fixed();
    Fixed(const int myInt);
    Fixed(const float myFloat);
    Fixed(const Fixed &copy);
    Fixed &operator=(const Fixed &other);
    ~Fixed();

    //Compare operators
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;

    //Arithmetic operators
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator--(int);
    Fixed &operator--();
    Fixed operator++(int);
    Fixed &operator++();
    
    //compare functions
    static Fixed &max(Fixed &a, Fixed &b);
    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    

    int getRawBits(void) const;
    void    setRawBits(int const newBits);
    float   toFloat(void) const;
    int toInt(void) const;
};
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
#endif