#include "lcr.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if (nrhs < 8 || nrhs > 8)
    {
        mexErrMsgIdAndTxt("lcr:usage", "Usage: lcrAddToPatLut(trigType, patNum, bitDepth, ledSelect, invertPat, insertBlack, bufSwap, trigOutPrev)");
        return;
    }

    int trigType = mxGetScalar(prhs[0]);
    int patNum = mxGetScalar(prhs[1]);
    int bitDepth = mxGetScalar(prhs[2]);
    int ledSelect = mxGetScalar(prhs[3]);
    bool invertPat = mxGetScalar(prhs[4]);
    bool insertBlack = mxGetScalar(prhs[5]);
    bool bufSwap = mxGetScalar(prhs[6]);
    bool trigOutPrev = mxGetScalar(prhs[7]);

    int result = DLPC350_AddToPatLut(trigType, patNum, bitDepth, ledSelect, invertPat, insertBlack, bufSwap, trigOutPrev);
    if (result == -1)
    {
        mexErrMsgIdAndTxt("lcr:failedToAddToPatLut", "Failed to add to pattern LUT");
        return;
    }
}
