#include <iostream>
#include <string>


namespace HW_1 {

	class Animal {
	public:
		const std::string _name;

		Animal(const std::string& name = "animal") : _name(name) { }
	};


	class Dog : public Animal {
	public:
		void Bark() {
			std::cout << _name << " barks: woof!" << std::endl;
		}

		Dog(const std::string& name = "dog") : Animal(name) { }
	};
}


int main_hw1()
{
	HW_1::Dog d;
	d.Bark();

	return 0;
}