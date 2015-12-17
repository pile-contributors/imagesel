/**
 * @file imagesel.h
 * @brief Declarations for ImageSel class
 * @author Nicu Tofan <nicu.tofan@gmail.com>
 * @copyright Copyright 2014 piles contributors. All rights reserved.
 * This file is released under the
 * [MIT License](http://opensource.org/licenses/mit-license.html)
 */

#ifndef GUARD_IMAGESEL_H_INCLUDE
#define GUARD_IMAGESEL_H_INCLUDE

#include <imagesel/imagesel-config.h>
#include <QWidget>

class ActiveGrip;
class LayoutInterf;

//! brief description
class IMAGESEL_EXPORT ImageSel : public QWidget {
    Q_OBJECT

    friend class ActiveGrip;

public:

    //! The list of build-in layouts.
    enum BuildInLay {
        Invalid = -1,

        Rectangular,
        Square,
        Ellipse,
        Circle,

        BuildinMax
    };



    //! Default constructor.
    ImageSel (
            QWidget * parent = NULL);

    //! Destructor.
    virtual ~ImageSel();

    //! Change the image that's being presented to the user.
    void
    setImage (
            const QPixmap & value) {
        image_ = value;
        update ();
    }

    //! Remove the image that's being presented to the user.
    void
    clearImage () {
        image_ = QPixmap ();
        update ();
    }

    //! The image that's being presented to the user.
    const QPixmap &
    image () const {
        return image_;
    }

    //! Set one of the build-in layouts
    void
    setBuildInLayout (
            BuildInLay kind);

    //! Set the layout interface; ownership transfered to this instance.
    void
    setLay (
        LayoutInterf * value) {
        lay_ = value;
        update ();
    }

    //! Get the layout interface.
    LayoutInterf *
    lay () const {
        return lay_;
    }

    //! Take ownership of the layout interface.
    LayoutInterf *
    takeLay () {
        LayoutInterf * tmp = lay_;
        lay_ = NULL;
        return tmp;
    }



protected:

    //! A grip informs us that it had been moved
    QPoint
    gripMode (
            ActiveGrip * grip,
            const QPoint & pos);

    void mousePressEvent (QMouseEvent *);
    void mouseReleaseEvent (QMouseEvent *);
    void mouseMoveEvent (QMouseEvent *);
    void paintEvent (QPaintEvent *);

private:
    QPixmap image_;
    QPoint offset_;
    LayoutInterf * lay_;
};

#endif // GUARD_IMAGESEL_H_INCLUDE
