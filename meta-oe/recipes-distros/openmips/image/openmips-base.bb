SUMMARY = "Base packages require for image."
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/LICENSE;md5=4d92cd373abda3937c2bc47fbc49d690 \
                    file://${COREBASE}/meta/COPYING.MIT;md5=3da9cfbcb788c80a0384361b4de20420"

ALLOW_EMPTY_${PN} = "1"

PV = "${IMAGE_VERSION}"
PR = "r1"

inherit packagegroup

RDEPENDS_${PN} = "\
    oe-alliance-base \
    openmips-enigma2 \
    openmips-bootlogo \
    openmips-spinner \
    openssh-sftp-server \
    ntfs-3g \
    ntfsprogs \
    hddtemp \
    busybox-cron \
    python-imaging \
    rtmpdump \
    zip \
    ${@base_contains("MACHINE_FEATURES", "smallflash", "", \
    " \
    enigma2-plugin-extensions-openwebif-themes \
    enigma2-plugin-extensions-openwebif-webtv \
    enigma2-plugin-extensions-openwebif-vxg \
    ", d)} \
    ${@base_contains("MACHINE_FEATURES", "singlecore", "", \
    " \
    packagegroup-base-smbfs-server \
    packagegroup-base-nfs \
    ", d)} \
    packagegroup-base-smbfs-client \
    packagegroup-base-smbfs \
    ofgwrite \
    bash \
    "
