/* ==================================================================== */
/* Allan CORNET - 2010-2012 */
/* ==================================================================== */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "pa_callback_play.h"
/* ==================================================================== */
int paPlayCallback( const void *inputBuffer, void *outputBuffer,
  unsigned long framesPerBuffer,
  const PaStreamCallbackTimeInfo* timeInfo,
  PaStreamCallbackFlags statusFlags,
  void *userData )
{
  int offset = 0;
  unsigned int i = 0;
  int c = 0;
  paWavDataPlay *data = (paWavDataPlay*) userData;

  SAMPLE *out = (SAMPLE *)outputBuffer;
  SAMPLE *in = (SAMPLE *)inputBuffer;

  (void) timeInfo;

  if (data->bufchannels > 0) offset = data->buflen / data->bufchannels;

  // for each frame
  for(i = 0; i<framesPerBuffer; i++ )
  {
    // for each output channel
    for (c = 0; c < data->bufchannels; c++)
    {
      // if we're not at the end of the buffer
      if (data->bufpos < (data->buflen / data->bufchannels))
      {
        SAMPLE val = 0.;
        SAMPLE  *valptr = (data->buffer + data->bufpos);

        valptr = valptr + (c * offset); // add offset for this channel
        val = *valptr;
        *out = val;
        out++;
      }
      else
      {
        *out++ = 0;
      }
    }
    data->bufpos++; // advance to next pos
  }

  if (data->bufpos >= (data->buflen / data->bufchannels))
  {
    return 1; // return of non-zero signals stream end
  }
  return 0;
}
/* ==================================================================== */
