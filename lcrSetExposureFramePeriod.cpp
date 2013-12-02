#include "lcr.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if (nrhs < 2 || nrhs > 2)
    {
        mexErrMsgIdAndTxt("lcr:usage", "Usage: lcrSetExposureFramePeriod(exposurePeriod, framePeriod)");
        return;
    }
    
    double exposurePeriod = mxGetScalar(prhs[0]);
    double framePeriod = mxGetScalar(prhs[1]);
    
    int result = LCR_SetExposure_FramePeriod(exposurePeriod, framePeriod);
    if (result < 0)
    {
        mexErrMsgIdAndTxt("lcr:failedToSetExposureFramePeriod", "Failed to set exposure/frame period");
        return;
    }
}