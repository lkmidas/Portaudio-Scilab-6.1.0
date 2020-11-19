// ====================================================================
// Allan CORNET - 2010-2012
// ====================================================================
stacksize(1.077D+08);
// ====================================================================
function demo_generated_sound()
  n = 20; // n second
  fs = 22050; // samplerata
  t = soundsec(n, fs);
  f1 = 440; // ref frequency
  s = cos(2 * %pi * f1 * t) / 10;
  h = scf();
  plot(s);
  pa_playwav(s', fs);
  delete(h)

  tau_up = 1;
  u = 1 - exp(-t / tau_up);
  s2 = s.*u;
  h = scf();
  plot(s2);
  pa_playwav(s2', fs);
  delete(h);

  n = 10; // duree
  fs = 44100; // samplerate
  f1 = 440; // ref frequency
  delta_f = 0.5; // error of f
  t = soundsec(n, fs);
  sref = sin(2*%pi*f1*t)*0.1;
  s2 = sin(2*%pi*(f1+delta_f)*t)*0.2;
  s = sref+s2;
  h = scf();
  plot2d(t,s);
  pa_playwav(s', fs);
  delete(h);

  //
  // Load this script into the editor
  //
  filename = "play_generated_sound.dem.sce";
  dname = get_absolute_file_path(filename);
  editor ( fullfile(dname, filename) , 'readonly' );

endfunction
// ====================================================================
demo_generated_sound();
clear demo_generated_sound;
// ====================================================================
