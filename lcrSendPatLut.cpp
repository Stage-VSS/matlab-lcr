#include "lcr.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	if (nrhs > 0)
	{
		mexErrMsgIdAndTxt("lcr:usage", "Usage: lcrSendPatLut()");
		return;
	}
    
    int result = LCR_SendPatLut();
    if (result == -1)
    {
        mexErrMsgIdAndTxt("lcr:failedToSendPatLut", "Failed to send pattern LUT");
        return;
    }
}