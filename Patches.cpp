#include "Functions.h"
#include "Original.h"
#include <iostream>
#include "Patches.h"
#include "MemUtil.h"

void DoPatches()
{
	MemUtil::WriteInt(0x455960,1751783659);
}