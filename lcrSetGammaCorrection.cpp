#include "lcr.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if (nrhs < 2 || nrhs > 2)
    {
        mexErrMsgIdAndTxt("lcr:usage", "Usage: lcrSetGammaCorrection(table, enable)");
        return;
    }
    
    unsigned char table = mxGetScalar(prhs[0]);
    bool enable = mxGetScalar(prhs[1]);
    
    int result = LCR_SetGammaCorrection(table, enable);
    if (result < 0)
    {
        mexErrMsgIdAndTxt("lcr:failedToSetGammaCorrection", "Failed to set gamma correction");
        return;
    }
}