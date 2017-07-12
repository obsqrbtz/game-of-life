#ifndef CELL_H
#define CELL_H

#include <QPainter>
#include <QGraphicsItem>
#include <QObject>

class Cell :public QGraphicsItem, public QObject
{
public:
    Cell();
    void setCoordinates(int x_new, int y_new);
    QRectF boundingRect() const;
    void paint(QPainter * painter,
                   const QStyleOptionGraphicsItem * option,
                   QWidget * widget);
    bool alive;
    int x, y;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // CELL_H
