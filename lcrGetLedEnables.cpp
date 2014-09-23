#include "lcr.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if (nrhs < 0 || nrhs > 0)
    {
        mexErrMsgIdAndTxt("lcr:usage", "Usage: [auto, red, green, blue] = lcrGetLedEnables()");
        return;
    }
    
	bool seqCtrl;
    bool red;
    bool green;
    bool blue;
    int result = LCR_GetLedEnables(&seqCtrl, &red, &green, &blue);
    if (result == -1)
    {
        mexErrMsgIdAndTxt("lcr:failedToGetLedEnables", "Failed to get LED enables");
        return;
    }
    
    plhs[0] = mxCreateLogicalScalar(seqCtrl);
    plhs[1] = mxCreateLogicalScalar(red);
    plhs[2] = mxCreateLogicalScalar(green);
	plhs[3] = mxCreateLogicalScalar(blue);
}