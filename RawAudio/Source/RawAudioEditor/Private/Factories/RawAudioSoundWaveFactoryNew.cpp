#include "RawAudioEditorPrivatePCH.h"


/* URawAudioSoundWaveFactoryNew structors
 *****************************************************************************/

URawAudioSoundWaveFactoryNew::URawAudioSoundWaveFactoryNew( const FObjectInitializer& ObjectInitializer )
	: Super(ObjectInitializer)
{
	SupportedClass = URawAudioSoundWave::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}


/* UFactory overrides
 *****************************************************************************/

UObject* URawAudioSoundWaveFactoryNew::FactoryCreateNew( UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn )
{
	URawAudioSoundWave* RawAudioSoundWave = NewObject<URawAudioSoundWave>(InParent, InClass, InName, Flags);

	return RawAudioSoundWave;
}


bool URawAudioSoundWaveFactoryNew::ShouldShowInNewMenu() const
{
	return true;
}
