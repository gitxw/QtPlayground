#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStandardItemModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initTreeView();
    initTreeWidget();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
QTreeView和QTreeWidget都用于在Qt中创建树形结构的视图，但它们之间有一些关键区别：

继承关系：QTreeView继承自QAbstractItemView，而QTreeWidget直接继承自QWidget。

使用灵活性：QTreeView更灵活，因为它需要手动设置数据模型，而QTreeWidget内部使用标准的数据模型。

自动排序：QTreeView需要手动实现排序，而QTreeWidget可以自动排序（需要设置一个标志）。

使用数据模型：QTreeView和QTreeWidget都可以使用自定义数据模型，但QTreeWidget使用的是基于项的数据模型，
            而QTreeView使用的是基于项的模型视图架构。

如果你需要更高级的模型视图支持或者需要更多的灵活性，QTreeView可能更适合。
如果你需要快速构建一个简单的树形结构并且不需要复杂的数据处理，QTreeWidget可能更方便。
*/

void MainWindow::initTreeView()
{
    static QStandardItemModel model(3, 0); // 创建一个3列的模型

    // 表头
    model.setHorizontalHeaderLabels(QStringList() << "列1" << "列2" << "列3");

    // 添加数据到模型
    for (int row = 0; row < 10; ++row) {
        for (int column = 0; column < 3; ++column) {
            QStandardItem *item = new QStandardItem(
                QString("Row %1, Column %2").arg(row).arg(column));
            model.setItem(row, column, item);
        }
    }

    // 创建树结构
    QStandardItem *item1 = new QStandardItem("Item 1");
    QStandardItem *item2 = new QStandardItem("Item 2");
    QStandardItem *item1_1 = new QStandardItem("Item 1.1");
    QStandardItem *item1_2 = new QStandardItem("Item 1.2");

    model.appendRow(item1);
    model.appendRow(item2);
    item1->appendRow(item1_1);
    item1->appendRow(item1_2);

    ui->treeView->setModel(&model);
}

void MainWindow::initTreeWidget()
{
    // 表头
    ui->treeWidget->setHeaderLabels(QStringList() << "列1" << "列2" << "列3");

    // 添加数据到QTreeWidget
    for (int row = 0; row < 10; ++row) {
        QTreeWidgetItem *item = new QTreeWidgetItem();
        for (int column = 0; column < 3; ++column) {
            item->setText(column, QString("Row %1, Column %2").arg(row).arg(column));
        }
        ui->treeWidget->addTopLevelItem(item);
    }

    // 创建树结构
    QTreeWidgetItem *item1 = new QTreeWidgetItem({"Item 1"});
    QTreeWidgetItem *item2 = new QTreeWidgetItem({"Item 2"});
    QTreeWidgetItem *item1_1 = new QTreeWidgetItem({"Item 1.1"});
    QTreeWidgetItem *item1_2 = new QTreeWidgetItem({"Item 1.2"});

    ui->treeWidget->addTopLevelItem(item1);
    ui->treeWidget->addTopLevelItem(item2);
    item1->addChild(item1_1);
    item1->addChild(item1_2);
}
