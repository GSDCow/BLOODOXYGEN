#include "CPP_GUN_851.h"
#include "CPP_Player.h"//�v���C���[�C���N���[�h

ACPP_GUN_851::ACPP_GUN_851()
{
	PrimaryActorTick.bCanEverTick = true;
	// ���b�V���R���|�[�l���g�̏�����
	US_GUN_851 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("US_GUN_851"));
	// ���b�V�������̃A�N�^�[��RootComponent�Ƃ��Đݒ�
	RootComponent = US_GUN_851;
}

void ACPP_GUN_851::BeginPlay()
{
	Super::BeginPlay();
	//�v���C���[���擾
}

void ACPP_GUN_851::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

//�e�Ō��������̏���
void ACPP_GUN_851::Shot()
{

}