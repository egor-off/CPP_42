#ifndef CONTACT_H
# define CONTACT_H

#include <string>

class Contact
{
private:
	std::string	FirstName;
	std::string	LastName;
	std::string	NickName;
	std::string	PhoneNumber;
	std::string	Secret;

public:
	Contact();
	// Contact(const Contact &other);
	~Contact();

	std::string GetFirstName() const;
	void SetFirstName(const std::string &FirstName_);

	std::string GetLastName() const;
	void SetLastName(const std::string &LastName_);

	std::string GetNickName() const;
	void SetNickName(const std::string &NickName_);

	std::string GetPhoneNumber() const;
	void SetPhoneNumber(const std::string &PhoneNumber_);

	std::string GetSecret() const;
	void SetSecret(const std::string &Secret_);

	void PrintContact(int id);
	void PrintFullContact();
};

#endif
