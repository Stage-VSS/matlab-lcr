#include "lcr.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if (nrhs > 0)
    {
        mexErrMsgIdAndTxt("lcr:usage", "Usage: [hwStatus, sysStatus, mainStatus] = lcrGetStatus()");
        return;
    }
    
    unsigned char hwStatus;
	unsigned char sysStatus;
	unsigned char mainStatus;
    int result = LCR_GetStatus(&hwStatus, &sysStatus, &mainStatus);
    if (result == -1)
    {
        mexErrMsgIdAndTxt("lcr:failedToGetStatus", "Failed to get status");
        return;
    }
    
    plhs[0] = mxCreateDoubleScalar(hwStatus);
	plhs[1] = mxCreateDoubleScalar(sysStatus);
	plhs[2] = mxCreateDoubleScalar(mainStatus);
}