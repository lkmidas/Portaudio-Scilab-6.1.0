// ====================================================================
// Allan CORNET - 2010-2012
// ====================================================================
function demo_playmat()
  data = fscanfMat(pa_gettlbxpath() + 'demos/chirp.mat');
  samplerate = 8192;
  mprintf("\nPlay %s\n", strsubst(pa_gettlbxpath() + 'chirp.mat', '\', '/'));
  scf();
  plot(data);
  pa_playwav(data, samplerate);

  data = fscanfMat(pa_gettlbxpath() + 'demos/dong.mat');
  samplerate = 8192;
  mprintf("\nPlay %s\n", strsubst(pa_gettlbxpath() + 'dong.mat', '\', '/'));
  scf();
  plot(data);
  pa_playwav(data, samplerate);
  
  //
  // Load this script into the editor
  //
  filename = "play_mat.dem.sce";
  dname = get_absolute_file_path(filename);
  editor ( fullfile(dname, filename) , 'readonly' );
  
endfunction  
// ====================================================================
demo_playmat();
clear demo_playmat;
// ====================================================================
