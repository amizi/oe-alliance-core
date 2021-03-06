# We know about rtc
include conf/machine/include/build-extras.inc

BRAND_OEM = "xcore"

MACHINE_NAME = "\
${@base_contains('MACHINEBUILD', 'spycat', 'SpyCat' , '', d)}\
${@base_contains('MACHINEBUILD', 'spycatmini', 'SpyCat mini' , '', d)}\
${@base_contains('MACHINEBUILD', 'spycatminiplus', 'SpyCat mini +' , '', d)}\
${@base_contains('MACHINEBUILD', 'vp7358ci', '7358ci' , '', d)}\
${@base_contains('MACHINEBUILD', 'bcm7358', '7358' , '', d)}\
${@base_contains('MACHINEBUILD', 'osmini', 'OS mini' , '', d)}\
${@base_contains('MACHINEBUILD', 'osminiplus', 'OS mini +' , '', d)}\
${@base_contains('MACHINEBUILD', 'osmega', 'OS mega' , '', d)}\
"

MACHINE_BRAND = "\
${@base_contains('MACHINEBUILD', 'spycat', 'SPYCAT' , '', d)}\
${@base_contains('MACHINEBUILD', 'spycatmini', 'SPYCAT' , '', d)}\
${@base_contains('MACHINEBUILD', 'spycatminiplus', 'SPYCAT' , '', d)}\
${@base_contains('MACHINEBUILD', 'vp7358ci', 'Sample2' , '', d)}\
${@base_contains('MACHINEBUILD', 'bcm7358', 'Sample1' , '', d)}\
${@base_contains('MACHINEBUILD', 'osmini', 'Edision' , '', d)}\
${@base_contains('MACHINEBUILD', 'osminiplus', 'Edision' , '', d)}\
${@base_contains('MACHINEBUILD', 'osmega', 'Edision' , '', d)}\
"

IMAGEDIR ?= "\
${@base_contains('MACHINEBUILD', 'spycat', 'spycat' , '', d)}\
${@base_contains('MACHINEBUILD', 'spycatmini', 'spycatmini' , '', d)}\
${@base_contains('MACHINEBUILD', 'spycatminiplus', 'spycatminiplus' , '', d)}\
${@base_contains('MACHINEBUILD', 'vp7358ci', 'vp7358ci' , '', d)}\
${@base_contains('MACHINEBUILD', 'bcm7358', 'bcm7358' , '', d)}\
${@base_contains('MACHINEBUILD', 'osmini', 'osmini' , '', d)}\
${@base_contains('MACHINEBUILD', 'osminiplus', 'osminiplus' , '', d)}\
${@base_contains('MACHINEBUILD', 'osmega', 'osmega' , '', d)}\
"

MTD_KERNEL = "\
${@base_contains('MACHINEBUILD', 'spycat', 'mtd0' , '', d)}\
${@base_contains('MACHINEBUILD', 'spycatmini', 'mtd0' , '', d)}\
${@base_contains('MACHINEBUILD', 'spycatminiplus', 'mtd0' , '', d)}\
${@base_contains('MACHINEBUILD', 'vp7358ci', 'mtd2' , '', d)}\
${@base_contains('MACHINEBUILD', 'bcm7358', 'mtd2' , '', d)}\
${@base_contains('MACHINEBUILD', 'osmini', 'mtd0' , '', d)}\
${@base_contains('MACHINEBUILD', 'osminiplus', 'mtd0' , '', d)}\
${@base_contains('MACHINEBUILD', 'osmega', 'mtd0' , '', d)}\
"

MTD_ROOTFS = "\
${@base_contains('MACHINEBUILD', 'spycat', 'mtd2' , '', d)}\
${@base_contains('MACHINEBUILD', 'spycatmini', 'mtd2' , '', d)}\
${@base_contains('MACHINEBUILD', 'spycatminiplus', 'mtd2' , '', d)}\
${@base_contains('MACHINEBUILD', 'vp7358ci', 'mtd3' , '', d)}\
${@base_contains('MACHINEBUILD', 'bcm7358', 'mtd3' , '', d)}\
${@base_contains('MACHINEBUILD', 'osmini', 'mtd2' , '', d)}\
${@base_contains('MACHINEBUILD', 'osminiplus', 'mtd2' , '', d)}\
${@base_contains('MACHINEBUILD', 'osmega', 'mtd2' , '', d)}\
"

MACHINE_DRIVER = "\
${@base_contains('MACHINEBUILD', 'spycat', 'spycat' , '', d)}\
${@base_contains('MACHINEBUILD', 'spycatmini', 'spycatmini' , '', d)}\
${@base_contains('MACHINEBUILD', 'spycatminiplus', 'spycatminiplus' , '', d)}\
${@base_contains('MACHINEBUILD', 'vp7358ci', 'vp7358ci' , '', d)}\
${@base_contains('MACHINEBUILD', 'bcm7358', 'bcm7358' , '', d)}\
${@base_contains('MACHINEBUILD', 'osmini', 'osmini' , '', d)}\
${@base_contains('MACHINEBUILD', 'osminiplus', 'osminiplus' , '', d)}\
${@base_contains('MACHINEBUILD', 'osmega', 'osmega' , '', d)}\
"

KERNEL_FILE = "kernel.bin"
ROOTFS_FILE = "rootfs.bin"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS = "\
    xcore-dvb-modules-${MACHINE_DRIVER} \
    "

DVBPROVIDER = "kernel"
DVBSKYPROVIDER = "kernel"

MACHINE_ESSENTIAL_EXTRA_RRECOMMENDS += " \
    kernel-module-cdfs \
    "

MACHINE_EXTRA_RRECOMMENDS += " \
    gstreamer1.0-plugin-dvbmediasink \
    "

include conf/machine/include/autoload-filesystems.inc

DVBMEDIASINK_CONFIG = "--with-wma --with-wmv --with-pcm --with-dts --with-eac3  \
    ${@base_contains('MACHINEBUILD', 'osminiplus', '--with-h265 --with-vb6 --with-vb8 --with-spark' , '', d)} \
    ${@base_contains('MACHINEBUILD', 'spycatminiplus', '--with-h265 --with-vb6 --with-vb8 --with-spark' , '', d)} \
    ${@base_contains('MACHINEBUILD', 'osmega', '--with-h265 --with-vb6 --with-vb8 --with-spark' , '', d)} \
"

TARGET_ARCH = "mipsel"
DEFAULTTUNE = "mips32el"

PREFERRED_PROVIDER_virtual/blindscan-dvbs = "xcore-blindscan-utils"
PREFERRED_PROVIDER_virtual/blindscan-dvbc = "xcore-blindscan-utils"

PREFERRED_PROVIDER_virtual/kernel = "linux-xcore"

KERNEL_OUTPUT = "${KERNEL_IMAGETYPE}"
KERNEL_CONSOLE = "ttyS0,115200n8"

IMAGE_FSTYPES ?= "ubi"

IMAGE_CMD_ubi_prepend = " \
    rm -rf ${IMAGE_ROOTFS}/boot/*; \
    rm -rf ${IMAGE_ROOTFS}/tmp/*; \
    "

MACHINE_FEATURES += "alsa 3dtv switchoff hdmicec bootsplash omb boxmodel feature1 feature2"

BOOTLOGO_FILENAME = "splash.bin"

require conf/machine/include/tune-mips32.inc
require conf/machine/include/soc-family.inc

# add support for extra feeds
PACKAGE_ARCHS += " ${MACHINEBUILD}"