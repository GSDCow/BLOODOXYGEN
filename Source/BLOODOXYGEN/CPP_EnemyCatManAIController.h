// CPP_EnemyCatManAIController.h

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "CPP_EnemyCatManAIController.generated.h"

UCLASS()
class BLOODOXYGEN_API ACPP_EnemyCatManAIController : public AAIController
{
    GENERATED_BODY()

public:
    ACPP_EnemyCatManAIController();

protected:
    virtual void BeginPlay() override;

public:
    //Tick
    virtual void Tick(float DeltaTime) override;

private:
    APlayerController* PlayerController;

};

