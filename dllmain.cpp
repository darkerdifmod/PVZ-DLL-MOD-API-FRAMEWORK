#include <Windows.h>

#include "Functions.h"
#include "Original.h"
#include "Patches.h"
#include "ReanimatorNew.hpp"

void __stdcall Hook(DWORD Address, void* Function)
{
	DWORD OldProt;
	VirtualProtect((LPVOID)Address, 5, PAGE_EXECUTE_READWRITE, &OldProt);

	DWORD Offset = (DWORD)Function - Address - 5;// Relative offset
	*(BYTE*)Address = 0xE9;// Set to jmp
	*(DWORD*)(Address + 1) = Offset;

	DWORD Temp;
	VirtualProtect((LPVOID)Address, 5, OldProt, &Temp);
}

__declspec(naked) Coin* COINADDED()
{
	__asm
	{
		push dword ptr[esp + 16]
		push dword ptr[esp + 16]
		push dword ptr[esp + 16]
		push dword ptr[esp + 16]
		push ecx
		call CoinAdded
		ret 0x10
	}
}

__declspec(naked) void COLLECTCOIN()
{
	__asm
	{
		push ecx
		call CollectCoin
		ret
	}
}

__declspec(naked) void UPDATECOIN()
{
	__asm
	{
		push eax
		call UpdateCoin
		ret
	}
}

__declspec(naked) bool UPDATEAPP()
{
	__asm
	{
		push ecx
		call UpdateApp
		ret
	}
}

__declspec(naked) void LAWNUPDATING()
{
	__asm
	{
		push ebx // Lawn*
		call LawnUpdating
		ret
	}
}

void __declspec(naked) PLANTADDED()
{
	__asm
	{
		pop ebx
		pop ecx
		push eax
		push eax
		call PlantAdded
		pop eax
		ret 0x10
	}
}

void __declspec(naked) PLANTUPDATING()
{
	__asm
	{
		push eax
		call PlantUpdating
		ret
	}
}

void __declspec(naked) ZOMBIEEATING()
{
	__asm
	{
		pop eax// Return addr
		pop edx// Zombie*
		push ecx// Plant*
		push edx// Zombie*
		push eax// Return addr
		jmp ZombieEating
	}
}

CONST DWORD _F0 = 0x463E49;
__declspec(naked) void __stdcall Original::PlantUpdate(Plant*)
{
	__asm
	{
		pop ecx// Return addr
		pop eax// Plant*
		push ecx// Return addr

		push ebx
		mov ebx, eax
		mov dl, byte ptr [ebx + 0x144]
		jmp _F0
	}
}

CONST DWORD _F1 = 0x465A96;
__declspec(naked) void __stdcall Original::PlantDraw(Plant*, Sexy::Graphics*)
{
	__asm
	{
		push ebp
		mov ebp, esp
		and esp, 0xFFFFFFF8
		jmp _F1
	}
}

CONST DWORD _F2 = 0x466E08;
__declspec(naked) void __stdcall Original::PlantShoot(Plant*, Zombie*, int, bool)
{
	__asm
	{
		sub esp, 0x1C
		push ebx
		mov ebx, [esp + 0x30]
		jmp _F2
	}
}

CONST DWORD _F3 = 0x52FB47;
__declspec(naked) void __stdcall Original::BitePlant(Zombie*, Plant*)
{
	__asm
	{
		pop edx // Return addr
		pop eax // Zombie*
		pop ecx // Plant*
		push eax // Zombie*
		push edx // Return addr

		push -1
		push 0x64F598
		jmp _F3
	}
}

CONST DWORD _F4 = 0x452CB7;
__declspec(naked) void ONLOAD()
{
	__asm
	{
		push ecx
		push ecx
		call GameLoaded
		pop ecx
		
		push -1
		push 0x64F348
		jmp _F4
	}
}

__declspec(naked) void ONNEWZOMB()
{
	__asm
	{
		push eax
		push eax
		call ZombieAdded
		pop eax
		ret 0x8
	}
}

__declspec(naked) void ZOMBUPDATE()
{
	__asm
	{
		push eax
		call ZombieUpdating
		ret
	}
}

__declspec(naked) void ZOMBDRAW()
{
	__asm
	{
		push [esp + 0x4]
		push ebx
		call ZombieDrawing
		ret 0x4
	}
}

__declspec(naked) void NEWPROJ()
{
	__asm
	{
		push eax
		push eax
		call ProjectileAdded
		pop eax
		ret 0x14
	}
}

__declspec(naked) void PROJUPD()
{
	__asm
	{
		push eax
		call ProjectileUpdating
		ret
	}
}

__declspec(naked) void PROJCOLL()
{
	__asm
	{
		push eax
		push ecx
		call ProjectileColliding
		ret
	}
}

CONST DWORD _F5 = 0x46E006;
__declspec(naked) void __stdcall Original::ProjectileCollide(Projectile*, Zombie*)
{
	__asm
	{
		pop edx// Ret
		pop ecx
		pop eax
		push edx
		sub esp, 0x14
		push ebx
		push ebp
		push esi
		jmp _F5
	}
}

CONST DWORD _F6 = 0x46E546;
__declspec(naked) void __stdcall Original::ProjectileDraw(Projectile*, Sexy::Graphics*)
{
	__asm
	{
		push ebp
		mov ebp, esp
		and esp, -0x8
		jmp _F6
	}
}

CONST DWORD _F7 = 0x46E468;
__declspec(naked) void __stdcall Original::ProjectileUpdate(Projectile*)
{
	__asm
	{
		pop edx// Ret
		pop eax// this*
		push edx
		push ecx
		push esi
		mov esi, eax
		add [esi + 0x60], 01
		jmp _F7
	}
}

