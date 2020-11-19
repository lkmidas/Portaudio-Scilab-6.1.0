/* ==================================================================== */
/* Allan CORNET - 2010-2012 */
/* ==================================================================== */
#include <stdlib.h>
#include "pa_callback_record.h"
/* ==================================================================== */
int paRecordCallback( const void *inputBuffer, void *outputBuffer,
  unsigned long framesPerBuffer,
  const PaStreamCallbackTimeInfo* timeInfo,
  PaStreamCallbackFlags statusFlags,
  void *userData)
{
  int recchannelsize =  0;
  int c = 0;
  int i = 0;

  // Cast data passed through stream to my paWavData
  paWavDataRecord *data = (paWavDataRecord*)userData;

  SAMPLE *out = (SAMPLE *)outputBuffer;
  SAMPLE *in = (SAMPLE *)inputBuffer;

  (void) timeInfo; // Prevent unused variable warnings.

  recchannelsize = data->recbuflen / data->nbChannels;

  for (i = 0; i < framesPerBuffer; i++)
  {
    if (in != NULL)
    {
      int c = 0;
      int j = 0;
      for (j = 0; j < data->nbChannels; j++)
      {
        if (data->recbufpos < recchannelsize)
        {
          if (j >= 0)
          {
            SAMPLE *valptr = (data->recbuffer + data->recbufpos);
            valptr = valptr + (c++ * recchannelsize);

            *valptr = *in;
          }

          in++;
        }
      }
      data->recbufpos++;
    }
  }

  if (data->recbufpos >= recchannelsize)
  {
    return 1; // return of non-zero signals stream end
  }
  return 0;
}
/* ==================================================================== */
