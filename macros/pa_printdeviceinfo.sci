// ====================================================================
// Allan CORNET - 2010-2012
// ====================================================================

function pa_printdeviceinfo(deviceID)

  [drv_names, samples_rate, MaxInputChannels, MaxOutputChannels, ..
  LowInputLatency, LowOutputLatency, ..
  HighInputLatency, HighOutputLatency] =  pa_deviceinfo();

  if isdef('deviceID') then
      mprintf("Driver ID: %d\n", deviceID);
      mprintf("Driver name: %s\n", drv_names(deviceID));
      mprintf("Default Sample rate: %f\n", samples_rate(deviceID));
      mprintf("Max. Input Channels: %i\n", MaxInputChannels(deviceID));
      mprintf("Max. Output Channels: %i\n", MaxInputChannels(deviceID));
      mprintf("Default Low Input Latency: %f\n", LowInputLatency(deviceID));
      mprintf("Default Low Output Latency: %f\n", LowOutputLatency(deviceID));
      mprintf("Default High Input Latency: %f\n", HighInputLatency(deviceID));
      mprintf("Default High Output Latency: %f\n\n", HighOutputLatency(deviceID));
  else
    for i = 1:1:size(drv_names, '*')
      mprintf("Driver ID: %d\n", i);
      mprintf("Driver name: %s\n", drv_names(i));
      mprintf("Default Sample rate: %f\n", samples_rate(i));
      mprintf("Max. Input Channels: %i\n", MaxInputChannels(i));
      mprintf("Max. Output Channels: %i\n", MaxInputChannels(i));
      mprintf("Default Low Input Latency: %f\n", LowInputLatency(i));
      mprintf("Default Low Output Latency: %f\n", LowOutputLatency(i));
      mprintf("Default High Input Latency: %f\n", HighInputLatency(i));
      mprintf("Default High Output Latency: %f\n\n", HighOutputLatency(i));
    end
  end
endfunction
// ====================================================================
