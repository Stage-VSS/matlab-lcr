#include "lcr.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if (nrhs < 0 || nrhs > 0)
    {
        mexErrMsgIdAndTxt("lcr:usage", "Usage: [red, green, blue] = lcrGetLedCurrents()");
        return;
    }
    
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    int result = LCR_GetLedCurrents(&red, &green, &blue);
    if (result == -1)
    {
        mexErrMsgIdAndTxt("lcr:failedToGetLedCurrents", "Failed to get LED currents");
        return;
    }
    
    plhs[0] = mxCreateDoubleScalar(red);
    plhs[1] = mxCreateDoubleScalar(green);
    plhs[2] = mxCreateDoubleScalar(blue);
}