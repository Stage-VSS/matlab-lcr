#include "lcr.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if (nrhs < 1 || nrhs > 1)
    {
        mexErrMsgIdAndTxt("lcr:usage", "Usage: lcrPatternDisplay(action)");
        return;
    }
    
    int action = mxGetScalar(prhs[0]);
    
    int result = LCR_PatternDisplay(action);
    if (result < 0)
    {
        mexErrMsgIdAndTxt("lcr:failedToSetPatternDisplay", "Failed to set pattern display");
        return;
    }
}