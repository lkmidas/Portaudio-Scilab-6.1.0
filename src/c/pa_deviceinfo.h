/* ==================================================================== */
/* Allan CORNET - 2010-2012 */
/* ==================================================================== */

#ifndef __PA_DEVICEINFO_H__
#define __PA_DEVICEINFO_H__

char **getDeviceInfoName(int *sizeArrayReturned);

int * getDeviceInfoMaxInputChannels(int *sizeArrayReturned);

int * getDeviceInfoMaxOutputChannels(int *sizeArrayReturned);

double *getDeviceInfoDefaultLowInputLatency(int *sizeArrayReturned);

double *getDeviceInfoDefaultLowOutputLatency(int *sizeArrayReturned);

double *getDeviceInfoDefaultHighInputLatency(int *sizeArrayReturned);

double *getDeviceInfoDefaultHighOutputLatency(int *sizeArrayReturned);

double *getDeviceInfoDefaultSampleRate(int *sizeArrayReturned);

int getDefaultOutputDeviceID(void);

int getDefaultInputDeviceID(void);

int getDefaultOutputSampleRate(void);

int getDefaultInputSampleRate(void);

char *getversiontxt(void);

int getversion(void);

int getdevicecount(void);

#endif /* __PA_DEVICEINFO_H__ */
