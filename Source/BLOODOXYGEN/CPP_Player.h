#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CPP_Player.generated.h"

UCLASS()
class BLOODOXYGEN_API ACPP_Player : public ACharacter
{
	GENERATED_BODY()

public:
	//プロパティ
	ACPP_Player();

protected:
	virtual void BeginPlay() override;

private:
	//カメラを設定
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* CameraComponent;
	//銃を設定
	UPROPERTY(EditAnywhere, Category = "Stats")
		TSubclassOf<class AActor> TS_HaveGun;
	//銃の場所
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Stats", meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* US_GunPosition;

public:
	//Tick
	virtual void Tick(float DeltaTime) override;

	//プレイヤーインプット
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//移動
	void MoveForward(float Value);
	void MoveRight(float Value);

	//視点
	void LookUp(float Value);
	void Turn(float Value);

	//発射
	void IN_Fire(bool isFire);

public:
	//血中酸素ゲージ(全てのゲージ）
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite ,Category = "Stats")
		float fBloodOxygen;
	//死んでるか判定
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Stats")
		bool bIsDead;

	//死んでるか判定
	void IsDead();
	//時間で減る処理
	void TimeOxygen();
	//銃を装備
	void SetGunPosition();
};
