#include "lcr.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if (nrhs < 1 || nrhs > 1)
    {
        mexErrMsgIdAndTxt("lcr:usage", "Usage: lcrSetMode(mode)");
        return;
    }
    
    bool mode = mxGetScalar(prhs[0]);
    
    int result = DLPC350_SetMode(mode);
    if (result == -1)
    {
        mexErrMsgIdAndTxt("lcr:failedToSetMode", "Failed to set mode");
        return;
    }
}