#include "lcr.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if (nrhs > 0)
    {
        mexErrMsgIdAndTxt("lcr:usage", "Usage: mode = lcrGetMode()");
        return;
    }
    
    bool mode;
    int result = DLPC350_GetMode(&mode);
    if (result == -1)
    {
        mexErrMsgIdAndTxt("lcr:failedToGetMode", "Failed to get mode");
        return;
    }
    
    plhs[0] = mxCreateLogicalScalar(mode);
}