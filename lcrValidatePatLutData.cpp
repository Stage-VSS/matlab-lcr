#include "lcr.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if (nrhs > 0)
    {
        mexErrMsgIdAndTxt("lcr:usage", "Usage: status = lcrValidatePatLutData()");
        return;
    }
    
    unsigned int status;
    int result = DLPC350_ValidatePatLutData(&status);
    if (result == -1)
    {
        mexErrMsgIdAndTxt("lcr:failedToValidatePatLutData", "Failed to validate pattern LUT data");
        return;
    }
    
    plhs[0] = mxCreateDoubleScalar(status);
}