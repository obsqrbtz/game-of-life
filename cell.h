#ifndef CELL_H
#define CELL_H

#include <QPainter>
#include <QGraphicsItem>
#include <QObject>

class Cell :public QGraphicsItem, public QObject
{
public:
    Cell(int xNew, int yNew, int cellSizeNew);
    //void setCoordinates(int x_new, int y_new);
    QRectF boundingRect() const;
    void paint(QPainter * painter,
                   const QStyleOptionGraphicsItem * option,
                   QWidget * widget);
    bool alive;
    bool wereAlive;
    bool border;
    int x, y;
    int cellSize;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // CELL_H
