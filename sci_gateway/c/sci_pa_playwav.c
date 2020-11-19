/* ==================================================================== */
/* Allan CORNET - 2010-2012 */
/* ==================================================================== */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "api_scilab.h"
#include "Scierror.h"
#include "MALLOC.h"
#include "localization.h"
#include "pa_playwav.h"
#include "convertSAMPLE.h"
#include "pa_deviceinfo.h"
/* ==================================================================== */
int sci_pa_playwav(char *fname, void* pvApiCtx)
{
  int DeviceID = 0;
  int SampleRate = 0;
  double *bufferDouble = NULL;
  SAMPLE *bufferSAMPLE = NULL;
  PaErrorCode err = paNoError;
  int bufferLen = 0;
  int bufferChannels = 0;
  int m_one = 0;
  int n_one = 0;

  SciErr sciErr;
  int *piAddressVarOne = NULL;

  CheckRhs(1, 3);
  CheckLhs(0, 1);

  sciErr = getVarAddressFromPosition(pvApiCtx, 1, &piAddressVarOne);
  if(sciErr.iErr)
  {
    Scierror(999, _("%s: Can not read input argument #%d.\n"), fname, 1);
    printError(&sciErr, 0);
    return 0;
  }

  if ( !isDoubleType(pvApiCtx, piAddressVarOne) )
  {
    Scierror(999, _("%s: Wrong type for input argument #%d: A matrix expected.\n"), fname, 1);
    return 0;
  }

  sciErr = getMatrixOfDouble(pvApiCtx, piAddressVarOne, &m_one, &n_one, &bufferDouble);
  if(sciErr.iErr)
  {
    Scierror(999, _("%s: Can not read input argument #%d.\n"), fname, 1);
    printError(&sciErr, 0);
    return 0;
  }

  if (Rhs > 1)
  {
    double dSampleRate = 0.;
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
      Scierror(999, _("%s: Wrong type for input argument #%d: A matrix expected.\n"), fname, 2);
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

    if ( getScalarDouble(pvApiCtx, piAddressVarTwo, &dSampleRate) )
    {
      Scierror(999, _("%s: No more memory.\n"), fname);
      return 0;
    }

    SampleRate = (int)dSampleRate;
  }
  else
  {
    SampleRate = getDefaultOutputSampleRate();
  }


  if (Rhs > 2)
  {
    double dDeviceID = 0.;
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
      Scierror(999, _("%s: Wrong type for input argument #%d: A matrix expected.\n"), fname, 3);
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

    if ( getScalarDouble(pvApiCtx, piAddressVarThree, &dDeviceID) )
    {
      Scierror(999, _("%s: No more memory.\n"), fname);
      return 0;
    }

    DeviceID = (int)dDeviceID;
  }
  else
  {
    DeviceID = getDefaultOutputDeviceID();
  }


  bufferLen = m_one * n_one;
  bufferChannels = n_one;

  bufferSAMPLE = convertDoubleToSample(bufferDouble, bufferLen);

  err = pa_playwav(bufferSAMPLE, bufferLen, bufferChannels, DeviceID, SampleRate);
  if (bufferSAMPLE)
  {
    FREE(bufferSAMPLE);
    bufferSAMPLE = NULL;
  }

  if (err != paNoError)
  {
    char *errorText = pa_geterror(err);
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
  }
  else
  {
    LhsVar(1) = 0;
    PutLhsVar();
  }
  return 0;
}
/* ==================================================================== */
