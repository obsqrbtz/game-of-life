#ifndef CELL_H
#define CELL_H

#include <QPainter>
#include <QGraphicsItem>
#include <QObject>

#define RECT_SIZE 10

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
    bool wereAlive;
    bool border;
    int x, y;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // CELL_H
