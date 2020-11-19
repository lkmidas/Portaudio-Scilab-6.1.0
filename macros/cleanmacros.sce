// ====================================================================
// Allan CORNET - 2010-2012
// ====================================================================
function clean_macros()
  libpath = get_absolute_file_path('cleanmacros.sce');

  binfiles = ls(libpath+'/*.bin');
  for i = 1:size(binfiles,'*')
    mdelete(binfiles(i));
  end

  mdelete(libpath+'/names');
  mdelete(libpath+'/lib');
endfunction
// ====================================================================
clean_macros();
clear clean_macros;
// ====================================================================
