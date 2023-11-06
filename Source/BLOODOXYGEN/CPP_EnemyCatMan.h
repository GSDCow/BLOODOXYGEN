#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CPP_EnemyCatMan.generated.h"

UCLASS()
class BLOODOXYGEN_API ACPP_EnemyCatMan : public APawn
{
	GENERATED_BODY()

public:
	ACPP_EnemyCatMan();

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* ECatManMeshComponent;
};
