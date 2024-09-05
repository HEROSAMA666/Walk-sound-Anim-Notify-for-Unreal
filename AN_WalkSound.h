// Made by Feng Chen aka Peter Feng  :D

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "AN_WalkSound.generated.h"

/**
 * 
 */
UCLASS()
class GLOBALGJ_API UAN_WalkSound : public UAnimNotify
{
	GENERATED_BODY()

public:
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation);//Called when received Anim Notify

	void SoundPlay(USoundBase* Sound,FVector SoundLoc);//Play sound function
	void DebugFunc(int casenum);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AnimNotify, meta = (DisplayName = "PM_1"))
		TObjectPtr<USoundBase> Sound_1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AnimNotify, meta = (DisplayName = "PM_2"))
		TObjectPtr<USoundBase> Sound_2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AnimNotify, meta = (DisplayName = "PM_3"))
		TObjectPtr<USoundBase> Sound_3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AnimNotify, meta = (DisplayName = "PM_4"))
		TObjectPtr<USoundBase> Sound_4;

	//Add sound effect slots above me👆

	FVector PlayerLocation,EndLocation;
	FHitResult HitResult;
	FCollisionQueryParams CollisonQueryParams;

};
