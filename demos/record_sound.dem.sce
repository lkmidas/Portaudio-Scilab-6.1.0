// ====================================================================
// Allan CORNET - 2010-2012
// ====================================================================
stacksize('max');
// ====================================================================
function demo_record()
  mprintf("\nRecord\n");
  recorderID = pa_defaultinputdeviceid();
  //pa_printdeviceinfo(recorderID);

  nbSamples = 10000;
  sampleRate = 44100;
  nbChannels = 1;
  datas = pa_recordwav(nbSamples, sampleRate, recorderID, nbChannels);

  tau = 1 / sampleRate;
  t = (0:nbSamples - 1) * tau;
  scf();
  plot(t,datas);
  
  pa_playwav(datas, sampleRate);
  
  //
  // Load this script into the editor
  //
  filename = "record_sound.dem.sce";
  dname = get_absolute_file_path(filename);
  editor ( fullfile(dname, filename) , 'readonly' );
  
endfunction
// ====================================================================
demo_record();
clear demo_record;
// ====================================================================
