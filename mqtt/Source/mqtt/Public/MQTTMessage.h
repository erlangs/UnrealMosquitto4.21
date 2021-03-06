// Copyright 2019 Warp Studios, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include <mosquittopp.h>

#include "MQTTMessage.generated.h"

USTRUCT(BlueprintType)
struct FUMQTTMessagePayload {
	GENERATED_BODY()

		void* Buffer;
};

/**
 * 
 */
UCLASS(Blueprintable)
class MQTT_API UMQTTMessage : public UObject
{
	GENERATED_BODY()
	
public:
	UMQTTMessage();
	~UMQTTMessage();

	void FromMosquitto(const struct mosquitto_message* message);

	UPROPERTY(BlueprintReadOnly, Category = MQTT)
		FString Topic;

	UPROPERTY(BlueprintReadOnly, Category = MQTT)
		int QOS;

	UPROPERTY(BlueprintReadOnly, Category = MQTT)
		bool Retain;

	UPROPERTY(BlueprintReadOnly, Category = MQTT)
		int PayloadLength;

	UPROPERTY(BlueprintReadOnly, Category = MQTT)
		FUMQTTMessagePayload Payload;

	UFUNCTION(BlueprintCallable, Category = MQTT)
		FString GetPayloadAsString();
	
	
};
