/* ==================================================================== */
/* Allan CORNET - 2010- */
/* ==================================================================== */
#ifndef __PA_RECORDWAV_H__
#define __PA_RECORDWAV_H__

#include <portaudio.h>

double *pa_recordwav(int buflen, int nbChannels, int deviceID,
                     int samplerate, PaErrorCode *err);

#endif /* __PA_RECORDWAV_H__ */
/* ==================================================================== */
