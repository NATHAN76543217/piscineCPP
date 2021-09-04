# include "Cat.hpp"
# include "Dog.hpp"

# define NB_ANIMALS 4

int main()
{
	int				i = 0;
	const Animal	*Animals[NB_ANIMALS];

// Init originals
	std::cout << "__init_originals__" << std::endl << std::endl;
	Dog				dog;
	std::cout << std::endl;
	Cat				cat;

	cat.setIdea(1, "despise some human");
	dog.setIdea(1, "run after my tail!");

// Init dogs
	std::cout << std::endl << "__init_dogs__" << std::endl;
	while (i < NB_ANIMALS / 2)
	{
		std::cout << std::endl << "[i] = "<< i << std::endl;
		Animals[i++] = new Dog(dog);
	}

// Init cats
	std::cout << std::endl << "__init_cats__" << std::endl;
	while (i < NB_ANIMALS - 1)
	{
		std::cout << std::endl << "[i] = "<< i << std::endl;
		Animals[i++] = new Cat(cat);
	}
	dog.setIdea(1, "seat down");
	cat.setIdea(1, "I changed my mind");
	Animals[i] = new Cat(cat);
	cat.setIdea(1, "I changed my mind again");

// Delete array
	std::cout << std::endl << "__deleting_array__" << std::endl << std::endl;
	for (i = 0; i < NB_ANIMALS; i++)
	{
		delete Animals[i];
		std::cout << std::endl;
	}

// Delete originals at program exit
	std::cout << std::endl << "__deleting_originals__" << std::endl << std::endl;
	return (0);
}