# include "Cat.hpp"
# include "Dog.hpp"
# include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal * w = new WrongCat();
	
	std::cout << std::endl << "Types:" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	std::cout << w->getType() << " " << std::endl;
	
	std::cout << std::endl << "Sounds:" << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl << "Test with wrong class" << std::endl;
	w->makeSound();
	return (0);
}