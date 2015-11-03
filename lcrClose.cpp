#include "lcr.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if (nrhs > 0)
    {
        mexErrMsgIdAndTxt("lcr:usage", "Usage: lcrClose()");
        return;
    }

    if (DLPC350_USB_IsConnected())
    {
        DLPC350_USB_Close();
    }

    DLPC350_USB_Exit();
}
