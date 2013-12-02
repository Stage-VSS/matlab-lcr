#include "lcr.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if (nrhs > 0)
    {
        mexErrMsgIdAndTxt("lcr:usage", "Usage: intExtOrVsync = lcrGetPatternTriggerMode()");
        return;
    }
    
    bool intExtOrVsync;
    int result = LCR_GetPatternTriggerMode(&intExtOrVsync);
    if (result == -1)
    {
        mexErrMsgIdAndTxt("lcr:failedToGetPatternTriggerMode", "Failed to get pattern trigger mode");
        return;
    }
    
    plhs[0] = mxCreateLogicalScalar(intExtOrVsync);
}