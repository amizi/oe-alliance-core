SUMMARY = "Hardware drivers for ${MACHINE}"
SECTION = "base"
PRIORITY = "required"
LICENSE = "CLOSED"
require conf/license/license-close.inc

PACKAGE_ARCH = "${MACHINEBUILD}"

SRCDATE = "20161230"
KV = "3.14.28"
PV = "${KV}+${SRCDATE}"
PR = "r0"

SRC_URI[md5sum] = "824a667b820ddbf12dec7f81ca33b8d1"
SRC_URI[sha256sum] = "2a2012c0c22d111164fb31b427a903bec00431d014c17de888f444bed23865e8"

SRC_URI = "http://en3homeftp.net/release/images/oedrivers/bcmlinuxdvb_7252S-300mm-${KV}-${SRCDATE}.tar.gz"

S = "${WORKDIR}"

INHIBIT_PACKAGE_STRIP = "1"

inherit module

do_compile() {
}

do_populate_sysroot[noexec] = "1"

do_install() {
    install -d ${D}/lib/modules/${KV}/extra
    install -m 0644 ${WORKDIR}/lib/modules/${KV}/extra/bcmlinuxdvb.ko ${D}/lib/modules/${KV}/extra/bcmlinuxdvb_${MACHINEBUILD}.ko
    install -d ${D}/${sysconfdir}/modules-load.d
    echo bcmlinuxdvb_${MACHINEBUILD} _hwtype=\$hwtypenum >> ${D}/${sysconfdir}/modules-load.d/_${MACHINEBUILD}.conf
}

FILES_${PN} += "${sysconfdir}/modules-load.d/_${MACHINEBUILD}.conf"
