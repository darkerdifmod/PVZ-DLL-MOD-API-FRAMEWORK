#pragma once
#include "GameObject.h"
#include "PottedPlant.h"
#include "SexyApp.h"

class Coin : public GameObject
{
#pragma region Fields
public:
	union
	{
		struct
		{
			float mPosX;
			float mPosY;
		};
		Sexy::FVector2 mPos;
	};
	union
	{
		struct
		{
			float mVelX;
			float mVelY;
		};
		Sexy::FVector2 mVel;
	};
	float mScale;
	bool mDead;
	int mFadeCount;
	float mCollectX;
	float mCollectY;
	int mGroundY;
	int mCoinAge;
	bool mIsBeingCollected;
	int mDisappearCounter;
	CoinType mType;
	CoinMotion mCoinMotion;
	AttachmentID mAttachmentID;
	float mCollectionDistance;
	SeedType mUsableSeedType;
	PottedPlant mPottedPlantSpec;
	bool mNeedsBouncyArrow;
	bool mHasBouncyArrow;
	bool mHitGround;
	int mTimesDropped;

#pragma endregion

	void Update();
	void Draw(Sexy::Graphics*);

	Coin(CoinType = PICKUP_NONE);
	void Die();

	void Collect();
};