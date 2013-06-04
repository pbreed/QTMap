#ifndef MYSCENE_H
#define MYSCENE_H
#include <QFrame>
#include <QGraphicsView>

QT_BEGIN_NAMESPACE
class QLabel;
class QSlider;
class QToolButton;
QT_END_NAMESPACE

class MainWindow;
class WP;

class MyScene : public QGraphicsScene
{
    Q_OBJECT
    
signals:
    
public slots:

protected:
    MainWindow * m_pParrent;
    virtual void mousePressEvent ( QGraphicsSceneMouseEvent * mouseEvent );
public:
    MyScene(MainWindow * pParent) {m_pParrent=pParent;};

};

#endif // MYSCENE_H
