// ====================================================================
// Allan CORNET - 2010-2012
// ====================================================================
function cleaner_src()
  src_dir = get_absolute_file_path("cleaner_src.sce");
  for language = ["c"]
    cleaner_file = src_dir + filesep() + language + filesep() + "cleaner.sce";
    if fileinfo(cleaner_file) <> [] then
     exec(cleaner_file);
     mdelete(cleaner_file);
    end
  end
endfunction  
// ====================================================================
cleaner_src();
clear cleaner_src;
// ====================================================================
