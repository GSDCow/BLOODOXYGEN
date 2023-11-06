#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_GUN_851.generated.h"

class ACPP_Player; //�O���錾

UCLASS()
class BLOODOXYGEN_API ACPP_GUN_851 : public AActor
{
	GENERATED_BODY()
	
public:	
	ACPP_GUN_851();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	//�v���C���[�̃��t�@�����X�擾
	UPROPERTY()
		ACPP_Player* PlayerRef;
	//���������̏���
	void Shot();
	//�e�̃��b�V����ݒ�
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh", meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* US_GUN_851;
};
