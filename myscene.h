#ifndef MYSCENE_H
#define MYSCENE_H
#include <QFrame>
#include <QGraphicsView>

QT_BEGIN_NAMESPACE
class QLabel;
class QSlider;
class QToolButton;
QT_END_NAMESPACE

class MyScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit MyScene() {};
    
signals:
    
public slots:

protected:
    virtual void mousePressEvent ( QGraphicsSceneMouseEvent * mouseEvent );
    
};

#endif // MYSCENE_H
