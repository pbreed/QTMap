
#ifndef WP_H
#define WP_H

#include <QColor>
#include <QGraphicsItem>
#include <QListWidgetItem>


class WP : public QGraphicsItem
{
public:
    WP(int lat_off, int lon_off);

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
    qreal m_lat_off;
    qreal m_lon_off;
    int wpn;

public:
    void SetRow(QListWidgetItem *	item) {row=item; FixUpList();}
    QString GetCString();
    int GetLat();
    int GetLon();


  };

#endif // WP_H
