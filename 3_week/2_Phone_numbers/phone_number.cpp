#include "phone_number.h"

PhoneNumber::PhoneNumber(const std::string& international_number)
{
	int border_counter = 0;
	
	if (international_number[0] != '+')
	{
		throw std::invalid_argument("Phone number must starts with \"+\" symbol");
	}

	for (size_t item = 1; item < international_number.size(); item++)
	{
		if (international_number[item] == '-')
		{
			border_counter++;
			continue;
		}

		if (border_counter == 0)
		{
			this->country_code_ += international_number[item];
		}
		else if (border_counter == 1)
		{
			this->city_code_ += international_number[item];
		}
		else
		{
			this->local_number_ += international_number[item];
		}
	}

	if (   !this->country_code_.size()
		|| !this->city_code_.size()
		|| !this->local_number_.size())
	{
		throw std::invalid_argument("Phone number must be like \"+XXX-YYY-ZZZ\" or \"+XXX-YYY-ZZZ-ZZZ...\"");
	}
}

std::string PhoneNumber::GetCountryCode() const
{
	return this->country_code_;
}

std::string PhoneNumber::GetCityCode() const
{
	return this->city_code_;
}

std::string PhoneNumber::GetLocalNumber() const
{
	return this->local_number_;
}

std::string PhoneNumber::GetInternationalNumber() const
{
	return "+" + this->country_code_ + "-" 
			   + this->city_code_    + "-" 
		       + this->local_number_;
}
