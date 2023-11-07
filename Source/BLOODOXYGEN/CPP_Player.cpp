#include "CPP_Player.h"
#include "Camera/CameraComponent.h"

//�f�t�H���g�l�ݒ�
ACPP_Player::ACPP_Player()
{
	//tick���ĂԂ����߂�
	PrimaryActorTick.bCanEverTick = true;

	//CameraComponent���쐬
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	CameraComponent->SetupAttachment(GetMesh()); //Mesh�̔z��
	CameraComponent->bUsePawnControlRotation = true;
	// GunPositionMesh�̏�����
	US_GunPosition = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GunPositionMesh"));
	US_GunPosition->SetupAttachment(CameraComponent);
	US_GunPosition->SetRelativeLocation(FVector(50, 0, 0));
	//�����l1000
	fBloodOxygen = 1000;
	//�����lfalse
	bIsDead = false;
}

void ACPP_Player::BeginPlay()
{
	Super::BeginPlay();

	//�e���Z�b�g
	SetGunPosition();
}

//Tick����
void ACPP_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//���S��
	IsDead();
	//���Ԍo�߂ɂ���Ď_�f�ቺ
	TimeOxygen();
}

//Input�ݒ�
void ACPP_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//�o�C���h
	PlayerInputComponent->BindAxis("MoveForward", this, &ACPP_Player::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACPP_Player::MoveRight);
	PlayerInputComponent->BindAxis("LookUp", this, &ACPP_Player::LookUp);
	PlayerInputComponent->BindAxis("Turn", this, &ACPP_Player::Turn);
	//�������Ƃ�
	PlayerInputComponent->BindAction("IN_Fire", IE_Pressed, this, &ACPP_Player::IN_Fire);

}

//�㉺�ړ�
void ACPP_Player::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value);
}
//���E�ړ�
void ACPP_Player::MoveRight(float Value)
{
	AddMovementInput(GetActorRightVector(), Value);
}
//���_�c��
void ACPP_Player::LookUp(float Value)
{
	AddControllerPitchInput(-Value);
}
//���_���E
void ACPP_Player::Turn(float Value)
{
	AddControllerYawInput(-Value);
}
//�e������
void ACPP_Player::IN_Fire(bool isFire)
{

}


//���񂾂Ƃ��̏���
void ACPP_Player::IsDead()
{
	if (fBloodOxygen <= 0 && !bIsDead)
	{
		if (GEngine) { GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, TEXT("Player Dead")); }
		bIsDead = true;
	}
}

//���ԂŌ��鏈�� �l�F���b �ő�[200]~�ŏ�[0]
void ACPP_Player::TimeOxygen()
{
	const float DecreaseAmount = 200.0f * GetWorld()->GetDeltaSeconds(); // ���b200��ڎw�����߁ADeltaTime���l��
	fBloodOxygen = FMath::Clamp(fBloodOxygen - DecreaseAmount, 0.0f, fBloodOxygen); // �ŏ�0�A���݂�fBloodOxygen�̊ԂŃN�����v
}

//�e�̈ʒu���Z�b�g
void ACPP_Player::SetGunPosition()
{
	// �e���X�|�[�����AGunPositionMesh�ɃA�^�b�`
	if (TS_HaveGun)
	{
		AActor* SpawnedGun = GetWorld()->SpawnActor<AActor>(TS_HaveGun);
		if (SpawnedGun)
		{
			SpawnedGun->AttachToComponent(US_GunPosition, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
		}
	}
}