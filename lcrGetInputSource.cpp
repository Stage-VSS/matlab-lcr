#include "lcr.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if (nrhs > 0)
    {
        mexErrMsgIdAndTxt("lcr:usage", "Usage: [source, portWidth] = lcrGetInputSource()");
        return;
    }
    
    unsigned int source;
    unsigned int portWidth;
    int result = LCR_GetInputSource(&source, &portWidth);
    if (result == -1)
    {
        mexErrMsgIdAndTxt("lcr:failedToGetInputSource", "Failed to get input source");
        return;
    }
    
    plhs[0] = mxCreateDoubleScalar(source);
    plhs[1] = mxCreateDoubleScalar(portWidth);
}