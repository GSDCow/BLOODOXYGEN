#include "CPP_EnemyCatMan.h"


ACPP_EnemyCatMan::ACPP_EnemyCatMan()
{
	PrimaryActorTick.bCanEverTick = true;
	// ���b�V���R���|�[�l���g���쐬
	ECatManMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ECatManMeshComponent"));
	RootComponent = ECatManMeshComponent;
}