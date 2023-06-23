#include"Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie*  zombiHorde = new Zombie[N];
	if (N < 0 || name.empty())
		return NULL;
	while(N > 0) {
		zombiHorde[N].set_name(name);
		--N;
	}
	return zombiHorde;

}
