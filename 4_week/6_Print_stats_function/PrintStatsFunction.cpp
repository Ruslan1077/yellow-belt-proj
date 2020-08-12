#include <algorithm>
#include <iostream>
#include <vector>

#define RANGE(a) std::begin(a),std::end(a)


enum class Gender
{
	FEMALE,
	MALE
};


struct Person
{
	int age;
	Gender gender;
	bool is_employed;
};


template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end);

void PrintStats1(std::vector<Person> persons);
void PrintStats2(std::vector<Person> persons);



int main_h6()
{
	std::vector<Person> persons = {
	  {31, Gender::MALE, false},
	  {40, Gender::FEMALE, true},
	  {24, Gender::MALE, true},
	  {20, Gender::FEMALE, true},
	  {80, Gender::FEMALE, false},
	  {78, Gender::MALE, false},
	  {10, Gender::FEMALE, false},
	  {55, Gender::MALE, true},
	};

	// Второй вариант быстрее
	PrintStats2(persons);
	return 0;
}


template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end) 
{
	if (range_begin == range_end) 
	{
		return 0;
	}

	std::vector<typename InputIt::value_type> range_copy(range_begin, range_end);
	auto middle = std::begin(range_copy) + range_copy.size() / 2;

	std::nth_element(
		std::begin(range_copy), middle, std::end(range_copy),
		[](const Person & lhs, const Person & rhs) {
			return lhs.age < rhs.age;
		});
	return middle->age;
}


void PrintStats1(std::vector<Person> persons)
{
	std::cout << "Median age: " << ComputeMedianAge(persons.begin(), persons.end()) << std::endl;
	
	auto female_range_iter = std::partition(RANGE(persons),
		[](const Person & person) { 
			return person.gender == Gender::FEMALE; 
		});
	std::cout << "Median age for females: " << ComputeMedianAge(persons.begin(), female_range_iter) << std::endl;


	auto male_range_iter = std::partition(RANGE(persons),
		[](const Person & person) {
			return person.gender == Gender::MALE;
		});
	std::cout << "Median age for male: " << ComputeMedianAge(persons.begin(), male_range_iter) << std::endl;


	auto employed_females_range_iter = std::partition(RANGE(persons),
		[](const Person& person){
			return person.gender == Gender::FEMALE && person.is_employed;
		});
	std::cout << "Median age for employed females: " << ComputeMedianAge(persons.begin(), employed_females_range_iter) << std::endl;


	auto unemployed_females_range_iter = std::partition(RANGE(persons),
		[](const Person & person) {
		return person.gender == Gender::FEMALE && !person.is_employed;
	});
	std::cout << "Median age for unemployed females: " << ComputeMedianAge(persons.begin(), unemployed_females_range_iter) << std::endl;


	auto employed_males_range_iter = std::partition(RANGE(persons), 
		[](const Person& person) {
			return person.gender == Gender::MALE && person.is_employed;
		});
	std::cout << "Median age for employed males: " << ComputeMedianAge(persons.begin(), employed_males_range_iter) << std::endl;


	auto unemployed_males_range_iter = std::partition(RANGE(persons),
		[](const Person & person) {
		return person.gender == Gender::MALE && !person.is_employed;
	});
	std::cout << "Median age for unemployed males: " << ComputeMedianAge(persons.begin(), unemployed_males_range_iter) << std::endl;
}

void PrintStats2(std::vector<Person> persons) {
	// Преобразуем порядок людей к следующему:
	//                  persons
	//                 /      \
    //          females        males
	//         /       \     /      \
    //      empl.  unempl. empl.   unempl.
	
	auto females_end = std::partition(
		RANGE(persons),
		[](const Person& p){
			return p.gender == Gender::FEMALE;
		});

	auto employed_females = std::partition(
		RANGE(persons),
		[](const Person & p) {
			return p.gender == Gender::FEMALE && p.is_employed;
		});

	auto employed_males = std::partition(
		RANGE(persons),
		[](const Person & p) {
			return p.gender == Gender::MALE && p.is_employed;
		});



	std::cout << "Median age: "							<< ComputeMedianAge(persons.begin(),	persons.end())		<< std::endl;
	std::cout << "Median age for females: "				<< ComputeMedianAge(persons.begin(),	females_end)		<< std::endl;
	std::cout << "Median age for male: "				<< ComputeMedianAge(females_end,		persons.end())		<< std::endl;
	std::cout << "Median age for employed females: "	<< ComputeMedianAge(persons.begin(),	employed_females)	<< std::endl;
	std::cout << "Median age for unemployed females: "	<< ComputeMedianAge(employed_females,	females_end)		<< std::endl;
	std::cout << "Median age for employed males: "		<< ComputeMedianAge(females_end,		employed_males)		<< std::endl;
	std::cout << "Median age for unemployed males: "	<< ComputeMedianAge(employed_males,		persons.end())		<< std::endl;
}