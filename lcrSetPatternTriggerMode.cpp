#include "lcr.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	if (nrhs < 1 || nrhs > 1)
	{
		mexErrMsgIdAndTxt("lcr:usage", "Usage: lcrSetPatternTriggerMode(intExtOrVsync)");
		return;
	}
	
	bool intExtOrVsync = mxGetScalar(prhs[0]);
    
	int result = LCR_SetPatternTriggerMode(intExtOrVsync);
    if (result == -1)
    {
        mexErrMsgIdAndTxt("lcr:failedToSetPatternTriggerMode", "Failed to set pattern trigger mode");
        return;
    }
}