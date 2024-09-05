// Made by Feng Chen aka Peter Feng  :D


#include "AN_WalkSound.h"
#include "Runtime\Engine\Classes\Sound\SoundCue.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Kismet/KismetMathlibrary.h"



void UAN_WalkSound::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	CollisonQueryParams.AddIgnoredActor(MeshComp->GetOwner());
	CollisonQueryParams.bReturnPhysicalMaterial = true;
	CollisonQueryParams.bTraceComplex = true;
	//👆Ray trace settings
	if(GEngine)
	{
		PlayerLocation = MeshComp->GetOwner()->GetActorLocation();
		EndLocation = UKismetMathLibrary::MakeVector(PlayerLocation.X, PlayerLocation.Y, PlayerLocation.Z-100.0f);
		bool bIsHit = GetWorld()->LineTraceSingleByChannel(HitResult,PlayerLocation,EndLocation, ECollisionChannel::ECC_Visibility, CollisonQueryParams);
		//DrawDebugLine(GetWorld(), PlayerLocation, HitResult.GetActor() ? HitResult.Location : EndLocation, FColor::Red, false, 1.0f);
		//👆 Draw debug line
		if(bIsHit)
		{
			switch (HitResult.PhysMaterial->SurfaceType)
			{
			case 0:
				// Empty here since default PM type = 0
				break;
			case 1:
				SoundPlay(Sound_1, HitResult.Location);
				break;
			case 2:
				SoundPlay(Sound_2, HitResult.Location);
				break;
			case 3:
				SoundPlay(Sound_3, HitResult.Location);
				break;
			case 4:
				SoundPlay(Sound_4, HitResult.Location);
				break;
			default:
				break;
			}
			
		}
	}
}
//1.Ray trace to get surface type&sound play location
//2.Play sound at location by using switch phrase

void UAN_WalkSound::SoundPlay(USoundBase* Sound, FVector SoundLoc)
{
	if (Sound) 
	{
		UGameplayStatics::PlaySoundAtLocation(this, Sound, SoundLoc);
	}
}
//Sound output

void UAN_WalkSound::DebugFunc(int casemnum)
{
	GEngine->AddOnScreenDebugMessage(-1,5.0f,FColor::Blue,FString::Printf(TEXT("Case:%d"),casemnum));
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("Surface type:%d"), HitResult.PhysMaterial->SurfaceType));
}
//Debug function used to check the surface type during developing