// ====================================================================
// Allan CORNET - 2010-2012
// ====================================================================

function builder_gateway_c()

CFLAGS = '';
gw_c_path = get_absolute_file_path("builder_gateway_c.sce");
src_c_path = fullpath(gw_c_path + '../../src/c');
includes_portaudio = fullpath(gw_c_path + '../../thirdparty/portaudio/include');

// PutLhsVar managed by user
// if you do not this variable, PutLhsVar is added
// in gateway generated (default mode in scilab 4.x and 5.x)
WITHOUT_AUTO_PUTLHSVAR = %t;

gateways = ['pa_deviceinfo', 'sci_pa_deviceinfo'; ..
            'pa_playwav', 'sci_pa_playwav'; ..
            'pa_defaultinputdeviceid','sci_pa_defaultinputdeviceid'; ..
            'pa_defaultoutputdeviceid','sci_pa_defaultoutputdeviceid'; ..
            'pa_getversiontext','sci_pa_getversiontext'; ..
            'pa_getversion','sci_pa_getversion'; ..
            'pa_recordwav','sci_pa_recordwav'; ..
            'pa_getdevicecount','sci_pa_getdevicecount'; ..
            ];

files_gateways = ['sci_pa_deviceinfo.c'; ..
                  'sci_pa_playwav.c'; ..
                  'sci_pa_defaultinputdeviceid.c'; ..
                  'sci_pa_defaultoutputdeviceid.c'; ..
                  'sci_pa_getversiontext.c'; ..
                  'sci_pa_getversion.c'; ..
                  'sci_pa_recordwav.c'; ..
                  'sci_pa_getdevicecount.c'; ..
                  ];

libs_c = ['../../src/c/libpa_c']

CFLAGS = CFLAGS + " " + ilib_include_flag([gw_c_path, src_c_path, includes_portaudio]);

tbx_build_gateway('gw_pa_c', gateways, files_gateways, ..
                  get_absolute_file_path('builder_gateway_c.sce'), ..
                  libs_c, '', CFLAGS);

endfunction

builder_gateway_c();
clear builder_gateway_c
