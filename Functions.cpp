#include "Functions.h"
#include "Original.h"
#include <iostream>

// Load resources in this function. Called only once when the game loads.
void __stdcall GameLoaded(LawnApp* App) // LawnAppInit
{
	
}

bool __stdcall UpdateApp(LawnApp* aApp)
{
	auto Result = Original::UpdateApp(aApp); // vanilla behavior
	auto mApp = aApp;
	auto mBoard = mApp->mLawn;


	return Result;// DONT REMOVE AND IT HAS TO BE LAST LANE UN THIS FUNC
}

void __stdcall LawnInitLevel(Board* aBoard)
{
	auto mBoard = aBoard;
	auto mApp = mBoard->mApp;
	Original::LawnInitLevel(aBoard); // vanilla init first
}

void __stdcall LawnUpdating(Board* aBoard)
{
	auto mBoard = aBoard;
	auto mApp = mBoard->mApp;
	Original::LawnUpdate(mBoard); // vanilla update (this also updates plants, zombies, etc.)
}

// Called when a new plant is Planted to the game.
void __stdcall PlantAdded(Plant* aPlant)
{
	auto mBoard = aPlant->mLawn;
	auto mApp = aPlant->mApp;
}

// Called when a plant is updating (once per frame per plant, iterating through all the plants on the board).
void __stdcall PlantUpdating(Plant* aPlant)
{
	auto mBoard = aPlant->mLawn;
	auto mApp = aPlant->mApp;
	Original::PlantUpdate(aPlant);
}

// Called when a plant is being drawn on the screen.
void __stdcall PlantDrawing(Plant* aPlant, Sexy::Graphics* G)
{
	auto mBoard = aPlant->mLawn;
	auto mApp = aPlant->mApp;
	Original::PlantDraw(aPlant, G);
	DrawPlantHealthBar(G, aPlant);
}

// Called when a plant is shooting and should create its projectiles.
void __stdcall PlantShooting(Plant* aPlant, Zombie* Target, int Lane, bool IsSecondary)
{
	auto mBoard = aPlant->mLawn;
	auto mApp = aPlant->mApp;
	Original::PlantShoot(aPlant, Target, Lane, IsSecondary);
}

// Called when a zombie spawns.
void __stdcall ZombieAdded(Zombie* aZombie)
{
	auto mBoard = aZombie->mLawn;
	auto mApp = aZombie->mApp;
}

// Called when a zombie is updating.
void __stdcall ZombieUpdating(Zombie* aZombie)
{
	auto mBoard = aZombie->mLawn;
	auto mApp = aZombie->mApp;
	Original::ZombieUpdate(aZombie);
}

// Called whena  zombie is being drawn.
void __stdcall ZombieDrawing(Zombie* aZombie, Sexy::Graphics* G)
{
	auto mApp = aZombie->mApp;
	Original::ZombieDraw(aZombie, G);
	DrawZombieHealthBar(G, aZombie);
}

// Called when a zombie bites a plant.
void __stdcall ZombieEating(Zombie* aZombie, Plant* BittenPlant)
{
	auto mBoard = aZombie->mLawn;
	auto mApp = aZombie->mApp;
	Original::BitePlant(aZombie, BittenPlant);
}

// Called when a new projectile is created.
void __stdcall ProjectileAdded(Projectile* aProj)
{
	auto mBoard = aProj->mLawn;
	auto mApp = aProj->mApp;
}

// Called when a projectile is updating
void __stdcall ProjectileUpdating(Projectile* aProj)
{
	auto mBoard = aProj->mLawn;
	auto mApp = aProj->mApp;
	Original::ProjectileUpdate(aProj);
}

// Called when a projectile is colliding with a zombie. Zombie could be NULL if it hit the roof.
void __stdcall ProjectileColliding(Projectile* aProj, Zombie* aZombie)
{
	auto mBoard = aProj->mLawn;
	auto mApp = aProj->mApp;
	Original::ProjectileCollide(aProj, aZombie);
}

// Called when a projectile is being drawn.
void __stdcall ProjectileDrawing(Projectile* aProj, Sexy::Graphics* G)
{
	auto mBoard = aProj->mLawn;
	auto mApp = aProj->mApp;
	Original::ProjectileDraw(aProj, G);
}

void __stdcall UpdateCoin(Coin* aCoin)
{
	auto mBoard = aCoin->mLawn;
	auto mApp = aCoin->mApp;
	Original::UpdateCoin(aCoin); // vanilla behavior. Remove this line to replace it completely.
	// your code here
	if (aCoin->mCoinAge == 200) { aCoin->Collect(); };
}

void __stdcall CollectCoin(Coin* aCoin)
{
	auto mBoard = aCoin->mLawn;
	auto mApp = aCoin->mApp;
	Original::CollectCoin(aCoin); // vanilla behavior. Remove this line to replace it completely.
	// your code here
}

Coin* __stdcall CoinAdded(Board* aBoard, CoinMotion aCoinMotion, CoinType aCoinType, int aPosY, int aPosX)
{
	auto aCoin = Original::CoinAdded(aBoard, aCoinMotion, aCoinType, aPosY, aPosX); // vanilla behavior
	auto mBoard = aCoin->mLawn;
	auto mApp = aCoin->mApp;


	return aCoin; // DONT REMOVE AND IT HAS TO BE LAST LANE UN THIS FUNC
}