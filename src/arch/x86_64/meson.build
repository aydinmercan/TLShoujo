shoujo_src += files([
    'probe.c',
    'core_lock.c',
    'cpuid.S',
])


internal_inc += include_directories('.')

x86_64_feat = [
    'sse2',
    'sse3',
    'ssse3',
    'sse41',
    'clmul',
    'avx',
    'avx2',
    'aesni',
    'shani',
]

arch_feat_dict = {}

foreach feat : x86_64_feat
    if get_option(feat).disabled()
        arch_feat_dict += { 'CPU_QUERY_COMPTIME_FLAG_@0@'.format(feat) : 1 }
    else
        arch_feat_dict += { 'CPU_QUERY_COMPTIME_FLAG_@0@'.format(feat) : 0 }
    endif
endforeach

configure_file(
    output : 'config.h',
    configuration : configuration_data(arch_feat_dict),
)
