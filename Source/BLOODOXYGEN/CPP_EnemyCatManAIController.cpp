// CPP_EnemyCatManAIController.cpp

#include "CPP_EnemyCatManAIController.h"
#include <Kismet/GameplayStatics.h>

ACPP_EnemyCatManAIController::ACPP_EnemyCatManAIController()
{

}

void ACPP_EnemyCatManAIController::BeginPlay()
{
    Super::BeginPlay();

    // プレイヤーコントローラーへの参照を取得
    PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
}

void ACPP_EnemyCatManAIController::Tick(float DeltaTime)
{
    FVector StartLocation = GetPawn()->GetActorLocation(); // AIの位置
    FVector EndLocation = PlayerController->GetPawn()->GetActorLocation(); // プレイヤーの位置

    FHitResult HitResult;

    FCollisionQueryParams CollisionParams;
    CollisionParams.AddIgnoredActor(GetPawn()); // レイキャストを行うAIキャラクターを無視

    // レイキャストを実行
    bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECC_Visibility, CollisionParams);

    // レイキャストの終点にデバッグラインを描画（太さを4に設定）
    DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, false, -1, 0, 4);
}