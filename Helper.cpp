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

    return zombies;
}

std::vector<Plant*> GetAllPlants(Board* aLawn)
{
    std::vector<Plant*> Plants;

    Plant* z = nullptr;
    while (aLawn->mPlants.Next(&z))
    {
        if (z)
            Plants.push_back(z);
    }

    return Plants;
}