#include "CPP_GUN_851.h"
#include "CPP_Player.h"//プレイヤーインクルード

ACPP_GUN_851::ACPP_GUN_851()
{
	PrimaryActorTick.bCanEverTick = true;
	// メッシュコンポーネントの初期化
	US_GUN_851 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("US_GUN_851"));
	// メッシュをこのアクターのRootComponentとして設定
	RootComponent = US_GUN_851;
}

void ACPP_GUN_851::BeginPlay()
{
	Super::BeginPlay();
	//プレイヤーを取得
}

void ACPP_GUN_851::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

//銃で撃った時の処理
void ACPP_GUN_851::Shot()
{

}