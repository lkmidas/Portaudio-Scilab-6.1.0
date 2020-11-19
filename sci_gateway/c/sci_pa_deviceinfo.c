/* ==================================================================== */
/* Allan CORNET - 2010-2012 */
/* ==================================================================== */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "api_scilab.h"
#include "Scierror.h"
#include "pa_deviceinfo.h"
#include "MALLOC.h"
#include "freeArrayOfString.h"
#include "localization.h"
/* ==================================================================== */
int sci_pa_deviceinfo(char *fname, void* pvApiCtx)
{
  int sizeArray = 0;

  CheckRhs(0, 0);
  CheckLhs(1, 8);

  if (Lhs >= 1)
  {
    int sizeArray = 0;
    char **names = getDeviceInfoName(&sizeArray);
    if (names)
    {
      int i = 0;
      int m_out = sizeArray;
      int n_out = 1;
      SciErr sciErr = createMatrixOfString(pvApiCtx, Rhs + 1, m_out, n_out, names);
      freeArrayOfString(names, sizeArray);
      if(sciErr.iErr)
      {
        printError(&sciErr, 0);
        Scierror(999,_("%s: Memory allocation error.\n"), fname);
        return 0;
      }
    }
    else
    {
      createEmptyMatrix(pvApiCtx, Rhs + 1);
    }
    LhsVar(1) = Rhs + 1;
  }

  if (Lhs >= 2)
  {
    double *samplesrate = getDeviceInfoDefaultSampleRate(&sizeArray);
    if (samplesrate)
    {
      int m_out = sizeArray;
      int n_out = 1;
      SciErr sciErr = createMatrixOfDouble(pvApiCtx, Rhs + 2, m_out, n_out, samplesrate);
      FREE(samplesrate);
      samplesrate = NULL;
      if(sciErr.iErr)
      {
        printError(&sciErr, 0);
        Scierror(999,_("%s: Memory allocation error.\n"), fname);
        return 0;
      }
    }
    else
    {
      createEmptyMatrix(pvApiCtx, Rhs + 2);
    }
    LhsVar(2) = Rhs + 2;
  }

  if (Lhs >= 3)
  {
    int *maxInputChannels = getDeviceInfoMaxInputChannels(&sizeArray);
    if (maxInputChannels)
    {
      int m_out = sizeArray;
      int n_out = 1;
      SciErr sciErr = createMatrixOfInteger32(pvApiCtx, Rhs + 3, m_out, n_out, maxInputChannels);
      FREE(maxInputChannels);
      maxInputChannels = NULL;
      if(sciErr.iErr)
      {
        printError(&sciErr, 0);
        Scierror(999,_("%s: Memory allocation error.\n"), fname);
        return 0;
      }
    }
    else
    {
      createEmptyMatrix(pvApiCtx, Rhs + 3);
    }
    LhsVar(3) = Rhs + 3;
  }

  if (Lhs >= 4)
  {
    int *maxOutputChannels = getDeviceInfoMaxOutputChannels(&sizeArray);
    if (maxOutputChannels)
    {
      int m_out = sizeArray;
      int n_out = 1;
      SciErr sciErr = createMatrixOfInteger32(pvApiCtx, Rhs + 4, m_out, n_out, maxOutputChannels);
      FREE(maxOutputChannels);
      maxOutputChannels = NULL;
      if(sciErr.iErr)
      {
        printError(&sciErr, 0);
        Scierror(999,_("%s: Memory allocation error.\n"), fname);
        return 0;
      }
    }
    else
    {
      createEmptyMatrix(pvApiCtx, Rhs + 4);
    }

    LhsVar(4) = Rhs + 4;
  }

  if (Lhs >= 5)
  {
    double *defaultLowInputLatency = getDeviceInfoDefaultLowInputLatency(&sizeArray);
    if (defaultLowInputLatency)
    {
      int m_out = sizeArray;
      int n_out = 1;
      SciErr sciErr = createMatrixOfDouble(pvApiCtx, Rhs + 5, m_out, n_out, defaultLowInputLatency);
      FREE(defaultLowInputLatency);
      defaultLowInputLatency = NULL;
      if(sciErr.iErr)
      {
        printError(&sciErr, 0);
        Scierror(999,_("%s: Memory allocation error.\n"), fname);
        return 0;
      }
    }
    else
    {
      createEmptyMatrix(pvApiCtx, Rhs + 5);
    }

    LhsVar(5) = Rhs + 5;
  }

  if (Lhs >= 6)
  {
    double *defaultLowOutputLatency = getDeviceInfoDefaultLowOutputLatency(&sizeArray);
    if (defaultLowOutputLatency)
    {
      int m_out = sizeArray;
      int n_out = 1;
      SciErr sciErr = createMatrixOfDouble(pvApiCtx, Rhs + 6, m_out, n_out, defaultLowOutputLatency);
      FREE(defaultLowOutputLatency);
      defaultLowOutputLatency = NULL;
      if(sciErr.iErr)
      {
        printError(&sciErr, 0);
        Scierror(999,_("%s: Memory allocation error.\n"), fname);
        return 0;
      }
    }
    else
    {
      createEmptyMatrix(pvApiCtx, Rhs + 6);
    }
    LhsVar(6) = Rhs + 6;
  }

  if (Lhs >= 7)
  {
    double *defaultHighInputLatency = getDeviceInfoDefaultHighInputLatency(&sizeArray);
    if (defaultHighInputLatency)
    {
      int m_out = sizeArray;
      int n_out = 1;
      SciErr sciErr = createMatrixOfDouble(pvApiCtx, Rhs + 7, m_out, n_out, defaultHighInputLatency);
      FREE(defaultHighInputLatency);
      defaultHighInputLatency = NULL;
      if(sciErr.iErr)
      {
        printError(&sciErr, 0);
        Scierror(999,_("%s: Memory allocation error.\n"), fname);
        return 0;
      }
    }
    else
    {
      createEmptyMatrix(pvApiCtx, Rhs + 7);
    }

    LhsVar(7) = Rhs + 7;
  }

  if (Lhs == 8)
  {
    double *defaultHighOutputLatency = getDeviceInfoDefaultHighOutputLatency(&sizeArray);
    if (defaultHighOutputLatency)
    {
      int m_out = sizeArray;
      int n_out = 1;
      SciErr sciErr = createMatrixOfDouble(pvApiCtx, Rhs + 8, m_out, n_out, defaultHighOutputLatency);
      FREE(defaultHighOutputLatency);
      defaultHighOutputLatency = NULL;
      if(sciErr.iErr)
      {
        printError(&sciErr, 0);
        Scierror(999,_("%s: Memory allocation error.\n"), fname);
        return 0;
      }
    }
    else
    {
      createEmptyMatrix(pvApiCtx, Rhs + 8);
    }
    LhsVar(8) = Rhs + 8;
  }

  PutLhsVar();
  return 0;
}
/* ==================================================================== */

