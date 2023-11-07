#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CPP_Player.generated.h"

UCLASS()
class BLOODOXYGEN_API ACPP_Player : public ACharacter
{
	GENERATED_BODY()

public:
	//�v���p�e�B
	ACPP_Player();

protected:
	virtual void BeginPlay() override;

private:
	//�J������ݒ�
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* CameraComponent;
	//�e��ݒ�
	UPROPERTY(EditAnywhere, Category = "Stats")
		TSubclassOf<class AActor> TS_HaveGun;
	//�e�̏ꏊ
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Stats", meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* US_GunPosition;

public:
	//Tick
	virtual void Tick(float DeltaTime) override;

	//�v���C���[�C���v�b�g
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//�ړ�
	void MoveForward(float Value);
	void MoveRight(float Value);

	//���_
	void LookUp(float Value);
	void Turn(float Value);

	//����
	void IN_Fire(bool isFire);

public:
	//�����_�f�Q�[�W(�S�ẴQ�[�W�j
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite ,Category = "Stats")
		float fBloodOxygen;
	//����ł邩����
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Stats")
		bool bIsDead;

	//����ł邩����
	void IsDead();
	//���ԂŌ��鏈��
	void TimeOxygen();
	//�e�𑕔�
	void SetGunPosition();
};
