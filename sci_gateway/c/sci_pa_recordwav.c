/* ==================================================================== */
/* Allan CORNET - 2010-2012 */
/* ==================================================================== */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "MALLOC.h"
#include "api_scilab.h"
#include "pa_recordwav.h"
#include "pa_deviceinfo.h"
#include "localization.h"
#include "Scierror.h"
#include "MALLOC.h"
/* ==================================================================== */
int sci_pa_recordwav(char *fname, void* pvApiCtx)
{
  SciErr sciErr;
  int *piAddressVarOne = NULL;

  int buflen = 0;
  double dbuflen = 0.;
  int nbChannels = 0;
  int deviceID = 0;
  int sampleRate = 0;

  PaErrorCode err =  paNoError;
  double *buffer = NULL;

  CheckRhs(1, 4);
  CheckLhs(1, 1);

  sciErr = getVarAddressFromPosition(pvApiCtx, 1, &piAddressVarOne);
  if(sciErr.iErr)
  {
    Scierror(999, _("%s: Can not read input argument #%d.\n"), fname, 1);
    printError(&sciErr, 0);
    return 0;
  }

  if ( !isDoubleType(pvApiCtx, piAddressVarOne) )
  {
    Scierror(999, _("%s: Wrong type for input argument #%d: A scalar expected.\n"), fname, 1);
    return 0;
  }

  if (!isScalar(pvApiCtx, piAddressVarOne))
  {
    Scierror(999,_("%s: Wrong size for input argument #%d.\n"), fname, 1);
    return 0;
  }

  if (isVarComplex(pvApiCtx, piAddressVarOne))
  {
    Scierror(999,_("%s: Wrong type for input argument #%d: Real scalar expected.\n"), fname, 1);
    return 0;
  }

  if (getScalarDouble(pvApiCtx, piAddressVarOne, &dbuflen))
  {
    Scierror(999, _("%s: No more memory.\n"), fname);
    return 0;
  }

  buflen = (int)dbuflen;

  if (Rhs > 1)
  {
    // samplerate
    double dsampleRate = 0.;
    int *piAddressVarTwo = NULL;
    sciErr = getVarAddressFromPosition(pvApiCtx, 2, &piAddressVarTwo);
    if(sciErr.iErr)
    {
      Scierror(999, _("%s: Can not read input argument #%d.\n"), fname, 2);
      printError(&sciErr, 0);
      return 0;
    }

    if ( !isDoubleType(pvApiCtx, piAddressVarTwo) )
    {
      Scierror(999, _("%s: Wrong type for input argument #%d: A scalar expected.\n"), fname, 2);
      return 0;
    }

    if (!isScalar(pvApiCtx, piAddressVarTwo))
    {
      Scierror(999,_("%s: Wrong size for input argument #%d.\n"), fname, 2);
      return 0;
    }

    if (isVarComplex(pvApiCtx, piAddressVarTwo))
    {
      Scierror(999,_("%s: Wrong type for input argument #%d: Real scalar expected.\n"), fname, 2);
      return 0;
    }

    if ( getScalarDouble(pvApiCtx, piAddressVarTwo, &dsampleRate) )
    {
      Scierror(999, _("%s: No more memory.\n"), fname);
      return 0;
    }

    sampleRate = (int)dsampleRate;
  }
  else
  {
    sampleRate = getDefaultInputSampleRate();
  }

  if (Rhs > 2)
  {
    // nb Channels to record
    double dnbChannels = 0.;
    int *piAddressVarThree = NULL;

    sciErr = getVarAddressFromPosition(pvApiCtx, 3, &piAddressVarThree);
    if(sciErr.iErr)
    {
      Scierror(999, _("%s: Can not read input argument #%d.\n"), fname, 3);
      printError(&sciErr, 0);
      return 0;
    }

    if ( !isDoubleType(pvApiCtx, piAddressVarThree) )
    {
      Scierror(999, _("%s: Wrong type for input argument #%d: A scalar expected.\n"), fname, 3);
      return 0;
    }

    if (!isScalar(pvApiCtx, piAddressVarThree))
    {
      Scierror(999,_("%s: Wrong size for input argument #%d.\n"), fname, 3);
      return 0;
    }

    if (isVarComplex(pvApiCtx, piAddressVarThree))
    {
      Scierror(999,_("%s: Wrong type for input argument #%d: Real scalar expected.\n"), fname, 3);
      return 0;
    }

    if ( getScalarDouble(pvApiCtx, piAddressVarThree, &dnbChannels) )
    {
      Scierror(999, _("%s: No more memory.\n"), fname);
      return 0;
    }

    nbChannels = (int)dnbChannels;
  }
  else
  {
    nbChannels = 2;
  }

  if (Rhs > 3)
  {
    // device Input
    double dDevice = 0.;
    int *piAddressVarFour = NULL;

    sciErr = getVarAddressFromPosition(pvApiCtx, 4, &piAddressVarFour);
    if(sciErr.iErr)
    {
      Scierror(999, _("%s: Can not read input argument #%d.\n"), fname, 4);
      printError(&sciErr, 0);
      return 0;
    }

    if ( !isDoubleType(pvApiCtx, piAddressVarFour) )
    {
      Scierror(999, _("%s: Wrong type for input argument #%d: A scalar expected.\n"), fname, 4);
      return 0;
    }

    if (!isScalar(pvApiCtx, piAddressVarFour))
    {
      Scierror(999,_("%s: Wrong size for input argument #%d.\n"), fname, 4);
      return 0;
    }

    if (isVarComplex(pvApiCtx, piAddressVarFour))
    {
      Scierror(999,_("%s: Wrong type for input argument #%d: Real scalar expected.\n"), fname, 4);
      return 0;
    }

    if ( getScalarDouble(pvApiCtx, piAddressVarFour, &dDevice) )
    {
      Scierror(999, _("%s: No more memory.\n"), fname);
      return 0;
    }

    deviceID = (int)dDevice;
  }
  else
  {
    deviceID = getDefaultInputDeviceID();
  }

  buffer = pa_recordwav(buflen, nbChannels, deviceID, sampleRate, &err);

  if (err != paNoError)
  {
    char *errorText = pa_geterror(err);

    if (buffer)
    {
      FREE(buffer);
      buffer = NULL;
    }

    if (errorText)
    {
      Scierror(999,_("%s: error: \"%s\".\n"), fname, errorText);
      FREE(errorText);
      errorText = NULL;
    }
    else
    {
      Scierror(999,_("%s: unknown error.\n"), fname);
    }
    return 0;
  }

  if (buffer)
  {
    int Inputbufcols = nbChannels;
    int Inputbufrows = buflen ;

    sciErr = createMatrixOfDouble(pvApiCtx, Rhs + 1, Inputbufrows, Inputbufcols, buffer);

    FREE(buffer);
    buffer = NULL;

    if(sciErr.iErr)
    {
      Scierror(999,_("%s: Memory allocation error.\n"), fname);
      printError(&sciErr, 0);
      return 0;
    }
  }
  else
  {
    createEmptyMatrix(pvApiCtx, Rhs + 1);
  }

  LhsVar(1) = Rhs + 1;
  PutLhsVar();

  return 0;
}
/* ==================================================================== */

