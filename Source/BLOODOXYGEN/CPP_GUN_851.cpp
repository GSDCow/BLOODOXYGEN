#include "CPP_GUN_851.h"
#include "CPP_Player.h"//プレイヤーインクルード
#include <Kismet/GameplayStatics.h>
#include "GameFramework/PlayerController.h"
#include "Camera/CameraComponent.h"

ACPP_GUN_851::ACPP_GUN_851()
{
	PrimaryActorTick.bCanEverTick = true;
	// メッシュコンポーネントの初期化
	US_GUN_851 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("US_GUN_851"));
	// メッシュをこのアクターのRootComponentとして設定
	RootComponent = US_GUN_851;
	MaxRayDistance = 1000;
}

void ACPP_GUN_851::BeginPlay()
{
	Super::BeginPlay();

	// プレイヤークラスのインスタンスへのポインタを取得
	PlayerRef = Cast<ACPP_Player>(UGameplayStatics::GetPlayerController(this, 0)->GetPawn());
}

void ACPP_GUN_851::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

//銃で撃った時の処理
void ACPP_GUN_851::Shot()
{
	// ACPP_PlayerのIN_Fire()を呼び出す
	if (PlayerRef) { PlayerRef->IN_Fire(true); };
	// プレイヤーコントローラーを取得
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);

	if (PlayerController)
	{
		// プレイヤーコントローラーからカメラコンポーネントを取得
		UCameraComponent* PlayerCamera = PlayerController->FindComponentByClass<UCameraComponent>();

		if (PlayerCamera)
		{
			// カメラコンポーネントから画面の中央の位置と視線方向を取得
			FVector CameraLocation;
			FRotator CameraRotation;
			PlayerController->GetPlayerViewPoint(CameraLocation, CameraRotation);
			FVector CameraForwardVector = CameraRotation.Vector();

			// レイを作成して飛ばす
			FVector StartLocation = CameraLocation; // カメラ位置が始点
			FVector EndLocation = StartLocation + (CameraForwardVector * MaxRayDistance); // MaxRayDistanceは適切な距離に設定
			FHitResult HitResult;

			FCollisionQueryParams CollisionParams;
			CollisionParams.AddIgnoredActor(this);

			// レイキャストを実行
			bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECC_Visibility, CollisionParams);

			if (bHit)
			{
				// レイが何かに当たった場合の処理
				AActor* HitActor = HitResult.GetActor();
				// レイのデバッグラインを表示
				DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Green, false, 1, 0, 1);

			}
		}
	}
}