#include "lcr.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if (nrhs > 0)
    {
        mexErrMsgIdAndTxt("lcr:usage", "Usage: lcrClearPatLut()");
        return;
    }
    
    int result = LCR_ClearPatLut();
    if (result == -1)
    {
        mexErrMsgIdAndTxt("lcr:failedToClearPatLut", "Failed to clear stored pattern LUT");
        return;
    }
}