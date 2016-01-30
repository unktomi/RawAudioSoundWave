#include "RawAudioEditorPrivatePCH.h"



#define LOCTEXT_NAMESPACE "AssetTypeActions"


/* FAssetTypeActions_SoundBase overrides
 *****************************************************************************/

bool FRawAudioSoundWaveActions::CanFilter()
{
	return true;
}


uint32 FRawAudioSoundWaveActions::GetCategories()
{
	return EAssetTypeCategories::Sounds;
}


FText FRawAudioSoundWaveActions::GetName() const
{
	return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_RawAudioSoundWave", "Raw Audio Sound Wave");
}


UClass* FRawAudioSoundWaveActions::GetSupportedClass() const
{
	return URawAudioSoundWave::StaticClass();
}


FColor FRawAudioSoundWaveActions::GetTypeColor() const
{
	return FColor(77, 93, 239);
}


bool FRawAudioSoundWaveActions::HasActions ( const TArray<UObject*>& InObjects ) const
{
	return false;
}


#undef LOCTEXT_NAMESPACE
