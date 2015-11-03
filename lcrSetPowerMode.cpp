#include "lcr.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if (nrhs < 1 || nrhs > 1)
    {
        mexErrMsgIdAndTxt("lcr:usage", "Usage: lcrSetPowerMode(standby)");
        return;
    }
    
    bool standby = mxGetScalar(prhs[0]);
    
    int result = DLPC350_SetPowerMode(standby);
    if (result < 0)
    {
        mexErrMsgIdAndTxt("lcr:failedToSetPowerMode", "Failed to set power mode");
        return;
    }
}