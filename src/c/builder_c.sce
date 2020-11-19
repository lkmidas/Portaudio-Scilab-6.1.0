// ====================================================================
// Allan CORNET - 2010-2012
// ====================================================================

function builder_c()

src_c_path = get_absolute_file_path('builder_c.sce');
includes_portaudio = fullpath(src_c_path + "../../thirdparty/portaudio/include");

CFLAGS = '';
LDFLAGS = '';
dynlibname = '';

if getos() == 'Windows' then
  if win64() then
    dynlibname = '../../thirdparty/portaudio/lib/windows/x64/portaudio_x64';
  else
    dynlibname = '../../thirdparty/portaudio/lib/windows/x86/portaudio_x86';
  end
else
  if getos() == 'Darwin' then
    dynlibname = '../../thirdparty/portaudio/lib/macos/portaudio';
  else
    dynlibname = '../../thirdparty/portaudio/lib/others/portaudio';
  end
end

files_c = ["pa_deviceinfo.c";
           "pa_playwav.c";
           "pa_recordwav.c";
           "pa_callback_play.c";
           "pa_callback_record.c";
           "convertSAMPLE.c"];

CFLAGS = CFLAGS + " " + ilib_include_flag([src_c_path, includes_portaudio]);

tbx_build_src(['pa_c'], files_c, 'c', ..
              src_c_path, dynlibname, LDFLAGS, CFLAGS);

endfunction
// ====================================================================
builder_c();
clear builder_c;
// ====================================================================
