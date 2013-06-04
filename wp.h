
#ifndef WP_H
#define WP_H

#include <QColor>
#include <QGraphicsItem>
#include <QListWidgetItem>
class MyScene;

class WP : public QGraphicsItem
{
public:
    WP();

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    QVariant itemChange(GraphicsItemChange change, const QVariant & value);
    void FixUpList();

private:

    QListWidgetItem * row;
    QColor color;
    QVector<QPointF> stuff;
public:
    void SetRow(QListWidgetItem *	item) {row=item; FixUpList();}
  };

#endif // CHIP_H
