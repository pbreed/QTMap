
#include "chip.h"
#include "mainwindow.h"
#include "view.h"
#include "myscene.h"
#include <QFrame>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

  void MyScene::mousePressEvent ( QGraphicsSceneMouseEvent * mE )
  {
      Qt::MouseButton b= mE->button();
      if(b==Qt::RightButton)
      {
      QPointF p=mE->buttonDownScenePos(b);
      int xx=p.x();
      int yy=p.y();

      QColor color(255,0,0);
      QGraphicsItem *item = new Chip(color, xx, yy);
      item->setPos(p);
      addItem(item);
      }
   else
        QGraphicsScene::mousePressEvent(mE);
  }

