#include "lcr.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if (nrhs > 0)
    {
        mexErrMsgIdAndTxt("lcr:usage", "Usage: lcrClose()");
        return;
    }
    
    if (USB_IsConnected())
    {
        USB_Close();
    }
    
    USB_Exit();
}