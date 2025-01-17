#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStandardItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initTableView();
    initTableWidget();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
QTableWidget是QTableView的子类，提供了静态编程的便利，但在实际使用中QTableView更灵活和强大。

项编辑能力：QTableWidget不能手动添加数据，只能通过编程方式添加QTableWidgetItem。而QTableView可以手动输入数据，也可以通过编程方式添加数据。

数据模型：QTableWidget使用内置的数据模型，而QTableView可以使用自定义的数据模型。

列头和行头自定义：QTableView可以自定义列头和行头，而QTableWidget则不能。

选择模式：QTableView可以设置不同的选择模式，而QTableWidget只能是单选。

信号和槽：QTableView发出的数据更改信号比QTableWidget发出的信号更多，更详细。

样式和主题：QTableView支持更多的样式和主题。

性能：由于QTableWidget的所有数据都在一开始就确定，因此它在内存和处理速度上可能不如QTableView。

在实际应用中，如果你需要编程地添加数据，自定义数据模型，或者需要更多的灵活性，你应该使用QTableView。
如果你只是需要一个简单的表格来显示和编辑数据，QTableWidget可能更方便。
*/

void MainWindow::initTableView()
{
    static QStandardItemModel model(5, 3);

    // 添加数据到模型
    for (int r = 0; r < 5; ++r) {
        for (int c = 0; c < 3; ++c) {
            QStandardItem *item = new QStandardItem(QString("Row %1, Column %2").arg(r).arg(c));
            model.setItem(r, c, item);
        }
    }

    ui->tableView->setModel(&model);
}

void MainWindow::initTableWidget()
{
    ui->tableWidget->setRowCount(5);
    ui->tableWidget->setColumnCount(3);

    for (int r = 0; r < 5; ++r) {
        for (int c = 0; c < 3; ++c) {
            auto item = new QTableWidgetItem(QString("Row %1, Column %2").arg(r).arg(c));
            ui->tableWidget->setItem(r, c, item);
        }
    }
}
