/****************************************************************************
**
** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the demonstration applications of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/


#include "mainwindow.h"
#include "view.h"
#include "myscene.h"
#include "wp.h"

#include <QHBoxLayout>
#include <QSplitter>
#include <QtWidgets>
#include <QClipboard>

MainWindow::MainWindow()
{
    Holder = new QWidget(this);
    setCentralWidget(Holder);
    Lat_Off=0;
    Lon_Off=0;

    populateScene();
/*
    h1Splitter = new QSplitter;
    h2Splitter = new QSplitter;
    
    QSplitter *vSplitter = new QSplitter;
    vSplitter->setOrientation(Qt::Vertical);
    vSplitter->addWidget(h1Splitter);
    vSplitter->addWidget(h2Splitter);

    View *view = new View("Top left view");
    view->view()->setScene(scene);
    h1Splitter->addWidget(view);

    view = new View("Top right view");
    view->view()->setScene(scene);
    h1Splitter->addWidget(view);

    view = new View("Bottom left view");
    view->view()->setScene(scene);
    h2Splitter->addWidget(view);

    view = new View("Bottom right view");
    view->view()->setScene(scene);
    h2Splitter->addWidget(view);
*/
    View * view = new View("One view");
    view->view()->setScene(scene);
    //h2Splitter->addWidget(view);

     List = new  QListWidget(this);

    QSplitter *vSplitter = new QSplitter;
    vSplitter->setOrientation(Qt::Vertical);
    vSplitter->addWidget(view);
    vSplitter->addWidget(List);


    QHBoxLayout *layout = new QHBoxLayout;
    //layout->addWidget(vSplitter);
    layout->addWidget(vSplitter);

    Holder->setLayout(layout);

    setWindowTitle(tr("MAP"));

    createActions();
    createMenus();
    createToolBars();
    createStatusBar();

    readSettings();

    setCurrentFile("");
    setUnifiedTitleAndToolBarOnMac(true);

}




void MainWindow::populateScene()
{
    scene = new MyScene(this);


    int nitems = 0;
    // Populate scene
    for(int i=-10000; i<10000; i+=100)
    {
        QGraphicsItem * item= new QGraphicsLineItem(-10000,i,10000,i);
        scene->addItem(item);
        ++nitems;
        item= new QGraphicsLineItem(i,-10000,i,10000);
        scene->addItem(item);
        ++nitems;
     }

        QPen * pQp=new QPen(QColor(0,255,0));

        pQp->setWidth(25);




  /*  int xx = 0;
    int nitems = 0;
    for (int i = -11000; i < 11000; i += 110) {
        ++xx;
        int yy = 0;
        for (int j = -7000; j < 7000; j += 70) {
            ++yy;
            qreal x = (i + 11000) / 22000.0;
            qreal y = (j + 7000) / 14000.0;

            QColor color(image.pixel(int(image.width() * x), int(image.height() * y)));
            QGraphicsItem *item = new Chip(color, xx, yy);
            item->setPos(QPointF(i, j));
            scene->addItem(item);

            ++nitems;
        }
    }
    */
}

void MainWindow::closeEvent(QCloseEvent *event)
//! [3] //! [4]
{
    if (maybeSave()) {
        writeSettings();
        event->accept();
    } else {
        event->ignore();
    }
}
//! [4]

//! [5]
void MainWindow::newFile()
//! [5] //! [6]
{
    if (maybeSave()) {
        setCurrentFile("");
    }
}
//! [6]

//! [7]
void MainWindow::open()
//! [7] //! [8]
{
    if (maybeSave()) {
         QString fileName = QFileDialog::getOpenFileName(this,QString("File to Open"),m_LastPath);
        if (!fileName.isEmpty()) loadFile(fileName);
    }
}
//! [8]

//! [9]
bool MainWindow::save()
//! [9] //! [10]
{
    if (curFile.isEmpty()) {
        return saveAs();
    } else {
        return saveFile(curFile);
    }
}
//! [10]

//! [11]
bool MainWindow::saveAs()
//! [11] //! [12]
{
    QString fileName = QFileDialog::getSaveFileName(this);
    if (fileName.isEmpty())
        return false;

    return saveFile(fileName);
}
//! [12]

//! [13]
void MainWindow::about()
//! [13] //! [14]
{
   QMessageBox::about(this, tr("About Application"),
            tr("The <b>Application</b> example demonstrates how to "
               "write modern GUI applications using Qt, with a menu bar, "
               "toolbars, and a status bar."));
}
//! [14]

//! [15]
void MainWindow::documentWasModified()
//! [15] //! [16]
{
    //setWindowModified(textEdit->document()->isModified());
}
//! [16]

