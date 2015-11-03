#include "lcr.h"

void cleanup(void) {
    if (DLPC350_USB_IsConnected())
    {
        DLPC350_USB_Close();
    }

    DLPC350_USB_Exit();
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if (nrhs > 0)
    {
        mexErrMsgIdAndTxt("lcr:usage", "Usage: lcrOpen()");
        return;
    }

    DLPC350_USB_Init();
    if (DLPC350_USB_IsConnected())
    {
        DLPC350_USB_Close();
    }

    DLPC350_USB_Open();
    if (!DLPC350_USB_IsConnected())
    {
        mexErrMsgIdAndTxt("lcr:failedToOpen", "Failed to open");
        return;
    }

    mexAtExit(cleanup);
}
