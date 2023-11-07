#include "CPP_Player.h"
#include "Camera/CameraComponent.h"

//デフォルト値設定
ACPP_Player::ACPP_Player()
{
	//tickを呼ぶか決める
	PrimaryActorTick.bCanEverTick = true;

	//CameraComponentを作成
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	CameraComponent->SetupAttachment(GetMesh()); //Meshの配下
	CameraComponent->bUsePawnControlRotation = true;
	// GunPositionMeshの初期化
	US_GunPosition = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GunPositionMesh"));
	US_GunPosition->SetupAttachment(CameraComponent);
	US_GunPosition->SetRelativeLocation(FVector(50, 0, 0));
	//初期値1000
	fBloodOxygen = 1000;
	//初期値false
	bIsDead = false;
}

void ACPP_Player::BeginPlay()
{
	Super::BeginPlay();

	//銃をセット
	SetGunPosition();
}

//Tick処理
void ACPP_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//死亡時
	IsDead();
	//時間経過によって酸素低下
	TimeOxygen();
}

//Input設定
void ACPP_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//バインド
	PlayerInputComponent->BindAxis("MoveForward", this, &ACPP_Player::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACPP_Player::MoveRight);
	PlayerInputComponent->BindAxis("LookUp", this, &ACPP_Player::LookUp);
	PlayerInputComponent->BindAxis("Turn", this, &ACPP_Player::Turn);
	//押したとき
	PlayerInputComponent->BindAction("IN_Fire", IE_Pressed, this, &ACPP_Player::IN_Fire);

}

//上下移動
void ACPP_Player::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value);
}
//左右移動
void ACPP_Player::MoveRight(float Value)
{
	AddMovementInput(GetActorRightVector(), Value);
}
//視点縦横
void ACPP_Player::LookUp(float Value)
{
	AddControllerPitchInput(-Value);
}
//視点左右
void ACPP_Player::Turn(float Value)
{
	AddControllerYawInput(-Value);
}
//銃を撃つ
void ACPP_Player::IN_Fire(bool isFire)
{

}


//死んだときの処理
void ACPP_Player::IsDead()
{
	if (fBloodOxygen <= 0 && !bIsDead)
	{
		if (GEngine) { GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, TEXT("Player Dead")); }
		bIsDead = true;
	}
}

//時間で減る処理 値：毎秒 最大[200]~最小[0]
void ACPP_Player::TimeOxygen()
{
	const float DecreaseAmount = 200.0f * GetWorld()->GetDeltaSeconds(); // 毎秒200を目指すため、DeltaTimeを考慮
	fBloodOxygen = FMath::Clamp(fBloodOxygen - DecreaseAmount, 0.0f, fBloodOxygen); // 最小0、現在のfBloodOxygenの間でクランプ
}

//銃の位置をセット
void ACPP_Player::SetGunPosition()
{
	// 銃をスポーンし、GunPositionMeshにアタッチ
	if (TS_HaveGun)
	{
		AActor* SpawnedGun = GetWorld()->SpawnActor<AActor>(TS_HaveGun);
		if (SpawnedGun)
		{
			SpawnedGun->AttachToComponent(US_GunPosition, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
		}
	}
}