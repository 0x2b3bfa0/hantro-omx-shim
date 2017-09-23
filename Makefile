NDK_ROOT=/home/user/android-ndk-r15c
ANDROID_API_VERSION=android-14
ARCH=arm

TOOLCHAIN = ${ARCH}-linux-androideabi
CC = ${TOOLCHAIN}-gcc
LD = ${TOOLCHAIN}-ld

SYSROOT = ${NDK_ROOT}/platforms/${ANDROID_API_VERSION}/arch-${ARCH}
LDFLAGS = --sysroot="${SYSROOT}" -L./lib -lon2_hantro_omx_core -shared
CFLAGS = --sysroot="${SYSROOT}" -I./include -fPIC -Wall -O2

.PHONY: all
all: libOMX_Core.so

.PHONY: clean
clean:
	rm libOMX_Core.so

libOMX_Core.so: 
	$(CC) ${CFLAGS} ${LDFLAGS} -o $@ libOMX_Core.c

