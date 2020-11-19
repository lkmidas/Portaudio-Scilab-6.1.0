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
int sci_pa_getversiontext(char *fname, void* pvApiCtx)
{
  char *text = NULL;

  CheckRhs(0, 0);
  CheckLhs(0, 1);

  text = getversiontxt();
  if (text)
  {
    int ierr = createSingleString(pvApiCtx, Rhs + 1, text);
    FREE(text);
    text = NULL;
    if (ierr != 0)
    {
      Scierror(999,_("%s: Memory allocation error.\n"), fname);
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
