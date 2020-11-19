// ====================================================================
// Allan CORNET - 2010-2012
// ====================================================================
function demo_playogg()
  [data, samplerate, fmt] = sfread(pa_gettlbxpath() + 'demos/demo.ogg'); 
  mprintf("\nPlay %s\n", strsubst(pa_gettlbxpath() + 'demos/demo.ogg', '\', '/'));
  mprintf("pa_playwav(data, samplerate);\n");
  pa_printdeviceinfo(pa_defaultoutputdeviceid());
  pa_playwav(data, samplerate);
  
  //
  // Load this script into the editor
  //
  filename = "play_ogg_file.dem.sce";
  dname = get_absolute_file_path(filename);
  editor ( fullfile(dname, filename) , 'readonly' );
  
endfunction  
// ====================================================================
demo_playogg();
clear demo_playogg;
// ====================================================================
