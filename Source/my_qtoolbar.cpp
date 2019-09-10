#include "my_qtoolbar.h"

my_qtoolbar::my_qtoolbar(QWidget *parent) :
    QToolBar(parent)
{

}

void my_qtoolbar::mouseMoveEvent(QMouseEvent *ev)
{
    if (isMoving)
    {
        QPoint diff = ev->pos() - pressPos;
        window()->move(window()->pos()+diff);
    }
}

void my_qtoolbar::mousePressEvent(QMouseEvent *ev)
{
    pressPos = ev->pos();
    isMoving = true;
}

void my_qtoolbar::mouseReleaseEvent(QMouseEvent *ev)
{
    isMoving = false;

}

