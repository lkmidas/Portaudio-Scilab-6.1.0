/* ==================================================================== */
/* Allan CORNET - 2010-2012 */
/* ==================================================================== */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <portaudio.h>
#include "pa_deviceinfo.h"
#include "malloc.h"
#ifdef _MSC_VER
//#include "strdup_windows.h"
#endif
/* ==================================================================== */
char **getDeviceInfoName(int *sizeArrayReturned)
{
  int nbDevices = 0;
  char **arrayStringFormat = NULL;

  *sizeArrayReturned = nbDevices;
  Pa_Initialize();

  nbDevices = Pa_GetDeviceCount();
  arrayStringFormat = (char**)malloc(sizeof(char*) * nbDevices);
  if (arrayStringFormat)
  {
    int i = 0;
    for (i = 0; i < nbDevices; i++)
    {
      const PaDeviceInfo *pdi = Pa_GetDeviceInfo(i);
      if (pdi)
      {
        arrayStringFormat[i] = strdup(pdi->name);
      }
      else
      {
        arrayStringFormat[i] = strdup("error");
      }
    }
    *sizeArrayReturned = nbDevices;
  }

  Pa_Terminate();
  return arrayStringFormat;
}
/* ==================================================================== */
int * getDeviceInfoMaxInputChannels(int *sizeArrayReturned)
{
  int nbDevices = 0;
  int *arrayMaxInputChannels = NULL;

  *sizeArrayReturned = nbDevices;
  Pa_Initialize();

  nbDevices = Pa_GetDeviceCount();

  arrayMaxInputChannels = (int*)malloc(sizeof(int) * nbDevices);
  if (arrayMaxInputChannels)
  {
    int i = 0;
    for (i = 0; i < nbDevices; i++)
    {
      const PaDeviceInfo *pdi = Pa_GetDeviceInfo(i);
      if (pdi)
      {
        arrayMaxInputChannels[i] = pdi->maxInputChannels;
      }
      else
      {
        arrayMaxInputChannels[i] = -1;
      }
    }
    *sizeArrayReturned = nbDevices;
  }

  Pa_Terminate();
  return arrayMaxInputChannels;
}
/* ==================================================================== */
int * getDeviceInfoMaxOutputChannels(int *sizeArrayReturned)
{
  int nbDevices = 0;
  int *arrayMaxOutputChannels = NULL;

  *sizeArrayReturned = nbDevices;
  Pa_Initialize();

  nbDevices = Pa_GetDeviceCount();

  arrayMaxOutputChannels = (int*)malloc(sizeof(int) * nbDevices);
  if (arrayMaxOutputChannels)
  {
    int i = 0;
    for (i = 0; i < nbDevices; i++)
    {
      const PaDeviceInfo *pdi = Pa_GetDeviceInfo(i);
      if (pdi)
      {
        arrayMaxOutputChannels[i] = pdi->maxOutputChannels;
      }
      else
      {
        arrayMaxOutputChannels[i] = -1;
      }
    }
    *sizeArrayReturned = nbDevices;
  }

  Pa_Terminate();
  return arrayMaxOutputChannels;

}
/* ==================================================================== */
double *getDeviceInfoDefaultLowInputLatency(int *sizeArrayReturned)
{
  int nbDevices = 0;
  double *arrayDefaultLowInputLatency = NULL;

  *sizeArrayReturned = nbDevices;
  Pa_Initialize();

  nbDevices = Pa_GetDeviceCount();
  arrayDefaultLowInputLatency = (double*)malloc(sizeof(double) * nbDevices);

  if (arrayDefaultLowInputLatency)
  {
    int i = 0;
    for (i = 0; i < nbDevices; i++)
    {
      const PaDeviceInfo *pdi = Pa_GetDeviceInfo(i);
      if (pdi)
      {
        arrayDefaultLowInputLatency[i] = pdi->defaultLowInputLatency;
      }
      else
      {
        arrayDefaultLowInputLatency[i] = -1;
      }
    }
    *sizeArrayReturned = nbDevices;
  }

  Pa_Terminate();
  return arrayDefaultLowInputLatency;
}
/* ==================================================================== */
double *getDeviceInfoDefaultLowOutputLatency(int *sizeArrayReturned)
{
  int nbDevices = 0;
  double *arrayDefaultLowOutputLatency = NULL;

  *sizeArrayReturned = nbDevices;
  Pa_Initialize();

  nbDevices = Pa_GetDeviceCount();
  arrayDefaultLowOutputLatency = (double*)malloc(sizeof(double) * nbDevices);

  if (arrayDefaultLowOutputLatency)
  {
    int i = 0;
    for (i = 0; i < nbDevices; i++)
    {
      const PaDeviceInfo *pdi = Pa_GetDeviceInfo(i);
      if (pdi)
      {
        arrayDefaultLowOutputLatency[i] = pdi->defaultLowOutputLatency;
      }
      else
      {
        arrayDefaultLowOutputLatency[i] = -1;
      }
    }
    *sizeArrayReturned = nbDevices;
  }

  Pa_Terminate();
  return arrayDefaultLowOutputLatency;
}
/* ==================================================================== */
double *getDeviceInfoDefaultHighInputLatency(int *sizeArrayReturned)
{
  int nbDevices = 0;
  double *arrayDefaultHighInputLatency = NULL;

  *sizeArrayReturned = nbDevices;
  Pa_Initialize();

  nbDevices = Pa_GetDeviceCount();
  arrayDefaultHighInputLatency = (double*)malloc(sizeof(double) * nbDevices);

  if (arrayDefaultHighInputLatency)
  {
    int i = 0;
    for (i = 0; i < nbDevices; i++)
    {
      const PaDeviceInfo *pdi = Pa_GetDeviceInfo(i);
      if (pdi)
      {
        arrayDefaultHighInputLatency[i] = pdi->defaultHighInputLatency;
      }
      else
      {
        arrayDefaultHighInputLatency[i] = -1;
      }
    }
    *sizeArrayReturned = nbDevices;
  }

  Pa_Terminate();
  return arrayDefaultHighInputLatency;
}
/* ==================================================================== */
double *getDeviceInfoDefaultHighOutputLatency(int *sizeArrayReturned)
{
  int nbDevices = 0;
  double *arrayDefaultHighOutputLatency = NULL;

  *sizeArrayReturned = nbDevices;
  Pa_Initialize();

  nbDevices = Pa_GetDeviceCount();
  arrayDefaultHighOutputLatency = (double*)malloc(sizeof(double) * nbDevices);

  if (arrayDefaultHighOutputLatency)
  {
    int i = 0;
    for (i = 0; i < nbDevices; i++)
    {
      const PaDeviceInfo *pdi = Pa_GetDeviceInfo(i);
      if (pdi)
      {
        arrayDefaultHighOutputLatency[i] = pdi->defaultHighOutputLatency;
      }
      else
      {
        arrayDefaultHighOutputLatency[i] = -1;
      }
    }
    *sizeArrayReturned = nbDevices;
  }

  Pa_Terminate();
  return arrayDefaultHighOutputLatency;
}
/* ==================================================================== */
double *getDeviceInfoDefaultSampleRate(int *sizeArrayReturned)
{
  int nbDevices = 0;
  double *arrayDefaultSampleRate = NULL;

  *sizeArrayReturned = nbDevices;
  Pa_Initialize();

  nbDevices = Pa_GetDeviceCount();
  arrayDefaultSampleRate = (double*)malloc(sizeof(double) * nbDevices);

  if (arrayDefaultSampleRate)
  {
    int i = 0;
    for (i = 0; i < nbDevices; i++)
    {
      const PaDeviceInfo *pdi = Pa_GetDeviceInfo(i);
      if (pdi)
      {
        arrayDefaultSampleRate[i] = pdi->defaultSampleRate;
      }
      else
      {
        arrayDefaultSampleRate[i] = -1;
      }
    }
    *sizeArrayReturned = nbDevices;
  }

  Pa_Terminate();
  return arrayDefaultSampleRate;
}
/* ==================================================================== */
int getDefaultOutputDeviceID(void)
{
  int defaultOutput = 0;

  Pa_Initialize();
  defaultOutput = Pa_GetDefaultOutputDevice();
  Pa_Terminate();

  return defaultOutput;
}
/* ==================================================================== */
int getDefaultInputDeviceID(void)
{
  int defaultInput = 0;

  Pa_Initialize();
  defaultInput = Pa_GetDefaultInputDevice();
  Pa_Terminate();

  return defaultInput;
}
/* ==================================================================== */
int getDefaultOutputSampleRate(void)
{
  const PaDeviceInfo *pdi = NULL;
  Pa_Initialize();
  pdi = Pa_GetDeviceInfo(Pa_GetDefaultOutputDevice());
  Pa_Terminate();
  return pdi->defaultSampleRate;
}
/* ==================================================================== */
int getDefaultInputSampleRate(void)
{
  const PaDeviceInfo *pdi = NULL;
  Pa_Initialize();
  pdi = Pa_GetDeviceInfo(Pa_GetDefaultInputDevice());
  Pa_Terminate();
  return pdi->defaultSampleRate;
}
/* ==================================================================== */
char *getversiontxt(void)
{
  return strdup(Pa_GetVersionText());
}
/* ==================================================================== */
int getversion(void)
{
  return Pa_GetVersion();
}
/* ==================================================================== */
int getdevicecount(void)
{
  int nbDevices = 0;

  Pa_Initialize();
  nbDevices = Pa_GetDeviceCount();
  Pa_Terminate();

  return nbDevices;
}
/* ==================================================================== */
