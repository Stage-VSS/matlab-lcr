/*
 * usb.h
 *
 * This module has the wrapper functions to access USB driver functions.
 *
 * Copyright (C) 2013 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 *
*/

#ifndef USB_H
#define USB_H

#define USB_MIN_PACKET_SIZE 64
#define USB_MAX_PACKET_SIZE 64

#define MY_VID 0x0451
#define MY_PID 0x6401

#ifdef _WIN32
      #define USB_API_EXPORT __declspec(dllexport)
      #define USB_API_CALL
#else
      #define USB_API_EXPORT /**< API export macro */
      #define USB_API_CALL /**< API call macro */
#endif

int USB_API_EXPORT USB_Open(void);
bool USB_API_EXPORT USB_IsConnected();
int USB_API_EXPORT USB_Write();
int USB_API_EXPORT USB_Read();
int USB_API_EXPORT USB_Close();
int USB_API_EXPORT USB_Init();
int USB_API_EXPORT USB_Exit();

#endif //USB_H
