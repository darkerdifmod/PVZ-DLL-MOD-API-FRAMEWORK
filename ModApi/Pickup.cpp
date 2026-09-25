#pragma once
#include "ModApi/LawnApp.h"
#include "ModApi/Pickup.h"

CONST DWORD UPDATE = 0x431500;
__declspec(naked) void Coin::Update()
{
	__asm
	{
		mov eax, ecx
		jmp UPDATE
	}
}

CONST DWORD DRAW = 0x431810;
__declspec(naked) void Coin::Draw(Sexy::Graphics*)
{
	__asm
	{
		pop eax// Ret
		push ecx
		push eax
		jmp DRAW
	}
}

Coin::Coin(CoinType T)
{
	mApp = LawnApp::GetApp();
	mLawn = mApp->mLawn;
	mRow = 0;
	mRenderOrder = 400000;
	mVisible = true;
	mDisappearCounter = 1000;
	mType = T;
}

CONST DWORD DIE = 0x432DD0;
__declspec(naked) void Coin::Die()
{
	__asm
	{
		push esi
		mov esi, ecx
		call DIE
		pop esi
		ret
	}
}

CONST DWORD COLLECT = 0x432060;
__declspec(naked) void Coin::Collect()
{
	__asm
	{
		jmp COLLECT
	}
}