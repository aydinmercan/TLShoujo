project(
    'tlshoujo',
    'c',
    license: 'BSD-3-Clause',
    meson_version: '>=0.55.0',
    default_options: [
        'c_std=c17',
        'b_pie=true',
        'warning_level=3',
        'werror=true'
    ],
)

cc = meson.get_compiler('c')

add_project_arguments(
    cc.get_supported_arguments(
        [
        '-Wundef',
        '-Walloca',
        '-Wcast-align',
        '-Wconversion',
        '-Wtrampolines',
        '-Woverflow',
        '-Wuninitialized',
        '-Winit-self',
        '-Wendif-labels',
        '-Wwrite-strings',
        '-Wmissing-prototypes',
        '-Wmissing-include-dirs',
        '-Wstrict-prototypes',
        '-Wstrict-aliasing=2',
        '-Wstrict-overflow=2',
        '-Wno-error=unknown-pragmas',
        '-Wno-error=#warnings',
        '-Wno-unused-parameter',
        '-Wno-format-nonliteral',
        '-Wno-missing-braces',
        '-Wno-missing-field-initializers',

        '-fno-common',
        '-fcf-protection=full',
        '-fstack-protector',
        '-fstack-protector-strong',
        ]
    ), language: 'c'
)

option_names = [
    'ssse3',
    'avx',
    'avx2',
    'aesni',
    'shani',
]

foreach opt : option_names
    if get_option(opt).disabled()
        add_project_arguments('-DCOMPTIME_NO_@0@'.format(opt.to_upper()), language: 'c')
    endif
endforeach

shoujo_src = []

subdir('src')


shoujo_inc = include_directories('.', 'include')

shoujo_lib = shared_library(
    'tlshoujo',
    shoujo_src,
    include_directories: shoujo_inc,
)

tlshoujo = declare_dependency(
	link_with: shoujo_lib,
	include_directories: shoujo_inc,
)

subdir('test')
