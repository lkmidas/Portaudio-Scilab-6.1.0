/* ==================================================================== */
/* Allan CORNET - 2010-2012 */
/* ==================================================================== */
#include <string.h>
#include "convertSAMPLE.h"
#include "malloc.h"
/* ==================================================================== */
SAMPLE* convertDoubleToSample(double *buffer, int buflen)
{
  // Convert to SAMPLEs for playback
  if (buffer && (buflen > 0))
  {
    SAMPLE *myBuf = (SAMPLE*)malloc(sizeof(SAMPLE) * buflen);

    if (myBuf)
    {
      int i = 0;

      memset(myBuf, 0, sizeof(SAMPLE) * buflen);

      for (i = 0; i < buflen; i++)
      {
        myBuf[i] = (SAMPLE)(buffer[i]);
      }
    }
    return myBuf;
  }
  return NULL;
}
/* ==================================================================== */
double* convertSampleToDouble(SAMPLE *buffer, int buflen)
{
  if (buffer && (buflen > 0))
  {
    double *myBuf = (double*)malloc(sizeof(double) * buflen);

    if (myBuf)
    {
      int i = 0;

      memset(myBuf, 0, sizeof(double) * buflen);

      for (i = 0; i < buflen; i++)
      {
        myBuf[i] = (double)(buffer[i]);
      }
    }
    return myBuf;
  }
  return NULL;
}
/* ==================================================================== */
