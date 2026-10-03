#include <vector>
#include "Original.h"
#include "Functions.h"
#include "ModApi/Lawn.h"

std::list<Zombie*> Board::GetAllZombies(Board* aLawn)
{
    std::list<Zombie*> zombies;

    Zombie* z = nullptr;
    while (aLawn->mZombies.Next(&z))
    {
        if (z)
            zombies.push_back(z);
    }
	delete z;

    return zombies;
}

std::list<Plant*> Board::GetAllPlants(Board* aLawn)
{
    std::list<Plant*> Plants;

    Plant* p = nullptr;
    while (aLawn->mPlants.Next(&p))
    {
        if (p)
            Plants.push_back(p);
    }
	delete p;

    return Plants;
}