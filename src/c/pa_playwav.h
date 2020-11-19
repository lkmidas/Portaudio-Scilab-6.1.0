/* ==================================================================== */
/* Allan CORNET - 2010-2012 */
/* ==================================================================== */
#ifndef __PA_PLAYWAVE_H__
#define __PA_PLAYWAVE_H__

#include <portaudio.h>

#ifndef SAMPLE
typedef float SAMPLE;
#endif

PaErrorCode pa_playwav(SAMPLE *buffer, int buflen, int bufchannels,
  int deviceID, int samplerate);

char *pa_geterror(PaErrorCode err);
#endif /* __PA_PLAYWAVE_H__ */
/* ==================================================================== */
