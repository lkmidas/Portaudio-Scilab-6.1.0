/* ==================================================================== */
/* Allan CORNET - 2010-2012 */
/* ==================================================================== */
#ifndef __PA_CALLBACK_RECORD_H__
#define __PA_CALLBACK_RECORD_H__
/* ==================================================================== */
#include <portaudio.h>
/* ==================================================================== */
#ifndef SAMPLE
typedef float SAMPLE;
#endif
/* ==================================================================== */
typedef struct
{
  SAMPLE *recbuffer;   // RECORDING audio buffer

  int nbChannels; // numbers recording channels

  int recbufpos;       // current rec pos in the buffer
  int recbuflen;       // total length of the RECORDING buffer
}
paWavDataRecord;
/* ==================================================================== */
int paRecordCallback( const void *inputBuffer, void *outputBuffer,
  unsigned long framesPerBuffer,
  const PaStreamCallbackTimeInfo* timeInfo,
  PaStreamCallbackFlags statusFlags,
  void *userData);
/* ==================================================================== */
#endif /* __PA_CALLBACK_RECORD_H__ */
/* ==================================================================== */
