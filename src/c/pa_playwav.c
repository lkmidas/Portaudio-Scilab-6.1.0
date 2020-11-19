/* ==================================================================== */
/* Allan CORNET - 2010-2012 */
/* ==================================================================== */
#include <portaudio.h>
#include <stdlib.h>
#include "pa_playwav.h"
#include "pa_callback_play.h"
#ifdef _MSC_VER
//#include "strdup_windows.h"
#endif
/* ==================================================================== */
PaErrorCode pa_playwav(SAMPLE *buffer, int buflen, int bufchannels,
  int deviceID, int samplerate)
{
  if (buffer)
  {
    PaStream *stream = NULL;
    PaStreamParameters outputStreamParameters;
    PaError err = paNoError;
    paWavDataPlay wav;

    wav.buffer = buffer;
    wav.bufpos = 0;
    wav.buflen = buflen;
    wav.bufchannels = bufchannels;

    err = Pa_Initialize();

    if( err != paNoError )
    {
      return err;
    }

    // Open an audio I/O stream.
    outputStreamParameters.device = deviceID ;
    outputStreamParameters.channelCount = bufchannels;
    outputStreamParameters.sampleFormat = paFloat32;
    outputStreamParameters.suggestedLatency = Pa_GetDeviceInfo(outputStreamParameters.device)->defaultLowOutputLatency;
    outputStreamParameters.hostApiSpecificStreamInfo = NULL;

    err = Pa_OpenStream(&stream,
      NULL,
      &outputStreamParameters,
      samplerate,
      256,
      paNoFlag,
      paPlayCallback,
      &wav);

    if(err != paNoError)
    {
      Pa_Terminate();
      return err;
    }

    err = Pa_StartStream(stream);
    if (err != paNoError)
    {
      Pa_Terminate();
      return err;
    }

    // sleep while stream's active
    while(( err = Pa_IsStreamActive( stream ) ) == 1)
    {
      Pa_Sleep(50);
    }

    err = Pa_StopStream(stream);
    if (err != paNoError)
    {
      Pa_Terminate();
      return err;
    }

    err = Pa_CloseStream(stream);
    if (err != paNoError)
    {
      Pa_Terminate();
      return err;
    }

    Pa_Terminate();
    return paNoError;
  }
  return paBadBufferPtr;
}
/* ==================================================================== */
char *pa_geterror(PaErrorCode err)
{
  return strdup(Pa_GetErrorText(err));
}
/* ==================================================================== */
