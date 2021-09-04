# include "Cat.hpp"
# include "Dog.hpp"

# define NB_ANIMALS 4

int main()
{
	int				i = 0;
	const Animal	*Animals[NB_ANIMALS];

	std::cout << "__init_originals__" << std::endl << std::endl;
	Dog				dog;
	std::cout << std::endl;
	Cat				cat;

	std::cout << std::endl << "__test_animal__" << std::endl << std::endl;
	{
		Animal	test;
		test.makeSound();
	}


	cat.setIdea(1, "despise some human");
	dog.setIdea(1, "run after my tail!");
	std::cout << std::endl << "__init_dogs__" << std::endl;
	while (i < NB_ANIMALS / 2)
	{
		std::cout << std::endl << "[i] = "<< i << std::endl;
		Animals[i++] = new Dog(dog);
	}
	std::cout << std::endl << "__init_cats__" << std::endl;
	while (i < NB_ANIMALS - 1)
	{
		std::cout << std::endl << "[i] = "<< i << std::endl;
		Animals[i++] = new Cat(cat);
	}
	cat.setIdea(1, "I changed my mind");
	dog.setIdea(1, "seat down");
	Animals[i] = new Cat(cat); 
	std::cout << std::endl << "__deleting_array__" << std::endl << std::endl;
	for (i = 0; i < NB_ANIMALS; i++)
	{
		delete Animals[i];
		std::cout << std::endl;
	}
	std::cout << std::endl << "__deleting_originals__" << std::endl << std::endl;
	return (0);
}