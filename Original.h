#pragma once
#include "ModApi/ModApi.hpp"
// Original functions. Call them to perform the vanilla game behavior. You can add to the vanilla behavior or overwrite it completely.
namespace Original
{
	// Game Update
	bool __stdcall UpdateApp(LawnApp*);

	// The original level init function. Call to initialize the level normally.
	void __stdcall LawnInitLevel(Board*);
	// The original game object update function. Call to update the lawn normally.
	void __stdcall LawnUpdate(Board*);

	// The original plant update function. Call to update the plant normally.
	void __stdcall PlantUpdate(Plant*);
	// The original shooting function. Call to make the plant shoot normally.
	void __stdcall PlantShoot(Plant*, Zombie* Target, int Lane, bool IsSecondaryWeapon);
	// The original plant drawing function. Call to draw the plant normally.
	void __stdcall PlantDraw(Plant*, Sexy::Graphics*);

	// The original zombie update function. Call to update the zombie normally.
	void __stdcall ZombieUpdate(Zombie*);
	// The original plant biting function. Call to make the zombie bite the plant normally.
	void __stdcall BitePlant(Zombie*, Plant*);
	// The original zombie draw function. Call to draw the zombie normally.
	void __stdcall ZombieDraw(Zombie*, Sexy::Graphics*);

	// The original projectile update function. Call to update the projectile normally.
	void __stdcall ProjectileUpdate(Projectile*);
	// The original projectile collision function. Call to make the projectile collide with a zombie normally.
	void __stdcall ProjectileCollide(Projectile*, Zombie*);
	// The original projectile draw function. Call to draw the projectile normally.
	void __stdcall ProjectileDraw(Projectile*, Sexy::Graphics*);

	// The original UpdateCoin function. Call to run the vanilla code.
	void __stdcall UpdateCoin(Coin*);
	// The original CollectCoin function. Call to run the vanilla code.
	void __stdcall CollectCoin(Coin*);
	// The original CoinAdded function. Call to run the vanilla code.
	Coin* __stdcall CoinAdded(Board*, CoinMotion, CoinType, int, int);
}