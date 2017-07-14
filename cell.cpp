#include "cell.h"

Cell::Cell()
{
    alive = false;
    wereAlive = false;
    border = false;
    x = 0;
    y = 0;
}

void Cell::setCoordinates(int x_new, int y_new){
    x = x_new;
    y = y_new;
}

QRectF Cell::boundingRect() const{
    return QRectF(x,y,RECT_SIZE,RECT_SIZE);
}
void Cell::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    if(alive)
    {
        QPen pen(Qt::gray, 1);
        QBrush brush(Qt::red);
        painter->setPen(pen);
        painter->setBrush(brush);
        painter->drawRect(rect);
    }
    else
    {
        if (!wereAlive){
            QPen pen(Qt::gray, 1);
            painter->setPen(pen);
            painter->drawRect(rect);
        }else{
            QPen pen(Qt::gray, 1);
            QBrush brush(Qt::lightGray);
            painter->setPen(pen);
            painter->setBrush(brush);
            painter->drawRect(rect);
        }
    }
}

void Cell::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!border) alive = !alive;
    update();
    QGraphicsItem::mousePressEvent(event);
}

