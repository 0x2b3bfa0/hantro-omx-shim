# OpenMAX IL shim for Hantro x170 hardware codec.
This shim was made to compatibilize the Hantro x170 hardware codec OpenMAX library with ffmpeg. Specifically to be used on Android KitKat, on the DJI Goggles.

# Building.

You may meed to tweak `Makefile` to achieve a successful build; you'll need to set the path to your Android NDK and have the toolchain executables in your `PATH`

Also, you may replace the libraries on `./lib` by the ones extracted from your device, though that shouldn't be needed.
