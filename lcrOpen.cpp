#include "lcr.h"

void cleanup(void) {
    if (USB_IsConnected())
    {
        USB_Close();
    }
    
    USB_Exit();
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if (nrhs > 0)
    {
        mexErrMsgIdAndTxt("lcr:usage", "Usage: lcrOpen()");
        return;
    }
    
    USB_Init();
    if (USB_IsConnected())
    {
        USB_Close();
    }
    
    USB_Open();
    if (!USB_IsConnected())
    {
        mexErrMsgIdAndTxt("lcr:failedToOpen", "Failed to open");
        return;
    }
    
    mexAtExit(cleanup);
}