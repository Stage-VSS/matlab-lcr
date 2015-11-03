#include "lcr.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if (nrhs > 0)
    {
        mexErrMsgIdAndTxt("lcr:usage", "Usage: trigMode = lcrGetPatternTriggerMode()");
        return;
    }

    int trigMode;
    int result = DLPC350_GetPatternTriggerMode(&trigMode);
    if (result == -1)
    {
        mexErrMsgIdAndTxt("lcr:failedToGetPatternTriggerMode", "Failed to get pattern trigger mode");
        return;
    }

    plhs[0] = mxCreateDoubleScalar(trigMode);
}
