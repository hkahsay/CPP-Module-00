#include"Zombie.hpp"
#include<string>

int main() {

	int N = 10;
	Zombie* Horde = zombieHorde(N, "zombie horde");

	for (int i = 0; i < N; i++)
	{
		Horde[i].announce();
	}
	
	// delete allocZombie;
	delete[] Horde;

	return 0;
}
