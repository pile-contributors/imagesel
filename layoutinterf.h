/**
 * @file imagesel.h
 * @brief Declarations for ActiveGrip class
 * @author Nicu Tofan <nicu.tofan@gmail.com>
 * @copyright Copyright 2014 piles contributors. All rights reserved.
 * This file is released under the
 * [MIT License](http://opensource.org/licenses/mit-license.html)
 */

#ifndef GUARD_ACTIVEGRIP_H_INCLUDE
#define GUARD_ACTIVEGRIP_H_INCLUDE

#include <imagesel/imagesel-config.h>
#include <QPoint>

class ImageSel;
class ActiveGrip;

//! brief description
class IMAGESEL_EXPORT LayoutInterf {

public:

    //! Destructor.
    virtual ~LayoutInterf ();

    virtual void
    paint (
        ImageSel * target) = 0;

    virtual void
    globalMove (
        ImageSel * target,
        const QPoint & pos) = 0;

    virtual void
    gripMode (
        ImageSel * target,
        ActiveGrip *grip,
        const QPoint & pos) = 0;

protected:

private:

};

#endif // GUARD_ACTIVEGRIP_H_INCLUDE
