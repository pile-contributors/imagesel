if (NOT IMAGESEL_BUILD_MODE)
    set (IMAGESEL_BUILD_MODE STATIC)
endif ()

include(pile_support)
pileInclude (ImageSel)
imageselInit(${IMAGESEL_BUILD_MODE})
