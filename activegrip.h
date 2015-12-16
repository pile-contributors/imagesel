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
#include <QWidget>

class ImageSel;

//! brief description
class IMAGESEL_EXPORT ActiveGrip : public QWidget {

    enum State {
        GST_NONE = 0,

        GST_HOVER = 0x0001,
        GST_CLICKED = 0x0002,

        GST_ALL = GST_HOVER | GST_CLICKED
    };

public:

    //! Default constructor.
    ActiveGrip (ImageSel * parent);

    //! Destructor.
    virtual ~ActiveGrip ();

    //! Retreive GripSize.
    inline int
    getGripSize () const {
        return minimumSize().width();
    }

    //! Set GripSize.
    inline void
    setGripSize (int value) {
        setMinimumSize (value, value);
        setMaximumSize (value, value);
    }

    //! Get the parent widget.
    ImageSel *
    parentSel () const;

protected:

    void enterEvent (QEvent *);
    void leaveEvent (QEvent *);
    void mousePressEvent (QMouseEvent *);
    void mouseReleaseEvent (QMouseEvent *);
    void mouseMoveEvent (QMouseEvent *);
    void paintEvent (QPaintEvent *);

private:
    QPoint offset_;
    int flags_;
};

#endif // GUARD_ACTIVEGRIP_H_INCLUDE
