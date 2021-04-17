.. _shoujoprobe:

CPU Feature Probing
===================

Running ``shoujo_init()`` automatically probes features
and sets the bets implementations internally. If manual lookup
is desired before ``shoujo_init()``, you can use ``uint32_t shoujo_probe_cpu_features(void)``
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

   uint32_t shoujo_probe_query_sse2(void);
   uint32_t shoujo_probe_query_sse3(void);
   uint32_t shoujo_probe_query_ssse3(void);
   uint32_t shoujo_probe_query_sse41(void);
   uint32_t shoujo_probe_query_clmul(void);
   uint32_t shoujo_probe_query_aesni(void);
   uint32_t shoujo_probe_query_shani(void);
   uint32_t shoujo_probe_query_avx(void);
   uint32_t shoujo_probe_query_avx2(void);

(Draft) RISC-V
-----------------
