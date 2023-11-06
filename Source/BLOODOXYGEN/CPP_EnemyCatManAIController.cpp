// CPP_EnemyCatManAIController.cpp

#include "CPP_EnemyCatManAIController.h"
#include <Kismet/GameplayStatics.h>

ACPP_EnemyCatManAIController::ACPP_EnemyCatManAIController()
{

}

void ACPP_EnemyCatManAIController::BeginPlay()
{
    Super::BeginPlay();

    // �v���C���[�R���g���[���[�ւ̎Q�Ƃ��擾
    PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
}

void ACPP_EnemyCatManAIController::Tick(float DeltaTime)
{
    FVector StartLocation = GetPawn()->GetActorLocation(); // AI�̈ʒu
    FVector EndLocation = PlayerController->GetPawn()->GetActorLocation(); // �v���C���[�̈ʒu

    FHitResult HitResult;

    FCollisionQueryParams CollisionParams;
    CollisionParams.AddIgnoredActor(GetPawn()); // ���C�L���X�g���s��AI�L�����N�^�[�𖳎�

    // ���C�L���X�g�����s
    bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECC_Visibility, CollisionParams);

    // ���C�L���X�g�̏I�_�Ƀf�o�b�O���C����`��i������4�ɐݒ�j
    DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, false, -1, 0, 4);
}