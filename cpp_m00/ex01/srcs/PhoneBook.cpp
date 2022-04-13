#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <string>
#include <iostream>
#include <sstream>

void PhoneBook::MoveContacts(void)
{
	int	i;

	i = (int) this->size;
	if (i == 8)
	{
		this->contacts[7].~Contact();
		i = 7;
	}
	while (--i >= 0)
		this->contacts[i + 1] = this->contacts[i];
}

void PhoneBook::AddContact(Contact &contact)
{
	if (this->size > 0)
		this->MoveContacts();
	if (this->size < 8)
		this->size++;
	this->contacts[0] = contact;
}

std::string readField(std::string prompt)
{
	std::string set;

	std::cout << prompt;
	std::getline(std::cin, set);
	while (set.empty())
	{
		std::cout << "Field cannot be empty!" << std::endl;
		std::cout << prompt;
		std::getline(std::cin, set);
	}
	return (set);
}

void PhoneBook::Add(void)
{
	Contact	a;

	a.SetFirstName(readField("Enter the first name: "));
	a.SetLastName(readField("Enter the last name: "));
	a.SetNickName(readField("Enter the nickname: "));
	a.SetPhoneNumber(readField("Enter the phone number: "));
	a.SetSecret(readField("Enter the darknest secret: "));

	AddContact(a);
}

bool PhoneBook::SearchNumber()
{
	std::string	s;
	int			i;

	i = 0;
	std::cout << "Enter the contact id to be printed: ";
	std::getline(std::cin, s);
	std::stringstream iv(s);
	iv >> i;
	if (i > 0 && i <= (int) this->size)
	{
		this->contacts[i - 1].PrintFullContact();
		return (true);
	}
	else
	{
		std::cout << "Wrong range. Min number is 1. Max number is " << this->size << "." << std::endl;
		return (false);
	}
}

void PhoneBook::Search(void)
{
	int			i;
	std::string	s;

	i = -1;
	std::cout << "|    ID    | FirstName|SecondName| NickName |" << std::endl;
	while (++i < (int) this->size)
		this->contacts[i].PrintContact(i);
	while (!SearchNumber())
	{
		std::cout << "Try again? [y/n]" << std::endl;
		std::getline(std::cin, s);
		if (s[0] == 'y')
			continue;
		else
			break;
	}
}

void	printPrompt(void)
{
	std::cout << "Print command: ADD, SEARCH or EXIT" << std::endl;
}

int main(void)
{
	std::string	read;
	PhoneBook	book;

	std::cout << "Hi! This is PhoneBook!" << std::endl;
	while (true)
	{
		printPrompt();
		std::getline (std::cin, read);
		for (int i = 0; i < (int) read.length(); i++)
			read[i] = std::toupper(read[i]);
		if (!read.compare("ADD"))
			book.Add();
		else if (!read.compare("SEARCH"))
			book.Search();
		else if (!read.compare("EXIT"))
			break ;
		else
			std::cout << "Wrong command" << std::endl;
		read.clear();
	}
	return (0);
}