CONST DWORD _F8 = 0x52E2E6;
__declspec(naked) void __stdcall Original::ZombieDraw(Zombie*, Sexy::Graphics*)
{
	__asm
	{
		push ebx
		push [esp + 0xC]
		mov ebx, [esp + 0xC]
		mov eax, fs: [00000000]
		call _F8
		pop ebx
		ret 0x8
	}
}

CONST DWORD _F9 = 0x52AE66;
__declspec(naked) void __stdcall Original::ZombieUpdate(Zombie*)
{
	__asm
	{
		pop edx// Ret
		pop eax// this*
		push edx

		push ebp
		mov ebp, esp
		and esp, -0x8
		jmp _F9
	}
}

CONST DWORD _F10 = 0x40AF96;
__declspec(naked) void __stdcall Original::LawnInitLevel(Board*)
{
	__asm
	{
		push ebx
		push ebp
		mov ebp, dword ptr[esp + 0xC]
		jmp _F10
	}
}

CONST DWORD _F11 = 0x4130D5;
__declspec(naked) void __stdcall Original::LawnUpdate(Board*)
{
	__asm
	{
		push ebx // save the caller's ebx, since the game function needs ebx = Lawn*
		mov ebx, [esp + 8] // Lawn* argument
		call Tramp // return here after the original function finishes
		pop ebx
		ret 4
	Tramp:
		sub esp, 8 // stolen bytes
		push ebp
		push esi
		jmp _F11
	}
}

CONST DWORD _F_UpdateApp = 0x453A57; // 0x453A50 + 7 stolen bytes
__declspec(naked) bool __stdcall Original::UpdateApp(LawnApp*)
{
	__asm
	{
		mov ecx, dword ptr[esp + 4]
		call Tramp
		ret 0x4
		Tramp:
		cmp byte ptr[ecx + 0x834], 0
			jmp _F_UpdateApp
	}
}

CONST DWORD _F_UpdateCoin = 0x431506; // 0x431500 + 6 stolen bytes
__declspec(naked) void __stdcall Original::UpdateCoin(Coin*)
{
	__asm
	{
		mov eax, dword ptr[esp + 4]
		call Tramp
		ret 0x4
		Tramp:
		sub esp, 0x20
			push ebx
			mov ebx, eax
			jmp _F_UpdateCoin
	}
}

CONST DWORD _F_CollectCoin = 0x430E46; // 0x430E40 + 6 stolen bytes
__declspec(naked) void __stdcall Original::CollectCoin(Coin*)
{
	__asm
	{
		mov ecx, dword ptr[esp + 4]
		call Tramp
		ret 0x4
		Tramp:
		push ebp
			mov ebp, esp
			and esp, 0xfffffff8
			jmp _F_CollectCoin
	}
}

CONST DWORD _F_CoinAdded = 0x40CB16; // 0x40CB10 + 6 stolen bytes
__declspec(naked) Coin* __stdcall Original::CoinAdded(Board*, CoinMotion, CoinType, int, int)
{
	__asm
	{
		mov ecx, dword ptr[esp + 4]
		push dword ptr[esp + 20]
		push dword ptr[esp + 20]
		push dword ptr[esp + 20]
		push dword ptr[esp + 20]
		call Tramp
		ret 0x14
		Tramp:
		push ebp
			mov ebp, esp
			and esp, 0xfffffff8
			jmp _F_CoinAdded
	}
}

BOOL APIENTRY DllMain
(
    HMODULE ModHandle,
    DWORD CallReason,
    LPVOID Reserved
)
{
	if (CallReason != DLL_PROCESS_ATTACH) return TRUE;
#ifdef _DEBUG
	MessageBoxA(NULL, "DEBUG COMPILATION MAY BE BUGGY AND ITS NON SUPPORTED", "ERROR", MB_OK | MB_ICONERROR);
	exit(-1);
#endif // _DEBUG
#ifdef _WIN64
	MessageBoxA(NULL, "PVZ is x32 game please change compilation from x64 to x32","ERROR",MB_OK | MB_ICONERROR);
	exit(-1);
#endif // _DEBUG

	
	// Writes to memory
	DoPatches();
	PatchReanimationArray();

	// Hooks
	Hook(0x452CB0, ONLOAD);
	Hook(0x453A50, UPDATEAPP);

	// Board
	Hook(0x40AF90, LawnInitLevel);
	Hook(0x4130D0, LAWNUPDATING);

	// Plant
	Hook(0x40D19B, PLANTADDED);
	Hook(0x463E40, PLANTUPDATING);
	Hook(0x466E00, PlantShooting);
	Hook(0x465A90, PlantDrawing);

	// Zombie
	Hook(0x52FB40, ZOMBIEEATING);
	Hook(0x52AE60, ZOMBUPDATE);
	Hook(0x40DE90, ONNEWZOMB);
	Hook(0x52E2E0, ZOMBDRAW);

	// Projectile
	Hook(0x40D653, NEWPROJ);
	Hook(0x46E460, PROJUPD);
	Hook(0x46E000, PROJCOLL);
	Hook(0x46E540, ProjectileDrawing);

	// Coin
	Hook(0x40CB10, COINADDED);
	Hook(0x431500, UPDATECOIN);
	Hook(0x430E40, COLLECTCOIN);
	
	AllocConsole();
	FILE* O = nullptr;
	freopen_s(&O, "CONOUT$", "w", stdout);
	SetConsoleTitleA("dll mod api by csc®");

    return TRUE;
}