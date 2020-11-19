/* ==================================================================== */
/* Allan CORNET - 2010-2012 */
/* ==================================================================== */
#ifndef __CONVERTSAMPLE_H__
#define __CONVERTSAMPLE_H__

#ifndef SAMPLE
typedef float SAMPLE;
#endif

SAMPLE* convertDoubleToSample(double *buffer, int buflen);

double* convertSampleToDouble(SAMPLE *buffer, int buflen);

#endif /*  __CONVERTSAMPLE_H__ */
/* ==================================================================== */
