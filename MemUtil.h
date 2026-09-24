#pragma once
//
// MemUtils.h
//
// Small helper layer for writing an E9 (jmp rel32) trampoline hook or a
// handful of raw bytes into another module's code section, with proper
// VirtualProtect handling and instruction-cache flushing.
//
#include <windows.h>
#include <cstdint>
#include <cstddef>

namespace MemUtil
{
    // Overwrites `size` bytes at `address` with `data`.
    // Handles VirtualProtect + FlushInstructionCache internally.
    bool WriteBytes(uintptr_t address, const void* data, size_t size);

    bool WriteInt(uintptr_t address, int value);

    // Writes a 5-byte "jmp rel32" at `hookAddress` pointing at `destination`,
    // then pads the remainder of `totalPatchSize` (>= 5) with NOP (0x90).
    // The bytes originally at `hookAddress` are copied into `outBackup`
    // (must be at least `totalPatchSize` bytes) before they're overwritten,
    // so the hook can be reverted later with RestoreBytes().
    bool WriteJmp(uintptr_t hookAddress,
        void* destination,
        size_t totalPatchSize,
        BYTE* outBackup);

    // Restores bytes previously saved by WriteJmp / WriteBytes.
    bool RestoreBytes(uintptr_t address, const BYTE* backup, size_t size);
}