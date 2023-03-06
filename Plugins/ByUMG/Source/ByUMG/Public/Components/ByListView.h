// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ListView.h"
#include "UnLuaInterface.h"
#include "ByLIstView.generated.h"

UCLASS()
class BYUMG_API ULuaListItem : public UObject, public IUnLuaInterface
{
	GENERATED_BODY()

public:
	virtual FString GetModuleName_Implementation() const override
	{
		return TEXT("LuaItemObject");
	}
};

/**
 * 
 */
UCLASS()
class BYUMG_API UByListView : public UListView
{
	GENERATED_BODY()
};