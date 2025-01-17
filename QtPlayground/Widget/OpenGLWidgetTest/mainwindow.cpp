#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>
#include <QDir>

/*
本程序使用QOpenGLWidget快速的显示图像，由于该控件使用GPU资源，
帧率比使用CPU有巨大的提升，同时可显著降低CPU的使用率。

实测核显能到70～100fps；独显能到200fps
*/

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 需要提前将_TestData/30M_images拷贝到程序运行路径下
    QString img_dir = QDir::cleanPath(QApplication::applicationDirPath() + "/30M_images");
    QImage img_1(QDir::cleanPath(img_dir + "/right01.jpg"));
    QImage img_6(QDir::cleanPath(img_dir + "/right06.jpg"));
    QImage img_7(QDir::cleanPath(img_dir + "/right07.jpg"));
    QImage img_8(QDir::cleanPath(img_dir + "/right08.jpg"));
    m_img_list.emplaceBack(img_1);
    m_img_list.emplaceBack(img_6);
    m_img_list.emplaceBack(img_7);
    m_img_list.emplaceBack(img_8);

    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &MainWindow::slotTimerUpdateUI);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotTimerUpdateUI()
{
    static int index = 0;
    // 播放图像
    ui->openGLWidget->setImage(m_img_list[index++]);
    if (index >= m_img_list.size()) {
        index = 0;
    }
    // 统计并显示总FPS
    m_played_count++;
    int fps = m_played_count * 1000 / m_et.elapsed();
    ui->label_fps->setText("fps:" + QString::number(fps));
}

void MainWindow::on_pushButton_start_clicked()
{
    m_played_count = 0;
    m_et.start();
    m_timer->start(1); // 使用1ms的Timer
}

void MainWindow::on_pushButton_stop_clicked()
{
    m_timer->stop();
}
