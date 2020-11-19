// ====================================================================
// Allan CORNET - 2010
// ====================================================================
function builder_gw()
  sci_gateway_dir = get_absolute_file_path('builder_gateway.sce');

  tbx_builder_gateway_lang('c', sci_gateway_dir);
  languages = ['c'];

  tbx_build_gateway_loader(languages, sci_gateway_dir);
  tbx_build_gateway_clean(languages, sci_gateway_dir);
endfunction
// ====================================================================
builder_gw();
clear builder_gw;
// ====================================================================

