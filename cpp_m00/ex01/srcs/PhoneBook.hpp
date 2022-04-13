#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
private:
	Contact	contacts[8];
	size_t	size;
	void	AddContact(Contact &contact);
	void	MoveContacts(void);

public:
	PhoneBook();
	~PhoneBook();

	void Add();
	void Search();
	bool SearchNumber();
};

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}


#endif
