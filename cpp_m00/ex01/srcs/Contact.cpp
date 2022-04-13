#include "Contact.hpp"
#include <iostream>
#include <iomanip>


Contact::Contact()
{
}

// Contact::Contact(const Contact &other)
// {
// 	this->FirstName = other.FirstName;
// 	this->LastName = other.LastName;
// 	this->NickName = other.NickName;
// 	this->PhoneNumber = other.PhoneNumber;
// 	this->Secret = other.Secret;
// }

Contact::~Contact()
{
}

std::string Contact::GetFirstName() const
{
	return FirstName;
}

void Contact::SetFirstName(const std::string &FirstName_)
{
	FirstName = FirstName_;
}

std::string Contact::GetLastName() const
{
	return LastName;
}

void Contact::SetLastName(const std::string &LastName_)
{
	LastName = LastName_;
}

std::string Contact::GetNickName() const
{
	return NickName;
}

void Contact::SetNickName(const std::string &NickName_)
{
	NickName = NickName_;
}

std::string Contact::GetPhoneNumber() const
{
	return PhoneNumber;
}

void Contact::SetPhoneNumber(const std::string &PhoneNumber_)
{
	PhoneNumber = PhoneNumber_;
}

std::string Contact::GetSecret() const
{
	return Secret;
}

void Contact::SetSecret(const std::string &Secret_)
{
	Secret = Secret_;
}

void PrintFirstTen(std::string s)
{
	std::cout.fill( ' ' );
	if (s.length() > 10)
	{
		s = s.substr(0, 9);
		s = s.insert(9, ".");
	}
	std::cout << std::setw(10) << s << std::ends;
}

void Contact::PrintContact(int id)
{
	std::string	s;

	s = std::to_string(id + 1);
	std::cout << "|";
	PrintFirstTen(s);
	std::cout << "|";
	PrintFirstTen(GetFirstName());
	std::cout << "|";
	PrintFirstTen(GetLastName());
	std::cout << "|";
	PrintFirstTen(GetNickName());
	std::cout << "|" << std::endl;
}

void Contact::PrintFullContact()
{
	std::cout << "FirstName:     " << GetFirstName() << std::endl;
	std::cout << "SecondName:    " << GetLastName() << std::endl;
	std::cout << "NickName:      " << GetNickName() << std::endl;
	std::cout << "PhoneNumber:   " << GetPhoneNumber() << std::endl;
	std::cout << "DarkestSecret: " << GetSecret() << std::endl;
}
