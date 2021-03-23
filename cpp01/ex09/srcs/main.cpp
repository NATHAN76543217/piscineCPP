# include "Logger.hpp"

int	main(void)
{
	Logger	log("test");
	Logger	log2("log");

	log.log("file", "coucou ceci est un log dans un fichier");
	log.log("file", "coucou ceci est un log ajouté à la fin d'un fichier");
	log.log("cout", "coucou ceci est un log sur la sortie standard");

	log2.log("file", "coucou ceci est un log dans un autre fichier");
	log2.log("file", "coucou ceci est un autre log dans un autre fichier");
	log2.log("cout", "coucou ceci est un autre log sur la sortie standard");
    return 0;
}
