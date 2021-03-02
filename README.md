# TLShoujo - Cute TLS
TLShoujo is an (in-progress) implementation of [TLS 1.3](https://tools.ietf.org/html/rfc8446).
It aims to be readable and aid in understanding the specfication.

## Disclaimer
This library is intended to exist as an exercise and is **not audited**.
***Use at your own risk.***. Or better yet, just use `OpenSSL`.

## Building
The following are required:

* A (modern) C17 compiler.
* Meson build *>=0.57*

## Roadmap
* PEM formatting
* Memory allocation/locking
* X.509/ASN.1 parsing
* Finite field arithmetic and elliptic curve math
* SHA-2 family of hashes
* (...)

## License
This repository is licensed under the BSD-3-Clause. Refer to `LICENSE.md` for more details.