//! [17]
void MainWindow::createActions()
//! [17] //! [18]
{
    newAct = new QAction(QIcon(":/images/new.png"), tr("&New"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Create a new file"));
    connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));

//! [19]
    openAct = new QAction(QIcon(":/images/open.png"), tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open an existing file"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

    openTrackAct = new QAction(QIcon(":/images/opentrack.png"), tr("Open&Track..."), this);
    openTrackAct->setStatusTip(tr("Open a track file"));
    connect(openTrackAct, SIGNAL(triggered()), this, SLOT(openTrack()));


//! [18] //! [19]

    saveAct = new QAction(QIcon(":/images/save.png"), tr("&Save"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save the document to disk"));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));

    saveAsAct = new QAction(tr("Save &As..."), this);
    saveAsAct->setShortcuts(QKeySequence::SaveAs);
    saveAsAct->setStatusTip(tr("Save the document under a new name"));
    connect(saveAsAct, SIGNAL(triggered()), this, SLOT(saveAs()));

//! [20]
    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
//! [20]
    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

//! [21]
    cutAct = new QAction(QIcon(":/images/cut.png"), tr("Cu&t"), this);
//! [21]
    cutAct->setShortcuts(QKeySequence::Cut);
    cutAct->setStatusTip(tr("Cut the current selection's contents to the clipboard"));
    //connect(cutAct, SIGNAL(triggered()), textEdit, SLOT(cut()));

    copyAct = new QAction(QIcon(":/images/copy.png"), tr("&Copy"), this);
    copyAct->setShortcuts(QKeySequence::Copy);
    copyAct->setStatusTip(tr("Copy the current selection's contents to the clipboard"));
    connect(copyAct, SIGNAL(triggered()), this, SLOT(copy()));

    pasteAct = new QAction(QIcon(":/images/paste.png"), tr("&Paste"), this);
    pasteAct->setShortcuts(QKeySequence::Paste);
    pasteAct->setStatusTip(tr("Paste the clipboard's contents into the current "
                              "selection"));
    //connect(pasteAct, SIGNAL(triggered()), textEdit, SLOT(paste()));

    aboutAct = new QAction(tr("&About"), this);
    aboutAct->setStatusTip(tr("Show the application's About box"));
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

//! [22]
    aboutQtAct = new QAction(tr("About &Qt"), this);
    aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
//! [22]

//! [23]
    cutAct->setEnabled(false);
//! [23] //! [24]
    copyAct->setEnabled(false);
    //connect(textEdit, SIGNAL(copyAvailable(bool)),  cutAct, SLOT(setEnabled(bool)));
    //connect(textEdit, SIGNAL(copyAvailable(bool)), copyAct, SLOT(setEnabled(bool)));

}
//! [24]

//! [25] //! [26]
void MainWindow::createMenus()
//! [25] //! [27]
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
//! [28]
    fileMenu->addAction(openAct);
    fileMenu->addAction(openTrackAct);
//! [28]
    fileMenu->addAction(saveAct);
//! [26]
    fileMenu->addAction(saveAsAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(cutAct);
    editMenu->addAction(copyAct);
    editMenu->addAction(pasteAct);

    menuBar()->addSeparator();

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);
}
//! [27]

//! [29] //! [30]
void MainWindow::createToolBars()
{
    fileToolBar = addToolBar(tr("File"));
    fileToolBar->addAction(newAct);
//! [29] //! [31]
    fileToolBar->addAction(openAct);
    fileToolBar->addAction(openTrackAct);
//! [31]
    fileToolBar->addAction(saveAct);

    editToolBar = addToolBar(tr("Edit"));
    editToolBar->addAction(cutAct);
    editToolBar->addAction(copyAct);
    editToolBar->addAction(pasteAct);
}
//! [30]

//! [32]
void MainWindow::createStatusBar()
//! [32] //! [33]
{
    statusBar()->showMessage(tr("Ready"));
}
//! [33]

//! [34] //! [35]
void MainWindow::readSettings()
//! [34] //! [36]
{
    QSettings settings("QtProject", "Application Example");
    QPoint pos = settings.value("pos", QPoint(200, 200)).toPoint();
    QSize size = settings.value("size", QSize(400, 400)).toSize();
    QString s=   settings.value("lastpath",QString("C:\\")).toString();
    m_LastPath=s;
    resize(size);
    move(pos);
}
//! [35] //! [36]

//! [37] //! [38]
void MainWindow::writeSettings()
//! [37] //! [39]
{
    QSettings settings("QtProject", "Application Example");
    settings.setValue("pos", pos());
    settings.setValue("size", size());
    settings.setValue("lastpath",m_LastPath);
}
//! [38] //! [39]

//! [40]
bool MainWindow::maybeSave()
//! [40] //! [41]
{
 /*   if (textEdit->document()->isModified()) {
        QMessageBox::StandardButton ret;
        ret = QMessageBox::warning(this, tr("Application"),
                     tr("The document has been modified.\n"
                        "Do you want to save your changes?"),
                     QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        if (ret == QMessageBox::Save)
            return save();
        else if (ret == QMessageBox::Cancel)
            return false;
    }
   */
    return true;
}
//! [41]

//! [42]
void MainWindow::loadFile(const QString &fileName)
//! [42] //! [43]
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly)) {
        QMessageBox::warning(this, tr("Application"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return;
    }

    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File loaded"), 2000);

    QDataStream in(&file);
    QString s;
    in>>s;
    if(s!="URMAPFILE")
    {
        QMessageBox::warning(this, tr("Application"),
                             tr("Cannot read file %1:\n Wrong format.%2")
                             .arg(fileName).arg(s));
        return;
    }

    int n;
    in>>n;
    for(int i=0; i<n; i++)
    {
    QList<int> * List = new QList<int>;
    in>>*List;
    Tracks.append(List);
    ReadList(*List);
    }
    in >>n;
    for(int i=0; i<n; i++)
    {
     int lat,lon;
     in>>lat;
     in>>lon;
     WP *item = new WP(GetLatOff(),GetLonOff());
     QPointF  p((lon-GetLonOff()),-(lat-GetLatOff()));
     item->setPos(p);
     scene->addItem(item);
     AddWP(item);
    }

}
//! [43]

//! [44]
bool MainWindow::saveFile(const QString &fileName)
//! [44] //! [45]
{
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly)) {
        QMessageBox::warning(this, tr("Application"),
                             tr("Cannot write file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return false;
    }

    QDataStream out(&file);
    QString s="URMAPFILE";
    out<<s;
    int n=Tracks.count();
    out<<n;
    for(int i=0; i<n; i++)
    {
        out<<*(Tracks.at(i));
    }

     out<< WPList.size();

    for (int i = 0; i < WPList.size(); ++i)
    {
      WP * pwp=WPList.at(i);
        out<<pwp->GetLat();
        out<<pwp->GetLon();
    }

    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File saved"), 2000);
    return true;
}
//! [45]

//! [46]
void MainWindow::setCurrentFile(const QString &fileName)
//! [46] //! [47]
{
    curFile = fileName;
//    textEdit->document()->setModified(false);
    setWindowModified(false);

    QString shownName = curFile;
    if (curFile.isEmpty())
        shownName = "untitled.txt";
    setWindowFilePath(shownName);
}
//! [47]

//! [48]
QString MainWindow::strippedName(const QString &fullFileName)
//! [48] //! [49]
{
    return QFileInfo(fullFileName).fileName();
}
//! [49]




void MainWindow::AddWP(WP *p)
{
    WPList.append(p);
    QListWidgetItem * pi=new QListWidgetItem("");
     List->addItem(pi);
     p->SetRow(pi);
     copyAct->setEnabled(true);

}


  void MainWindow::ReadList(QList<int> &list)
  {
      int np=0;
      int llat;int llon;

      static int listnum;
      QPen qp;
      switch(listnum++)
      {
      case 0:qp=QPen(QColor(0,255,0)); break;
      case 1:qp=QPen(QColor(0,0,255)); break;
      case 2:qp=QPen(QColor(0,255,255)); break;
      case 3:qp=QPen(QColor(255,255,0)); break;
      case 4:qp=QPen(QColor(255,0,255)); break;
      default:
             qp=QPen(QColor(0,0,0)); break;
      }


      qp.setWidth(25);
      for(int i=0; i<list.count(); i+=2)
      {int lat=list.at(i);
          int lon=list.at(i+1);

          if(Lat_Off==0)
          {
              Lat_Off=lat;
              Lon_Off=lon;
          }
           if(np)
             {
                int x1=lon-Lon_Off;
                int x2=llon-Lon_Off;
                int y1=Lat_Off-lat;
                int y2=Lat_Off-llat;
                 QGraphicsLineItem * item= new QGraphicsLineItem(x1,y1,x2,y2);
                 item->setPen(qp);
                 scene->addItem(item);
              }
             np++;
             llat=lat;
             llon=lon;
      }

  }

void MainWindow::loadTrack(const QString &fileName)
{   QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Application"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return;
    }

    statusBar()->showMessage(tr("Track loaded"), 2000);

    QList<int> * List = new QList<int>;

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();

        {int lat; int lon;
            int n;
            n=sscanf(line.toLatin1(),"%d,%d",&lat,&lon);
            if(n==2)
            {
                List->append(lat);
                List->append(lon);


            }
        }

    }
    if(!List->isEmpty())
    {
        Tracks.append(List);
        ReadList(*List);
    }
    else
    {
     delete List;
    }

}


void MainWindow::openTrack()
{
        QString fileName = QFileDialog::getOpenFileName(this,QString("Track files"),m_LastPath);
     if (!fileName.isEmpty())
     { QFileInfo fileinfo(fileName);
       m_LastPath=fileinfo.filePath();
       loadTrack(fileName);
     }
}

void MainWindow::copy()
{
     QClipboard *clipboard = QApplication::clipboard();
     QString s="const int [][2]={\n";
     for (int i = 0; i < WPList.size(); ++i) {

          s+=WPList.at(i)->GetCString();
       }
     s+="\n{0,0}};\n";
    clipboard->setText(s);
}

