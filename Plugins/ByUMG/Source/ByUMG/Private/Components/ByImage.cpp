// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/ByImage.h"

void UByImage::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);
}

TSharedRef<SWidget> UByImage::RebuildWidget()
{
	return Super::RebuildWidget();
}
