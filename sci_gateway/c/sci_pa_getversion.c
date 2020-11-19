/* ==================================================================== */
/* Allan CORNET - 2010-2012 */
/* ==================================================================== */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "MALLOC.h"
#include "api_scilab.h"
#include "pa_deviceinfo.h"
#include "localization.h"
/* ==================================================================== */
int sci_pa_getversion(char *fname, void* pvApiCtx)
{
  double ver = 0.;

  CheckRhs(0, 0);
  CheckLhs(0, 1);

  ver = (double)getversion();
  if (createScalarDouble(pvApiCtx, Rhs + 1, ver) != 0)
  {
    Scierror(999,_("%s: Memory allocation error.\n"), fname);
    return 0;
  }
  LhsVar(1) = Rhs + 1;
  PutLhsVar();

  return 0;
}
/* ==================================================================== */
