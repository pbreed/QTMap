
#include "wp.h"
#include "myscene.h"
#include <QtWidgets>

WP::WP()
{
   static int zn;
    this->color = QColor(255,0,0);
    setZValue(zn++);
    setFlags(ItemIsSelectable | ItemIsMovable|ItemSendsScenePositionChanges);

    setAcceptHoverEvents(true);
    row=NULL;
}

QRectF WP::boundingRect() const
{
    return QRectF(-50, -50, 100, 100);
}

QPainterPath WP::shape() const
{
    QPainterPath path;
    path.addRect(-50,-50, 100, 100);
    return path;
}

void WP::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    QColor fillColor = (option->state & QStyle::State_Selected) ? color.dark(150) : color;
    
	if (option->state & QStyle::State_MouseOver) fillColor = fillColor.light(125);

    const qreal lod = option->levelOfDetailFromTransform(painter->worldTransform());
    if (lod < 0.2) {
        if (lod < 0.125) {
            painter->setBrush(fillColor);
            painter->fillRect(QRectF(-50, -50, 100, 100), fillColor);
            return;
        }

        QPen p = painter->pen();
        QPen mp(fillColor);
        mp.setWidth(8);
        painter->setPen(mp);
        painter->drawLine(-50,-50,50,50);
		painter->drawLine(-50,50,50,-50);
        painter->setPen(p);
        return;
    }

    QPen p = painter->pen();
    QPen mp(fillColor);
    if(lod<0.5)
        mp.setWidth(4);
    else
        if(lod<1)
            mp.setWidth(2);

     painter->setPen(mp);
     painter->drawLine(-50,-50,50,50);
	painter->drawLine(-50,50,50,-50);
    painter->setPen(p);
    return;
    
/*
    // Draw red ink
    if (stuff.size() > 1) {
        QPen p = painter->pen();
        painter->setPen(QPen(Qt::red, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
        painter->setBrush(Qt::NoBrush);
        QPainterPath path;
        path.moveTo(stuff.first());
        for (int i = 1; i < stuff.size(); ++i)
            path.lineTo(stuff.at(i));
        painter->drawPath(path);
        painter->setPen(p);

    }*/
}

void WP::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mousePressEvent(event);
    update();
}

void WP::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->modifiers() & Qt::ShiftModifier) {
        stuff << event->pos();
        update();
        return;
    }
    QGraphicsItem::mouseMoveEvent(event);
}

void WP::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseReleaseEvent(event);
    update();
    FixUpList();

}

void WP::FixUpList()
{
    QString s=QString::number(this->x())+","+QString::number(this->y());
    if(row) row->setText(s);

}

 QVariant WP::itemChange(GraphicsItemChange change, const QVariant & value)
 {
     if (change == ItemPositionChange && scene())
     {
            // value is the new position.
            QPointF newPos = value.toPointF();
            FixUpList();
     }
     return QGraphicsItem::itemChange(change, value);
 }
