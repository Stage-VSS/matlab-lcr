#include "lcr.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	if (nrhs > 0)
	{
		mexErrMsgIdAndTxt("lcr:usage", "Usage: [numLutEntries, repeat, numPatsForTrigOut2, numSplash] = lcrGetPatternConfig()");
		return;
	}
    
    unsigned int numLutEntries;
	bool repeat;
	unsigned int numPatsForTrigOut2;
	unsigned int numSplash;
    int result = LCR_GetPatternConfig(&numLutEntries, &repeat, &numPatsForTrigOut2, &numSplash);
    if (result == -1)
    {
        mexErrMsgIdAndTxt("lcr:failedToGetPatternConfig", "Failed to get pattern config");
        return;
    }
    
    plhs[0] = mxCreateDoubleScalar(numLutEntries);
	plhs[1] = mxCreateLogicalScalar(repeat);
	plhs[2] = mxCreateDoubleScalar(numPatsForTrigOut2);
	plhs[3] = mxCreateDoubleScalar(numSplash);
}