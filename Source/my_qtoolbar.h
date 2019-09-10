#ifndef MY_QTOOLBAR_H
#define MY_QTOOLBAR_H

#include <QToolBar>
#include <QWidget>
#include <QMouseEvent>
#include <QDebug>
#include <QEvent>
#include <mainwindow.h>
#include <QtWidgets>

class my_qtoolbar : public QToolBar
{
    Q_OBJECT
public:
    explicit my_qtoolbar(QWidget *parent = 0);

    void mouseMoveEvent(QMouseEvent *ev);
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
    QPoint pressPos;
    bool isMoving{false};


signals:
    void Mouse_Pressed();
    void Mouse_Pos();
    void Mouse_Left();

public slots:

};

#endif // MY_QTOOLBAR_H
