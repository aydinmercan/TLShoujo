arch_list = [
    'x86_64',
]

assert(arch_list.contains(host_machine.cpu_family()), 'TLShoujo currently doesn\'t support the host architecture')

subdir(host_machine.cpu_family())
