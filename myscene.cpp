
#include "wp.h"
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
      //QColor color(255,0,0);
      WP *item = new WP();
      item->setPos(p);
      addItem(item);
      m_pParrent->AddWP(item);
      }
   else
        QGraphicsScene::mousePressEvent(mE);
  }

