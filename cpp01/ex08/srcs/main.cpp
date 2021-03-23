# include "Human.hpp"

int	main(void)
{
	Human human("bob");

	human.action("melee", "mark");
	human.action("ranged", "goblin");
	human.action("shout", "shark");

	std::cout << std::endl << std::string(45, '-') << std::endl << std::endl;
	
	human.action("ranged", "goblin");
	human.action("shout", "shark");
	human.action("melee", "mark");

    return 0;
}
