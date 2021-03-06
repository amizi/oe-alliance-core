# We know about rtc
include conf/machine/include/build-extras.inc

BRAND_OEM = "octagon"
MACHINE_BRAND = "Octagon"

IMAGEDIR ?= "${MACHINE}"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS = "\
    octagon-dvb-modules-${MACHINE} \
    "

DVBPROVIDER = "kernel"
DVBSKYPROVIDER = "kernel"

MACHINE_ESSENTIAL_EXTRA_RRECOMMENDS = "\
    kernel-module-cdfs \
    "

MACHINE_EXTRA_RRECOMMENDS = " \
    ${@base_contains("GST_VERSION", "1.0", "gstreamer1.0-plugin-dvbmediasink", "gst-plugin-dvbmediasink", d)} \
    "

include conf/machine/include/autoload-filesystems.inc

DVBMEDIASINK_CONFIG = "--with-wma --with-wmv --with-pcm --with-dts --with-eac3 --with-h265 --with-vb6 --with-vb8 --with-vb9 --with-spark"

TARGET_ARCH = "arm"
DEFAULTTUNE = "armv7ahf-neon"
IMAGE_FSTYPES =+ "tar.bz2"

PREFERRED_PROVIDER_virtual/kernel = "linux-octagon"

PREFERRED_PROVIDER_virtual/blindscan-dvbs = "octagon-blindscan-utils"
PREFERRED_PROVIDER_virtual/blindscan-dvbc = "octagon-blindscan-utils"

MACHINE_FEATURES += "alsa 3dtv switchoff hdmicec omb boxmodel feature2 blindscan-tbs blindscan-dvbc"

BOOTLOGO_FILENAME = "splash.bin"

require conf/machine/include/arm/arch-armv7a.inc
require conf/machine/include/soc-family.inc
