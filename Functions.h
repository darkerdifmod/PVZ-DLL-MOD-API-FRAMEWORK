#pragma once
#include "ModApi/ModApi.hpp"

using namespace Sexy;
// Load resources in this function. Called only once when the game is started.
void __stdcall GameLoaded(LawnApp*);
// Game Updating (possibly every tick)
bool __stdcall UpdateApp(LawnApp* aApp);

// Board \\
// Called when a level is initialized.
void __stdcall LawnInitLevel(Board*);

// Called every frame while the level's game objects are updating.
void __stdcall LawnUpdating(Board*);

// Plants \\
// Called when a new plant is added to the game.
void __stdcall PlantAdded(Plant*);
// Called when a plant is updating (once per frame per plant, iterating through all the plants on the board).
void __stdcall PlantUpdating(Plant*);
// Called when a plant is shooting and should create its projectiles.
void __stdcall PlantShooting(Plant* aPlant, Zombie* Target, int Lane, bool IsSecondary);
// Called when a plant is being drawn on the screen.
void __stdcall PlantDrawing(Plant*, Sexy::Graphics*);

// Zombies \\
// Called when a zombie spawns.
void __stdcall ZombieAdded(Zombie*);
// Called when a zombie is updating.
void __stdcall ZombieUpdating(Zombie*);
// Called when a zombie bites a plant.
void __stdcall ZombieEating(Zombie*, Plant*);
// Called whena  zombie is being drawn.
void __stdcall ZombieDrawing(Zombie*, Sexy::Graphics*);

// Projectiles \\
// Called when a new projectile is created.
void __stdcall ProjectileAdded(Projectile*);
// Called when a projectile is updating
void __stdcall ProjectileUpdating(Projectile*);
// Called when a projectile is colliding with a zombie. Zombie could be NULL if it hit the roof.
void __stdcall ProjectileColliding(Projectile*, Zombie*);
// Called when a projectile is being drawn.
void __stdcall ProjectileDrawing(Projectile*, Sexy::Graphics*);

// Hooked at 0x431500. Arguments: aCoin=eax.
void __stdcall UpdateCoin(Coin* aCoin);
// Hooked at 0x430E40. Arguments: aCoin=ecx.
void __stdcall CollectCoin(Coin* aCoin);
// Hooked at 0x40CB10. Arguments: aBoard=ecx, aCoinMotion=stack, aCoinType=stack, aPosY=stack, aPosX=stack.
Coin* __stdcall CoinAdded(Board* aBoard, CoinMotion aCoinMotion, CoinType aCoinType, int aPosY, int aPosX);

void DrawPlantHealthBar(Sexy::Graphics* g, Plant* aPlant);

void DrawZombieHealthBar(Sexy::Graphics* g, Zombie* aZombie);