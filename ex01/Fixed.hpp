/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenne <jenne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 17:35:29 by jenne             #+#    #+#             */
/*   Updated: 2026/02/01 18:30:34 by jenne            ###   ########.fr       */
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

    int getRawBits(void) const;
    void    setRawBits(int const raw);
    float   toFloat(void) const;
    int toInt(void) const;
};
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
#endif