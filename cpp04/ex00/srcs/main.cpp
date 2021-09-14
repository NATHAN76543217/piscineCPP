# include "Cat.hpp"
# include "Dog.hpp"
# include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* d = new Dog();
	const Animal* c = new Cat();
	const WrongAnimal* wa = new WrongAnimal();
	const WrongAnimal* wc = new WrongCat();
	
	std::cout << std::endl << "Types:" << std::endl;
	std::cout << c->getType() << " " << std::endl;
	std::cout << d->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	std::cout << wa->getType() << " " << std::endl;
	std::cout << wc->getType() << " " << std::endl;
	
	std::cout << std::endl << "Sounds:" << std::endl;
	c->makeSound(); //will output the cat sound!
	d->makeSound();
	meta->makeSound();

	std::cout << std::endl << "Test with wrong class:" << std::endl;
	wa->makeSound();
	wc->makeSound();

	std::cout << std::endl;
	delete meta;
	delete d;
	delete c;
	delete wa;
	delete wc;
	return (0);
}