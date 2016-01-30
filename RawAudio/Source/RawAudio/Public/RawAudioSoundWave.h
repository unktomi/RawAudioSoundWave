
#pragma once
#include "Engine.h"
#include "Sound/SoundWave.h"
#include "RawAudioSoundWave.generated.h"



/**
 * Implements a playable sound asset for streams of raw pcm data.
 */
UCLASS(BlueprintType)
class RAWAUDIO_API URawAudioSoundWave
	: public USoundWave
{
	GENERATED_UCLASS_BODY()

public:
	virtual void Parse(class FAudioDevice* AudioDevice, const UPTRINT NodeWaveInstanceHash, FActiveSound& ActiveSound, const FSoundParseParameters& ParseParams, TArray<FWaveInstance*>& WaveInstances) override;


	virtual void EnqueuePCMData(const uint8* Data, const int32 Size);

public:

	// USoundWave overrides

	virtual int32 GeneratePCMData(uint8* PCMData, const int32 SamplesNeeded) override;
	virtual FByteBulkData* GetCompressedData(FName Format) override;
	virtual int32 GetResourceSizeForFormat( FName Format ) override;
	virtual void InitAudioResource( FByteBulkData& CompressedData ) override;
	virtual bool InitAudioResource( FName Format ) override;

public:

	// UObject overrides

	virtual void GetAssetRegistryTags( TArray<FAssetRegistryTag>& OutTags ) const override;
	virtual SIZE_T GetResourceSize( EResourceSizeMode::Type Mode ) override;
	virtual void Serialize( FArchive& Ar ) override;
	virtual void PostLoad() override;
	virtual void BeginDestroy() override;

	

public:
	// Notifications from downstream
//virtual void Play() override;
//	virtual void Pause() override;
//	virtual void Stop() override;

protected:

	/** Holds queued audio samples. */
	TArray<uint8> QueuedAudio;

	bool bSetupDelegates;
};
