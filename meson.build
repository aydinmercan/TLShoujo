project(
    'tlshoujo',
    'c',
    meson_version: '>=0.57.0',
    default_options: [
        'c_std=c17',
        'b_pie=true',
        'warning_level=3',
        'werror=true'
    ],
)

cc = meson.get_compiler('c')

subdir('src')

shoujo_include_dir = include_directories('.', 'include')

shoujo_lib = shared_library(
    'tlshoujo',
    shoujo_sources,
    include_directories: shoujo_include_dir,
)

tlshoujo = declare_dependency(
	link_with: shoujo_lib,
	include_directories: shoujo_include_dir,
)

subdir('test')
