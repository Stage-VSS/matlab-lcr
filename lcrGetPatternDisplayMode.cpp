#include "lcr.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if (nrhs > 0)
    {
        mexErrMsgIdAndTxt("lcr:usage", "Usage: external = lcrGetPatternDisplayMode()");
        return;
    }
    
    bool external;
    int result = DLPC350_GetPatternDisplayMode(&external);
    if (result == -1)
    {
        mexErrMsgIdAndTxt("lcr:failedToGetPatternDisplayMode", "Failed to get pattern display mode");
        return;
    }
    
    plhs[0] = mxCreateLogicalScalar(external);
}