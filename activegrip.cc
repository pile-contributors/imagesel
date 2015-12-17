/**
 * @file imagesel.cc
 * @brief Definitions for ActiveGrip class.
 * @author Nicu Tofan <nicu.tofan@gmail.com>
 * @copyright Copyright 2014 piles contributors. All rights reserved.
 * This file is released under the
 * [MIT License](http://opensource.org/licenses/mit-license.html)
 */

#include "imagesel.h"
#include "imagesel-private.h"
#include "activegrip.h"

#include <QMouseEvent>
#include <QPaintEvent>
#include <QPainter>


/**
 * @class ActiveGrip
 *
 * Detailed description.
 */

/* ------------------------------------------------------------------------- */
/**
 * Detailed description for constructor.
 */
ActiveGrip::ActiveGrip (ImageSel * parent) :
    QWidget (parent),
    offset_(),
    flags_(GST_NONE)
{
    IMAGESEL_TRACE_ENTRY;
    setGripSize (8);
    IMAGESEL_TRACE_EXIT;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
/**
 * Detailed description for destructor.
 */
ActiveGrip::~ActiveGrip()
{
    IMAGESEL_TRACE_ENTRY;

    IMAGESEL_TRACE_EXIT;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
ImageSel *ActiveGrip::parentSel() const
{
    return qobject_cast<ImageSel *>(parentWidget());
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
void ActiveGrip::enterEvent (QEvent *event)
{
    flags_ = flags_ | GST_HOVER;
    update ();
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
void ActiveGrip::leaveEvent (QEvent *event)
{
    update ();
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
void ActiveGrip::mousePressEvent (QMouseEvent *event)
{
    flags_ = flags_ | GST_CLICKED;
    offset_ = event->pos();
    update ();
    event->accept();
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
void ActiveGrip::mouseReleaseEvent (QMouseEvent *event)
{
    flags_ = flags_ & (~GST_CLICKED);
    update ();
    event->accept();
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
void ActiveGrip::mouseMoveEvent (QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        this->move (
                    parentSel()->gripMode (
                        this,
                        mapToParent (
                            event->pos() - offset_)));
    }
    event->accept();
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
void ActiveGrip::paintEvent (QPaintEvent *event)
{
    QPainter painter (this);
    int rad = size().width()/2 - 1;
    if ((flags_ & GST_CLICKED) == GST_CLICKED) {
        painter.setPen (Qt::red);
    } else if ((flags_ & GST_HOVER) == GST_HOVER) {
        painter.setPen (Qt::blue);
        painter.setBrush (Qt::red);
    } else {
        painter.setPen (Qt::black);
    }
    int w = size().width() - 2;
    painter.drawEllipse (1, 1, w, w);
    event->accept ();
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
