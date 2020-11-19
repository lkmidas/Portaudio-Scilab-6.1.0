// =============================================================================
// Copyright (C) 2010-2012 - Allan CORNET
// =============================================================================
function builder_module()

mode(-1);

TOOLBOX_NAME  = "portaudio";
TOOLBOX_TITLE = "portaudio Toolbox";
toolbox_dir   = get_absolute_file_path("builder.sce");

// Check Scilab's version
// =============================================================================
try
	v = getversion("scilab");
catch
	error(gettext("Scilab 5.4 or more is required."));
end

if v(1) <= 5 && v(2) < 4 then
	// new API in scilab 5.4
	error(gettext('Scilab 5.4 or more is required.'));  
end

// Check modules_manager module availability
// =============================================================================
if ~isdef('tbx_build_loader') then
  error(msprintf(gettext('%s module not installed.'), 'modules_manager'));
end

// Action
// =============================================================================
tbx_builder_macros(toolbox_dir);
tbx_builder_src(toolbox_dir);
tbx_builder_gateway(toolbox_dir);
tbx_builder_help(toolbox_dir);
tbx_build_loader(TOOLBOX_NAME, toolbox_dir);
tbx_build_cleaner(TOOLBOX_NAME, toolbox_dir);
endfunction
// =============================================================================
builder_module();
clear builder_module;
// =============================================================================
