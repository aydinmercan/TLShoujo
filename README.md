# TLShoujo - Cute TLS
TLShoujo is an (in-progress) implementation of [TLS 1.3](https://tools.ietf.org/html/rfc8446).
It aims to be readable and aid in understanding the specfication.

## Disclaimer
This library is intended to exist as an exercise and is **not audited**.
***Use at your own risk***. Or better yet, just use [OpenSSL](https://www.openssl.org).

## Building
The following are required:

* A (modern) C17 compiler.
* Meson build *>=0.55*

## Roadmap
* PEM formatting
* Memory allocation/locking
* X.509/ASN.1 parsing
* Finite field arithmetic and elliptic curve math
* SHA-2 family of hashes
* ChaCha20-Poly1305 (IETF variant) and AES-128-GCM AEADs
* X25519 and Ed25519
* RSASSA-PSS with MGF-1
* RSASSA-PKCS#1-v1.5
* ECDH and ECDSA over NIST P-256 (secp256r1)
* X.509 Validation
* Client/Server Hello
* Client/Server Handshake
* Simple CLI tool (debugging friendly)
* [...]

## License
This repository is licensed under the BSD-3-Clause. Refer to `LICENSE.md` for more details.
