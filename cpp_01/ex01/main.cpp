#include"Zombie.hpp"
#include<string>

int main() {

	int N = 20;
	Zombie* Horde = zombieHorde(N, "zombie horde");
	if (Horde == NULL)
		return 1;
	for (int i = 0; i < N; i++)
		Horde[i].announce();
	delete[] Horde;
	return 0;
}
