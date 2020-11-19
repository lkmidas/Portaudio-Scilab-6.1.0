/* ==================================================================== */
/* Allan CORNET - 2010-2012 */
/* ==================================================================== */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "MALLOC.h"
#include "api_scilab.h"
#include "pa_deviceinfo.h"
/* ==================================================================== */
int sci_pa_getdevicecount(char *fname, void* pvApiCtx)
{
  CheckRhs(0, 0);
  CheckLhs(1, 1);

  if (!createScalarDouble(pvApiCtx, Rhs + 1, (double)getdevicecount()))
  {
    LhsVar(1) = Rhs + 1;
    PutLhsVar();
  }

  return 0;
}
/* ==================================================================== */
