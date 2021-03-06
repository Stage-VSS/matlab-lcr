#include "lcr.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if (nrhs < 1 || nrhs > 1)
    {
        mexErrMsgIdAndTxt("lcr:usage", "Usage: lcrSetShortAxisImageFlip(flip)");
        return;
    }
    
    bool flip = mxGetScalar(prhs[0]);
    
    int result = DLPC350_SetShortAxisImageFlip(flip);
    if (result < 0)
    {
        mexErrMsgIdAndTxt("lcr:failedToSetShortAxisImageFlip", "Failed to set short axis image flip");
        return;
    }
}