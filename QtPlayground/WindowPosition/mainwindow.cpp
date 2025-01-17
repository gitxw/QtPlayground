#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::slotTimerUpdateUI);
    timer->start(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString QRectToQString(const QRect &rc)
{
    return QString("(%1,%2,%3,%4)").arg(rc.x()).arg(rc.y()).arg(rc.width()).arg(rc.height());
}

QString QPointToQString(const QPoint &pt)
{
    return QString("(%1,%2)").arg(pt.x()).arg(pt.y());
}

QString QSizeToQString(const QSize &sz)
{
    return QString("(%1,%2)").arg(sz.width()).arg(sz.height());
}

void MainWindow::slotTimerUpdateUI()
{
    /// QWidget中关于位置的方法：
    // QRect frameGeometry() const;
    // const QRect &geometry() const;
    // QRect normalGeometry() const;
    // int x() const;
    // int y() const;
    // QPoint pos() const;
    // QSize frameSize() const;
    // QSize size() const;
    // inline int width() const;
    // inline int height() const;
    // inline QRect rect() const;
    // QRect childrenRect() const;
    // QRegion childrenRegion() const;

    ui->label_frameGeometry_val->setText(QRectToQString(this->frameGeometry()));
    ui->label_geometry_val->setText(QRectToQString(this->geometry()));
    ui->label_normalGeometry_val->setText(QRectToQString(this->normalGeometry()));
    ui->label_x_val->setText(QString::number(this->x()));
    ui->label_y_val->setText(QString::number(this->y()));
    ui->label_pos_val->setText(QPointToQString(this->pos()));
    ui->label_frameSize_val->setText(QSizeToQString(this->frameSize()));
    ui->label_size_val->setText(QSizeToQString(this->size()));
    ui->label_width_val->setText(QString::number(this->width()));
    ui->label_height_val->setText(QString::number(this->height()));
    ui->label_rect_val->setText(QRectToQString(this->rect()));
    ui->label_childrenRect_val->setText(QRectToQString(this->childrenRect()));
    ui->label_childrenRegion_val->setText(QRectToQString(this->childrenRegion().boundingRect()));
}
