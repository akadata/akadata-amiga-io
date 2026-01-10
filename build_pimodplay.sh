#!/bin/sh
# Build script for pimodplay - compatible with both glibc and musl libc environments
set -eu

# Allow overriding compiler via environment variable
: "${CC:=gcc}"

# Allow overriding pkg-config via environment variable
: "${PKG_CONFIG:=pkg-config}"

echo "Building pimodplay..."
echo "Using compiler: $CC"

# Build with appropriate flags
$CC -O2 -Wall -Wextra -std=c99 \
    -I./ \
    -Isrc/ \
    -Iplatforms/amiga/registers/ \
    src/pimodplay.c \
    gpio/ps_protocol.c \
    gpio/rpi_peri.c \
    -lm -o pimodplay

echo "Build completed successfully!"
echo "Binary: pimodplay"
