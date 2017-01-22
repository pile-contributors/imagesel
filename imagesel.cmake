
# enable/disable cmake debug messages related to this pile
set (IMAGESEL_DEBUG_MSG OFF)

# make sure support code is present; no harm
# in including it twice; the user, however, should have used
# pileInclude() from pile_support.cmake module.
include(pile_support)

# initialize this module
macro    (imageselInit
          ref_cnt_use_mode)

    # default name
    if (NOT IMAGESEL_INIT_NAME)
        set(IMAGESEL_INIT_NAME "ImageSel")
    endif ()

    # compose the list of headers and sources
    set(IMAGESEL_HEADERS
        "imagesel.h"
        "layoutinterf.h"
        "activegrip.h")
    set(IMAGESEL_SOURCES
        "activegrip.cc"
        "layoutinterf.cc"
        "imagesel.cc")
    set(IMAGESEL_QT_MODS
        Core Widgets)

    pileSetSources(
        "${IMAGESEL_INIT_NAME}"
        "${IMAGESEL_HEADERS}"
        "${IMAGESEL_SOURCES}")

    pileSetCommon(
        "${IMAGESEL_INIT_NAME}"
        "0;0;1;d"
        "ON"
        "${ref_cnt_use_mode}"
        ""
        "category1"
        "tag1;tag2")

endmacro ()
