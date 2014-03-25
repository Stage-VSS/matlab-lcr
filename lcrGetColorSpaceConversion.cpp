#include "lcr.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if (nrhs > 0)
    {
        mexErrMsgIdAndTxt("lcr:usage", "Usage: [attr, coefficients] = lcrGetColorSpaceConversion()");
        return;
    }
	
    unsigned char attr;
	unsigned short coefficients[9];
    int result = LCR_GetColorSpaceConversion(&attr, coefficients);
    if (result < 0)
    {
        mexErrMsgIdAndTxt("lcr:failedToGetColorSpaceConversion", "Failed to get color space conversion");
        return;
    }
	
    mxArray *matrix = mxCreateNumericMatrix(1, 9, mxUINT16_CLASS, mxREAL);
    unsigned short *pointer = (unsigned short *)mxGetData(matrix);
    for (int i = 0; i < 9; i++)
    {
        pointer[i] = coefficients[i];
    }
	
	plhs[0] = mxCreateDoubleScalar(attr);
	plhs[1] = matrix;
}