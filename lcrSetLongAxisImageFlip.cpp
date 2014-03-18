#include "lcr.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if (nrhs < 1 || nrhs > 1)
    {
        mexErrMsgIdAndTxt("lcr:usage", "Usage: lcrSetLongAxisImageFlip(flip)");
        return;
    }
    
    bool flip = mxGetScalar(prhs[0]);
    
    int result = LCR_SetLongAxisImageFlip(flip);
    if (result < 0)
    {
        mexErrMsgIdAndTxt("lcr:failedToSetLongAxisImageFlip", "Failed to set long axis image flip");
        return;
    }
}