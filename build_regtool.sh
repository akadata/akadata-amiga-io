#!/bin/sh
# Build script for regtool - compatible with both glibc and musl libc environments
set -eu

# Allow overriding compiler via environment variable
: "${CC:=gcc}"

# Allow overriding pkg-config via environment variable
: "${PKG_CONFIG:=pkg-config}"

echo "Building regtool..."
echo "Using compiler: $CC"

# Build with appropriate flags
$CC -O2 -Wall -Wextra -std=c99 \
    -I./ \
    -Iplatforms/amiga/registers/ \
    src/regtool.c \
    gpio/ps_protocol.c \
    gpio/rpi_peri.c \
    -o regtool

echo "Build completed successfully!"
echo "Binary: regtool"
