#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
	this->fpNum = 0;
}

Fixed::Fixed(const Fixed &fixed)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed(const int num)
{
	// std::cout << "Int constructor called" << std::endl;
	this->fpNum = num << fBit;
}

Fixed::Fixed(const float num)
{
	// std::cout << "Float constructor called" << std::endl;
	this->fpNum = std::roundf(num * (1 << fBit));
}

Fixed::~Fixed()
{
	// std::cout << "Default destructor called" << std::endl;
}

Fixed & Fixed::operator=(const Fixed &fixed) {
	// std::cout << "Copy assigment operator called" << std::endl;
	this->fpNum = fixed.getRawBits();
	return (*this);
}

bool Fixed::operator>(const Fixed &fixed) const
{
	return (this->fpNum > fixed.fpNum);
}

bool Fixed::operator<(const Fixed &fixed) const
{
	return (this->fpNum < fixed.fpNum);
}

bool Fixed::operator>=(const Fixed &fixed) const
{
	return (this->fpNum >= fixed.fpNum);
}

bool Fixed::operator<=(const Fixed &fixed) const
{
	return (this->fpNum <= fixed.fpNum);
}

bool Fixed::operator!=(const Fixed &fixed) const
{
	return (this->fpNum != fixed.fpNum);
}

bool Fixed::operator==(const Fixed &fixed) const
{
	return (this->fpNum == fixed.fpNum);
}

Fixed Fixed::operator+(const Fixed &fixed) const{
	Fixed tmp;
	tmp.fpNum = this->fpNum + fixed.fpNum;
	return (tmp);
}

Fixed Fixed::operator-(const Fixed &fixed) const{
	Fixed tmp;
	tmp.fpNum = this->fpNum - fixed.fpNum;
	return (tmp);
}

Fixed Fixed::operator*(const Fixed &fixed) const{
	Fixed tmp(this->toFloat() * fixed.toFloat());
	return (tmp);
}

Fixed Fixed::operator/(const Fixed &fixed) const{
	Fixed tmp;
	tmp.fpNum = this->fpNum / fixed.fpNum;
	return (tmp);
}

Fixed & Fixed::operator++(void) {
	this->fpNum++;
	return (*this);
}

Fixed & Fixed::operator--(void) {
	this->fpNum--;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed	tmp(*this);
	this->fpNum++;
	return (tmp);
}

Fixed Fixed::operator--(int) {
	Fixed	tmp(*this);
	this->fpNum--;
	return (tmp);
}

Fixed & Fixed::min(Fixed & a, Fixed & b) {
	return (a < b ? a : b);
}

const Fixed & Fixed::min(const Fixed & a, const Fixed & b) {
	return (a < b ? a : b);
}

Fixed & Fixed::max(Fixed & a, Fixed & b) {
	return (a > b ? a : b);
}

const Fixed & Fixed::max(const Fixed & a, const Fixed & b) {
	return (a > b ? a : b);
}

int Fixed::getRawBits(void) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->fpNum);
}

void Fixed::setRawBits(int const raw) {
	// std::cout << "setRawBits member function called" << std::endl;
	this->fpNum = raw;
}

float Fixed::toFloat(void) const {
	return ((float) this->fpNum / (1 << fBit));
}

int Fixed::toInt(void) const {
	return (this->fpNum >> fBit);
}

std::ostream & operator<<(std::ostream &out, Fixed const &fixed) {
	out << fixed.toFloat();
	return (out);
}
