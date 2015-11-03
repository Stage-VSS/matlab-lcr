#include "lcr.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if (nrhs < 4 || nrhs > 4)
    {
        mexErrMsgIdAndTxt("lcr:usage", "Usage: lcrSetLedEnables(seqCtrl, red, green, blue)");
        return;
    }
    
    bool seqCtrl = mxGetScalar(prhs[0]);
    bool red = mxGetScalar(prhs[1]);
    bool green = mxGetScalar(prhs[2]);
    bool blue = mxGetScalar(prhs[3]);
    
    int result = DLPC350_SetLedEnables(seqCtrl, red, green, blue);
    if (result == -1)
    {
        mexErrMsgIdAndTxt("lcr:failedToSetLedEnables", "Failed to set LED enables");
        return;
    }
}