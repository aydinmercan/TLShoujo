shoujo_src += files([
	'compare.c',
	'wipe.c',
	'tweak.c',
	'alloc.c',
])

function_names_memory = [
	'mlock',
    'madvise',
]

foreach func : function_names_memory
    if (cc.has_function(func, prefix : '#define _DEFAULT_SOURCE\n#include <sys/mman.h>'))
          add_project_arguments('-DHAVE_@0@'.format(func.to_upper()), language : 'c')
    endif
endforeach
