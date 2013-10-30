#include "lcr.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	if (nrhs < 2 || nrhs > 2)
	{
		mexErrMsgIdAndTxt("lcr:usage", "Usage: lcrSetInputSource(source, portWidth)");
		return;
	}
	
	unsigned int source = mxGetScalar(prhs[0]);
	unsigned int portWidth = mxGetScalar(prhs[1]);
    
	int result = LCR_SetInputSource(source, portWidth);
    if (result < 0)
    {
        mexErrMsgIdAndTxt("lcr:failedToSetInputSource", "Failed to set input source");
        return;
    }
}