# RawAudioSoundWave
UE-4 Editor/Runtime Plugin which provides a SoundWave asset to stream raw pcm data

Provides a class <code>URawAudioSoundWave</code> which extends <code>USoundWave</code> and provides the following additional function:

    void EnqueuePCMData(const uint8 *Data, int32 Size);

This function must be called on the main thread. You must also specify the <code>SampleRate</code> and <code>NumChannels</code> fields of <code>USoundWave</code> and format the data accordingly.
