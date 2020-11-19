/* ==================================================================== */
/* Allan CORNET  - 2010-2012 */
/* ==================================================================== */
#ifndef __PA_CALLBACK_PLAY_H__
#define __PA_CALLBACK_PLAY_H__
/* ==================================================================== */
#include <portaudio.h>
/* ==================================================================== */
#ifndef SAMPLE
typedef float SAMPLE;
#endif
/* ==================================================================== */
typedef struct
{
  SAMPLE *buffer;      // PLAYBACK audio buffer //pdh
  int bufpos;          // current play pos in the buffer
  int buflen;          // total length of the buffer
  int bufchannels;     // number of audio channels
}
paWavDataPlay;
/* ==================================================================== */
int paPlayCallback( const void *inputBuffer, void *outputBuffer,
  unsigned long framesPerBuffer,
  const PaStreamCallbackTimeInfo* timeInfo,
  PaStreamCallbackFlags statusFlags,
  void *userData);
/* ==================================================================== */
#endif /* __PA_CALLBACK_PLAY_H__ */
/* ==================================================================== */
