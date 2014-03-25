#include "lcr.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if (nrhs > 0)
    {
        mexErrMsgIdAndTxt("lcr:usage", "Usage: [table, enable] = lcrGetGammaCorrection()");
        return;
    }
	
    unsigned char table;
	bool enable;
    int result = LCR_GetGammaCorrection(&table, &enable);
    if (result < 0)
    {
        mexErrMsgIdAndTxt("lcr:failedToGetGammaCorrection", "Failed to get gamma correction");
        return;
    }
	
	plhs[0] = mxCreateDoubleScalar(table);
	plhs[1] = mxCreateLogicalScalar(enable);
}