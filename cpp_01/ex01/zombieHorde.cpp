#include"Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie*  zombiHorde = new Zombie[N];
	
	while(N > 0) {
		zombiHorde[N].set_name(name);
		--N;
	}
	return zombiHorde;

}
