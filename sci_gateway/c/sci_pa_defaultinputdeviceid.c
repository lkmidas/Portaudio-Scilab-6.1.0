/* ==================================================================== */
/* Allan CORNET - 2010-2012 */
/* ==================================================================== */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "api_scilab.h"
#include "pa_deviceinfo.h"
#include "localization.h"
/* ==================================================================== */
int sci_pa_defaultinputdeviceid(char *fname, void* pvApiCtx)
{
  CheckRhs(0, 0);
  CheckLhs(0, 1);

  if (createScalarDouble(pvApiCtx, Rhs + 1, getDefaultInputDeviceID()) != 0)
  {
    Scierror(999,_("%s: Memory allocation error.\n"), fname);
    return 0;
  }
  LhsVar(1) = Rhs + 1;
  PutLhsVar();

  return 0;
}
/* ==================================================================== */
