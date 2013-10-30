#include "lcr.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	if (nrhs > 0)
	{
		mexErrMsgIdAndTxt("lcr:usage", "Usage: [exposurePeriod, framePeriod] = lcrGetExposureFramePeriod()");
		return;
	}
    
    unsigned int exposurePeriod;
	unsigned int framePeriod;
    int result = LCR_GetExposure_FramePeriod(&exposurePeriod, &framePeriod);
    if (result == -1)
    {
        mexErrMsgIdAndTxt("lcr:failedToGetExposureFramePeriod", "Failed to get exposure/frame period");
        return;
    }
    
    plhs[0] = mxCreateDoubleScalar(exposurePeriod);
	plhs[1] = mxCreateDoubleScalar(framePeriod);
}