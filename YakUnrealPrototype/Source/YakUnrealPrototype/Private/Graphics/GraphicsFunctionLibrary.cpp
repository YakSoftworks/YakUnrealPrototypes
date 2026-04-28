// Fill out your copyright notice in the Description page of Project Settings.


#include "Graphics/GraphicsFunctionLibrary.h"

FVector UGraphicsFunctionLibrary::GetKubelkaInfiniteReflectance(FVector S, FVector K)
{

	FVector Result;

	Result.X = 1 + (K.X/S.X) - FMath::Sqrt(FMath::Pow(K.X/S.X, 2)+(2*(K.X/S.X) ));
	Result.Y = 1 + (K.Y/S.Y) - FMath::Sqrt(FMath::Pow(K.Y/S.Y, 2)+(2*(K.Y/S.Y) ));
	Result.Z = 1 + (K.Z/S.Z) - FMath::Sqrt(FMath::Pow(K.Z/S.Z, 2)+(2*(K.Z/S.Z) ));
	
	return Result;
	
}
