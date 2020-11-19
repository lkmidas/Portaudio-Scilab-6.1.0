// ====================================================================
// Allan CORNET - 2010-2012
// ====================================================================
function subdemolist = demo_gateway()
  demopath = get_absolute_file_path("portaudio_toolbox.dem.gateway.sce");
  
  subdemolist = ["Play generated sound"       ,"play_generated_sound.dem.sce"; ..
                 "Play .mat files"            ,"play_mat.dem.sce"; ..
                 "Record sound"               ,"record_sound.dem.sce"];

  if isdef("sndfilelib") then
    subdemolist = ["Play .ogg file"             ,"play_ogg_file.dem.sce"; ..
                   subdemolist];
  end               

  subdemolist(:,2) = demopath + subdemolist(:,2);
endfunction  
// ====================================================================
subdemolist = demo_gateway();
clear demo_gateway;
// ====================================================================
