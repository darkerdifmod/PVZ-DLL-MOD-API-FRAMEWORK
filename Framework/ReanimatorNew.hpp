#pragma once
#include "Functions.h"
#include "Original.h"
#include <iostream>
class ReanimationParams
{
public:
    ReanimationType                 mReanimationType;
    const char* mReanimFileName;
    int                             mReanimParamFlags;
};
extern int gReanimationParamArraySize;              //[0x6A9EEC]
extern ReanimationParams* gReanimationParamArray;   //[0x6A9EF0]

/*inline*/ void                     ReanimationFillInMissingData(float& thePrev, float& theValue);
/*inline*/ void                     ReanimationFillInMissingData(void*& thePrev, void*& theValue);
bool                                ReanimationLoadDefinition(const std::string& theFileName, ReanimatorDefinition* theDefinition);
void                                ReanimationFreeDefinition(ReanimatorDefinition* theDefinition);
void _cdecl	                        ReanimatorEnsureDefinitionLoaded(ReanimationType theReanimType, bool theIsPreloading);
void                                ReanimatorLoadDefinitions(ReanimationParams* theReanimationParamArray, int theReanimationParamArraySize);
void                                ReanimatorFreeDefinitions();

extern ReanimationParams gLawnReanimationArray[(int)ReanimationType::NUM_REANIMS];  //0x6A1340

void PatchReanimationArray();