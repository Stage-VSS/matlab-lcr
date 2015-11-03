#include "lcr.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if (nrhs < 1 || nrhs > 1)
    {
        mexErrMsgIdAndTxt("lcr:usage", "Usage: [trigType, patNum, bitDepth, ledSelect, invertPat, insertBlack, bufSwap, trigOutPrev] = lcrGetPatLutItem(index)");
        return;
    }
    
    int index = mxGetScalar(prhs[0]);
    
    int trigType;
    int patNum;
    int bitDepth;
    int ledSelect;
    bool invertPat;
    bool insertBlack;
    bool bufSwap;
    bool trigOutPrev;
    int result = DLPC350_GetPatLutItem(index, &trigType, &patNum, &bitDepth, &ledSelect, &invertPat, &insertBlack, &bufSwap, &trigOutPrev);
    if (result == -1)
    {
        mexErrMsgIdAndTxt("lcr:failedToGetPatLutItem", "Failed to get pattern LUT item");
        return;
    }
    
    plhs[0] = mxCreateDoubleScalar(trigType);
    plhs[1] = mxCreateDoubleScalar(patNum);
    plhs[2] = mxCreateDoubleScalar(bitDepth);
    plhs[3] = mxCreateDoubleScalar(ledSelect);
    plhs[4] = mxCreateLogicalScalar(invertPat);
    plhs[5] = mxCreateLogicalScalar(insertBlack);
    plhs[6] = mxCreateLogicalScalar(bufSwap);
    plhs[7] = mxCreateLogicalScalar(trigOutPrev);
}