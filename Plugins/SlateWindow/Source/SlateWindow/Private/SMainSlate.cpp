// Fill out your copyright notice in the Description page of Project Settings.


#include "SMainSlate.h"
#include "SlateOptMacros.h"
#include "Widgets/Layout/SConstraintCanvas.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SMainSlate::Construct(const FArguments& InArgs)
{
	UE_LOG(LogTemp, Log, TEXT("SMainSlate::Construct"));
	ChildSlot
	[
		SNew(SConstraintCanvas)
		+SConstraintCanvas::Slot()
		.Anchors(0.f)
		.Offset(FMargin(20, 12, 600, 72))
		.Alignment(FVector2D(0, 0))
		.AutoSize(false)
		.ZOrder(0)
		[
			SNew(STextBlock)
			.Text(NSLOCTEXT("MainSlate", "SMainSlate_Text_1", "测试Slate 1"))
			.Font(FCoreStyle::GetDefaultFontStyle("Roboto", 53))
			.ColorAndOpacity(FSlateColor(FLinearColor(1, 0, 0.361307, 1)))
		]
		+SConstraintCanvas::Slot()
		.Anchors(0.f)
		.Offset(FMargin(20, 85, 600, 72))
		.Alignment(FVector2D(0, 0))
		.AutoSize(false)
		[
			SNew(STextBlock)
			.Text(NSLOCTEXT("MainSlate", "SMainSlate_Text_2", "测试Slate 2"))
			.Font(FCoreStyle::GetDefaultFontStyle("Roboto", 53))
			.ColorAndOpacity(FSlateColor(FLinearColor(1, 0, 1, 1)))
		]
	]; 
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
