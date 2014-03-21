#include "lcr.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if (nrhs < 3 || nrhs > 3)
    {
        mexErrMsgIdAndTxt("lcr:usage", "Usage: lcrSetLedCurrents(redCurrent, greenCurrent, blueCurrent)");
        return;
    }
    
    unsigned char redCurrent = mxGetScalar(prhs[0]);
    unsigned char greenCurrent = mxGetScalar(prhs[1]);
    unsigned char blueCurrent = mxGetScalar(prhs[2]);
    
    int result = LCR_SetLedCurrents(redCurrent, greenCurrent, blueCurrent);
    if (result == -1)
    {
        mexErrMsgIdAndTxt("lcr:failedToSetLedCurrents", "Failed to set LED currents");
        return;
    }
}