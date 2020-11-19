/* ==================================================================== */
/* Allan CORNET - 2010-2012 */
/* ==================================================================== */
#include <stdlib.h>
#include "pa_recordwav.h"
#include "pa_callback_record.h"
#include "convertSAMPLE.h"
#include "malloc.h"
/* ==================================================================== */
#define FRAMES_PER_BUFFER 1024
/* ==================================================================== */
double *pa_recordwav(int buflen, int nbChannels, int deviceID,
  int samplerate, PaErrorCode *err)
{
  *err = paBadBufferPtr;
  if (buflen > 0)
  {
    double *bufferReturned = NULL;
    PaStream *stream = NULL;
    PaStreamParameters inputStreamParameters;
    paWavDataRecord wav;
    int Inputbufcols = nbChannels;
    int Inputbufrows = buflen * nbChannels;


    wav.recbuffer = (SAMPLE*)malloc(sizeof(SAMPLE) * (Inputbufcols * Inputbufrows));   // RECORDING audio buffer

    if (wav.recbuffer == NULL)
    {
      *err = paInsufficientMemory;
      return NULL;
    }
    memset(wav.recbuffer, 0, sizeof(wav.recbuffer));

    wav.nbChannels = nbChannels;

    wav.recbufpos = 0;
    wav.recbuflen = buflen;


    *err = paNoError;

    *err = Pa_Initialize();

    if( *err != paNoError )
    {
      return NULL;
    }

    inputStreamParameters.device = deviceID;
    inputStreamParameters.channelCount = nbChannels;
    inputStreamParameters.sampleFormat = paFloat32;
    inputStreamParameters.suggestedLatency = Pa_GetDeviceInfo( deviceID )->defaultLowInputLatency;
    inputStreamParameters.hostApiSpecificStreamInfo = NULL;

    *err = Pa_OpenStream(&stream,
      &inputStreamParameters,
      NULL,
      (double)samplerate,
      FRAMES_PER_BUFFER,
      paClipOff,
      paRecordCallback,
      &wav);

    if(*err != paNoError)
    {
      if (wav.recbuffer)
      {
        free(wav.recbuffer);
        wav.recbuffer = NULL;
      }
      Pa_Terminate();
      return NULL;
    }

    *err = Pa_StartStream(stream);
    if (*err != paNoError)
    {
      if (wav.recbuffer)
      {
        free(wav.recbuffer);
        wav.recbuffer = NULL;
      }
      Pa_Terminate();
      return NULL;
    }

    // sleep while stream's active
    while(( *err = Pa_IsStreamActive( stream ) ) == 1)
    {
      Pa_Sleep(1000);
    }

    *err = Pa_StopStream(stream);
    if (*err != paNoError)
    {
      if (wav.recbuffer)
      {
        free(wav.recbuffer);
        wav.recbuffer = NULL;
      }
      Pa_Terminate();
      return NULL;
    }

    *err = Pa_CloseStream(stream);
    if (*err != paNoError)
    {
      if (wav.recbuffer)
      {
        free(wav.recbuffer);
        wav.recbuffer = NULL;
      }
      Pa_Terminate();
      return NULL;
    }

    Pa_Terminate();

    bufferReturned = convertSampleToDouble(wav.recbuffer, buflen * nbChannels);
    if (wav.recbuffer)
    {
      free(wav.recbuffer);
      wav.recbuffer = NULL;
    }

    return bufferReturned;
  }
  return NULL;
}
/* ==================================================================== */
