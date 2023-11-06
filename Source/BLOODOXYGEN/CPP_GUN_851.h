#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_GUN_851.generated.h"

class ACPP_Player; //前方宣言

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

	//プレイヤーのリファレンス取得
	UPROPERTY()
		ACPP_Player* PlayerRef;
	//撃った時の処理
	void Shot();
	//銃のメッシュを設定
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh", meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* US_GUN_851;
};
