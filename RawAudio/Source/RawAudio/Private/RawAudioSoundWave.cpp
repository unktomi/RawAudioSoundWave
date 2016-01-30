#include "RawAudioPrivatePCH.h"
#include "Engine.h"
#include "RawAudioSoundWave.h"
#include "ActiveSound.h"


/* UMediaSoundWave structors
 *****************************************************************************/

URawAudioSoundWave::URawAudioSoundWave( const FObjectInitializer& ObjectInitializer )
	: Super(ObjectInitializer)
{
	bSetupDelegates = false;
	bLooping = false;
	bProcedural = true;
	Duration = INDEFINITELY_LOOPING_DURATION;
}

/* UMediaSoundWave interface
 *****************************************************************************/


/* USoundWave overrides
 *****************************************************************************/
void URawAudioSoundWave::Parse(class FAudioDevice* AudioDevice, const UPTRINT NodeWaveInstanceHash, FActiveSound& ActiveSound, const FSoundParseParameters& ParseParams, TArray<FWaveInstance*>& WaveInstances)
{
	Super::Parse(AudioDevice, NodeWaveInstanceHash, ActiveSound, ParseParams, WaveInstances);
	FWaveInstance* WaveInstance = ActiveSound.FindWaveInstance(NodeWaveInstanceHash);
	if (WaveInstance) {
		// Hack
		//bPassiveMixEnabled = QueuedAudio.Num() > 0;
	}
}

int32 URawAudioSoundWave::GeneratePCMData( uint8* PCMData, const int32 SamplesNeeded )
{

	// get requested samples
	if (SamplesNeeded <= 0)
	{
		return 0;
	}

	const int32 SamplesAvailable = QueuedAudio.Num() / sizeof(int16);
	const int32 BytesToCopy = FMath::Min<int32>(SamplesNeeded, SamplesAvailable) * sizeof(int16);

	if (BytesToCopy > 0)
	{
		FMemory::Memcpy((void*)PCMData, &QueuedAudio[0], BytesToCopy);
		QueuedAudio.RemoveAt(0, BytesToCopy);
	}

	return BytesToCopy;
}

void URawAudioSoundWave::EnqueuePCMData(const uint8* Data, const int32 Size)
{
	QueuedAudio.Append(Data, Size);
}


FByteBulkData* URawAudioSoundWave::GetCompressedData( FName Format )
{
	return nullptr;
}


int32 URawAudioSoundWave::GetResourceSizeForFormat( FName Format )
{
	return 0;
}


void URawAudioSoundWave::InitAudioResource( FByteBulkData& CompressedData )
{
	check(false); // should never be pushing compressed data to this class
}


bool URawAudioSoundWave::InitAudioResource( FName Format )
{
	return true;
}


/* UObject overrides
 *****************************************************************************/

void URawAudioSoundWave::GetAssetRegistryTags( TArray<FAssetRegistryTag>& OutTags ) const
{
}


SIZE_T URawAudioSoundWave::GetResourceSize(EResourceSizeMode::Type Mode)
{
	return 0;
}


void URawAudioSoundWave::Serialize( FArchive& Ar )
{
	// do not call the USoundWave version of serialize
	USoundBase::Serialize(Ar);
}

void URawAudioSoundWave::PostLoad()
{
	Super::PostLoad();

	if (!HasAnyFlags(RF_ClassDefaultObject) && !GIsBuildMachine)
	{
		  //InitializeTrack();
	}
}

void URawAudioSoundWave::BeginDestroy()
{
	Super::BeginDestroy();
}



