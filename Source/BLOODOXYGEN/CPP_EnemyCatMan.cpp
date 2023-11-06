#include "CPP_EnemyCatMan.h"


ACPP_EnemyCatMan::ACPP_EnemyCatMan()
{
	PrimaryActorTick.bCanEverTick = true;
	// メッシュコンポーネントを作成
	ECatManMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ECatManMeshComponent"));
	RootComponent = ECatManMeshComponent;
}