#include "MemUtil.h"

namespace MemUtil
{
    bool WriteBytes(uintptr_t address, const void* data, size_t size)
    {
        DWORD oldProtect = 0;
        void* p = reinterpret_cast<void*>(address);

        if (!VirtualProtect(p, size, PAGE_EXECUTE_READWRITE, &oldProtect))
            return false;

        memcpy(p, data, size);

        DWORD dummy = 0;
        VirtualProtect(p, size, oldProtect, &dummy);
        FlushInstructionCache(GetCurrentProcess(), p, size);
        return true;
    }

    bool WriteInt(uintptr_t address, int value)
    {
        return WriteBytes(address, &value, sizeof(value));
    }

    bool WriteJmp(uintptr_t hookAddress, void* destination, size_t totalPatchSize, BYTE* outBackup)
    {
        if (totalPatchSize < 5)
            return false;

        BYTE* target = reinterpret_cast<BYTE*>(hookAddress);

        DWORD oldProtect = 0;
        if (!VirtualProtect(target, totalPatchSize, PAGE_EXECUTE_READWRITE, &oldProtect))
            return false;

        if (outBackup)
            memcpy(outBackup, target, totalPatchSize);

        // E9 rel32 : rel32 = destination - (hookAddress + 5)
        int32_t rel = static_cast<int32_t>(
            reinterpret_cast<intptr_t>(destination) -
            (static_cast<intptr_t>(hookAddress) + 5));

        target[0] = 0xE9;
        memcpy(target + 1, &rel, sizeof(rel));

        for (size_t i = 5; i < totalPatchSize; ++i)
            target[i] = 0x90; // NOP padding

        DWORD dummy = 0;
        VirtualProtect(target, totalPatchSize, oldProtect, &dummy);
        FlushInstructionCache(GetCurrentProcess(), target, totalPatchSize);
        return true;
    }

    bool RestoreBytes(uintptr_t address, const BYTE* backup, size_t size)
    {
        return WriteBytes(address, backup, size);
    }
}