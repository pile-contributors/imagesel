/**
 * @file imagesel.cc
 * @brief Definitions for ImageSel class.
 * @author Nicu Tofan <nicu.tofan@gmail.com>
 * @copyright Copyright 2014 piles contributors. All rights reserved.
 * This file is released under the
 * [MIT License](http://opensource.org/licenses/mit-license.html)
 */

#include "imagesel.h"
#include "imagesel-private.h"

#include <QPainter>

/**
 * @class ImageSel
 *
 * Detailed description.
 */

/* ------------------------------------------------------------------------- */
/**
 * Detailed description for constructor.
 */
ImageSel::ImageSel(QWidget * parent) :
    QWidget (parent),
    image_(),
    offset_(),
    lay_(NULL)
{
    IMAGESEL_TRACE_ENTRY;

    IMAGESEL_TRACE_EXIT;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
/**
 * Detailed description for destructor.
 */
ImageSel::~ImageSel()
{
    IMAGESEL_TRACE_ENTRY;

    IMAGESEL_TRACE_EXIT;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
void ImageSel::setBuildInLayout (ImageSel::BuildInLay kind)
{
    switch (kind) {
    case Rectangular: {
        setLay (new RectangularBuildInlay ());
        break; }
    case Square: {
        setLay (new SquareBuildInlay ());
        break; }
    case Ellipse: {
        setLay (new EllipseBuildInlay ());
        break; }
    case Circle: {
        setLay (new CircleBuildInlay ());
        break; }
    default:
        IMAGESEL_DEBUGM("invalid build-in constant: %d\n", kind);
    }
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
/**
 *
 * @param grip the grip that's being moved
 * @param pos the position where it would be if this was a free move
 * @return The position of the grip.
 */
QPoint ImageSel::gripMode (ActiveGrip *grip, const QPoint &pos)
{
    if (lay_ == NULL)
        return pos;
    return lay_->gripMode (this, grip, pos);
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
void ImageSel::mousePressEvent (QMouseEvent *event)
{
    offset_ = event->pos();
    update ();
    event->accept();
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
void ImageSel::mouseReleaseEvent (QMouseEvent *event)
{
    update ();
    event->accept();
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
void ImageSel::mouseMoveEvent (QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        return lay_->globalMove (this, event->pos() - offset_);
    }
    event->accept();
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
void ImageSel::paintEvent (QPaintEvent *event)
{
    QPainter painter (this);

    if (!image_.isNull()) {
        QRect src (image_.rect());
        QSize dst (size ());
        int scale = qMin(dst.width() / src.width(), dst.height()/src.height());
        int dst_width = src.width() * scale;
        int dst_height = src.height() * scale;
        QRect drect (
                    (dst.width() - dst_width)/2,
                    (dst.height() - dst_height)/2,
                    dst_width, dst_height);

        painter.drawPixmap (drect, image_, src);
    }

    lay_->paint (this);

    event->accept ();
}
/* ========================================================================= */
