#include "Functions.h"
#include "Original.h"
#include <iostream>

void DrawPlantHealthBar(Sexy::Graphics* g, Plant* aPlant)
{
	if (aPlant->mMaxHealth <= 0 || aPlant->mHealth <= 0)
		return;

	const int BarW = 5;    // thin
	const int BarH = 50;   // tall

	float Frac = (float)aPlant->mHealth / (float)aPlant->mMaxHealth;
	if (Frac > 1.0f) Frac = 1.0f;

	// Left edge of the plant, vertically centered
	int X = 2;
	int Y = (aPlant->mHeight - BarH) / 2;

	// Fill height, at least 1 px while the plant is alive
	int FillH = (int)(BarH * Frac);
	if (FillH < 1) FillH = 1;

	Sexy::Color aOldColor = g->mColor;

	// Border/background
	g->mColor = Sexy::Color(0, 0, 0, 200);
	g->FillRect(X - 1, Y - 1, BarW + 2, BarH + 2);

	// Fill grows from the bottom up: red -> green
	g->mColor = Sexy::Color((int)(255 * (1.0f - Frac)), (int)(255 * Frac), 0, 255);
	g->FillRect(X, Y + BarH - FillH, BarW, FillH);

	g->mColor = aOldColor;
}

static Sexy::Color LerpColor(const Sexy::Color& Low, const Sexy::Color& High, float T)
{
	return Sexy::Color(
		(int)(Low.mRed + (High.mRed - Low.mRed) * T),
		(int)(Low.mGreen + (High.mGreen - Low.mGreen) * T),
		(int)(Low.mBlue + (High.mBlue - Low.mBlue) * T),
		255);
}

static void DrawVerticalBar(Sexy::Graphics* g, int X, int Y, int W, int H, float Frac, const Sexy::Color& FillColor)
{
	if (Frac < 0.0f) Frac = 0.0f;
	if (Frac > 1.0f) Frac = 1.0f;

	int FillH = (int)(H * Frac);
	if (FillH < 1 && Frac > 0.0f) FillH = 1;

	// Border/background
	g->mColor = Sexy::Color(0, 0, 0, 200);
	g->FillRect(X - 1, Y - 1, W + 2, H + 2);

	// Fill grows from the bottom up
	g->mColor = FillColor;
	g->FillRect(X, Y + H - FillH, W, FillH);
}

void DrawZombieHealthBar(Sexy::Graphics* g, Zombie* aZombie)
{
	if (aZombie->mDead || aZombie->mBodyMaxHealth <= 0 || aZombie->mBodyHealth <= 0)
		return;

	const int BarW = 5;
	const int BarH = 60;   // taller than the plant bar

	Sexy::Color aOldColor = g->mColor;

	// Right side of the zombie's body rect, vertically centered
	int X = aZombie->mZobmieW + 2;
	int Y = (aZombie->mZombieH - BarH) / 2;

	// Body health: purple (low) -> orange (full)
	float BodyFrac = (float)aZombie->mBodyHealth / (float)aZombie->mBodyMaxHealth;
	Sexy::Color aBodyColor = LerpColor(Sexy::Color(128, 0, 128), Sexy::Color(255, 165, 0), BodyFrac > 1.0f ? 1.0f : BodyFrac);
	DrawVerticalBar(g, X, Y, BarW, BarH, BodyFrac, aBodyColor);

	// Armor (helmet + shield) as a second, blue-gray bar next to it
	int ArmorMax = aZombie->mHelmMaxHealth + aZombie->mShieldMaxHealth;
	if (ArmorMax > 0)
	{
		int Armor = aZombie->mHelmHealth + aZombie->mShieldHealth;
		if (Armor > 0)
			DrawVerticalBar(g, X + BarW + 3, Y, BarW, BarH, (float)Armor / (float)ArmorMax, Sexy::Color(120, 170, 220, 255));
	}

	g->mColor = aOldColor;
}