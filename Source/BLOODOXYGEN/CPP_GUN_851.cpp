#include "CPP_GUN_851.h"
#include "CPP_Player.h"//�v���C���[�C���N���[�h
#include <Kismet/GameplayStatics.h>
#include "GameFramework/PlayerController.h"
#include "Camera/CameraComponent.h"

ACPP_GUN_851::ACPP_GUN_851()
{
	PrimaryActorTick.bCanEverTick = true;
	// ���b�V���R���|�[�l���g�̏�����
	US_GUN_851 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("US_GUN_851"));
	// ���b�V�������̃A�N�^�[��RootComponent�Ƃ��Đݒ�
	RootComponent = US_GUN_851;
	MaxRayDistance = 1000;
}

void ACPP_GUN_851::BeginPlay()
{
	Super::BeginPlay();

	// �v���C���[�N���X�̃C���X�^���X�ւ̃|�C���^���擾
	PlayerRef = Cast<ACPP_Player>(UGameplayStatics::GetPlayerController(this, 0)->GetPawn());
}

void ACPP_GUN_851::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

//�e�Ō��������̏���
void ACPP_GUN_851::Shot()
{
	// ACPP_Player��IN_Fire()���Ăяo��
	if (PlayerRef) { PlayerRef->IN_Fire(true); };
	// �v���C���[�R���g���[���[���擾
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);

	if (PlayerController)
	{
		// �v���C���[�R���g���[���[����J�����R���|�[�l���g���擾
		UCameraComponent* PlayerCamera = PlayerController->FindComponentByClass<UCameraComponent>();

		if (PlayerCamera)
		{
			// �J�����R���|�[�l���g�����ʂ̒����̈ʒu�Ǝ����������擾
			FVector CameraLocation;
			FRotator CameraRotation;
			PlayerController->GetPlayerViewPoint(CameraLocation, CameraRotation);
			FVector CameraForwardVector = CameraRotation.Vector();

			// ���C���쐬���Ĕ�΂�
			FVector StartLocation = CameraLocation; // �J�����ʒu���n�_
			FVector EndLocation = StartLocation + (CameraForwardVector * MaxRayDistance); // MaxRayDistance�͓K�؂ȋ����ɐݒ�
			FHitResult HitResult;

			FCollisionQueryParams CollisionParams;
			CollisionParams.AddIgnoredActor(this);

			// ���C�L���X�g�����s
			bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECC_Visibility, CollisionParams);

			if (bHit)
			{
				// ���C�������ɓ��������ꍇ�̏���
				AActor* HitActor = HitResult.GetActor();
				// ���C�̃f�o�b�O���C����\��
				DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Green, false, 1, 0, 1);

			}
		}
	}
}