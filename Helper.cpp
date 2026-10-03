#include <vector>
#include "Original.h"
#include "Functions.h"
#include "ModApi/Lawn.h"

std::vector<Zombie*> GetAllZombies(Board* aLawn)
{
    std::vector<Zombie*> zombies;

    Zombie* z = nullptr;
    while (aLawn->mZombies.Next(&z))
    {
        if (z)
            zombies.push_back(z);
    }
	delete z;

    return zombies;
}

std::vector<Plant*> GetAllPlants(Board* aLawn)
{
    std::vector<Plant*> Plants;

    Plant* p = nullptr;
    while (aLawn->mPlants.Next(&p))
    {
        if (p)
            Plants.push_back(p);
    }
	delete p;

    return Plants;
}