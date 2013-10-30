#include "lcr.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	if (nrhs < 1 || nrhs > 1)
	{
		mexErrMsgIdAndTxt("lcr:usage", "Usage: lcrSetPatternDisplayMode(external)");
		return;
	}
	
	bool external = mxGetScalar(prhs[0]);
    
	int result = LCR_SetPatternDisplayMode(external);
    if (result == -1)
    {
        mexErrMsgIdAndTxt("lcr:failedToSetPatternDisplayMode", "Failed to set pattern display mode");
        return;
    }
}