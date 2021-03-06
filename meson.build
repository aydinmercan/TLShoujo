project(
    'tlshoujo',
    'c',
    license : 'BSD-3-Clause',
    meson_version : '>=0.55.0',
    default_options : [
        'c_std=c17',
        'b_pie=true',
        'b_asneeded=true',
        'b_staticpic=true',
        'warning_level=3',
        'werror=true',
    ],
)

cc = meson.get_compiler('c')

add_project_arguments(
    cc.get_supported_arguments(
        [
        '-Walloca',
        '-Wcast-align',
        '-Wconversion',
        '-Wendif-labels',
        '-Wformat-security',
        '-Wformat=2',
        '-Winit-self',
        '-Wmissing-include-dirs',
        '-Wmissing-prototypes',
        '-Wno-error=#warnings',
        '-Wno-error=unknown-pragmas',
        '-Wno-format-nonliteral',
        '-Wno-missing-braces',
        '-Wno-missing-field-initializers',
        '-Wno-unused-parameter',
        '-Woverflow',
        '-Wstrict-aliasing=2',
        '-Wstrict-overflow=2',
        '-Wstrict-prototypes',
        '-Wtrampolines',
        '-Wundef',
        '-Wuninitialized',
        '-Wwrite-strings',

        '-fcf-protection=full',
        '-fno-common',
        '-fstack-protector',
        '-fstack-protector-strong',

        '-masm=intel',
        ]
    ), language : 'c'
)

add_project_link_arguments(
    cc.get_supported_link_arguments(
        [
        '-Wl,-z,noexecheap',
        '-Wl,-z,noexecstack',
        '-Wl,-z,relro',
        ]
    ), language : 'c'
)



add_project_arguments('-D_POSIX_C_SOURCE=200809L', language : 'c')
add_project_arguments('-D_DEFAULT_SOURCE', language : 'c')

shoujo_src = []
shoujo_inc = include_directories('.', 'include')

internal_inc = []

cli_src = []
cli_inc = []

subdir('src')

shoujo_lib = shared_library(
    'tlshoujo',
    shoujo_src,
    include_directories : [shoujo_inc, internal_inc]
)

tlshoujo = declare_dependency(
	link_with : shoujo_lib,
	include_directories : shoujo_inc,
)

subdir('test')

if get_option('cli').enabled()
  shoujo_cli = executable(
      'shoujo',
      cli_src,
      include_directories : [ cli_inc, shoujo_inc ],
      dependencies : tlshoujo,
  )
endif
