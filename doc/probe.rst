.. _shoujoprobe:

CPU Feature Probing
===================

Running ``shoujo_init()`` automatically probes features
and sets the bets implementations internally. If manual lookup
is desired before ``shoujo_init()``, you can use ``int shoujo_probe_cpu_features(void)``
and then query the results.

Keep in mind that while every feature from every architecture can be queried,
only the target architecture will probe.

Currently the following architectures are supported:

- x86_64 (aka AMD64)

Future target candidates are:

- RISC-V (RV32IMAKV and RV64IMAKV)


x86_64
------

.. code-block:: c

   int shoujo_probe_query_sse2(void);
   int shoujo_probe_query_sse3(void);
   int shoujo_probe_query_ssse3(void);
   int shoujo_probe_query_sse41(void);
   int shoujo_probe_query_clmul(void);
   int shoujo_probe_query_aesni(void);
   int shoujo_probe_query_shani(void);
   int shoujo_probe_query_avx(void);
   int shoujo_probe_query_avx2(void);

(Draft) RISC-V
-----------------

.. code-block:: c
   int shoujo_probe_query_riscv_sha256(void);
   int shoujo_probe_query_rotate(void);
   int shoujo_probe_query_permute(void);
   int shoujo_probe_query_clmul(void);
