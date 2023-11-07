#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_Bullet_851.generated.h"

UCLASS()
class BLOODOXYGEN_API ACPP_Bullet_851 : public AActor
{
	GENERATED_BODY()
	
public:	
	ACPP_Bullet_851();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
