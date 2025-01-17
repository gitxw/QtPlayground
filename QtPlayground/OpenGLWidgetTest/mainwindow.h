#pragma once

#include <QElapsedTimer>
#include <QImage>
#include <QList>
#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_start_clicked();
    void on_pushButton_stop_clicked();
    void slotTimerUpdateUI();

private:
    Ui::MainWindow *ui;
    QList<QImage> m_img_list;
    QTimer *m_timer;
    QElapsedTimer m_et; // 经过时间统计
    int m_played_count; // 已经播放的帧数
};
