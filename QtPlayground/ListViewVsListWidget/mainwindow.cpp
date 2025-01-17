#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStringListModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initListView();
    initListWidget();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
QListView和QListWidget都是Qt中用于展示列表项的部件，但它们之间有一些关键的区别：

QListView 是更底层的部件，它提供了更多的定制性，但同时使用起来也更复杂。

QListWidget 是一个封装了QListView的简单类，它提供了一些预定义的功能，如插入、删除等，但自定义能力相对较弱。

如果你需要高度定制的列表视图（例如，需要使用自定义的delegate），你应该使用QListView。
如果你只需要一个简单的列表部件，并且不需要太多自定义，那么QListWidget可能会更方便。
*/

void MainWindow::initListView()
{
    QStringList stringList;
    stringList << "Item 1" << "Item 2" << "Item 3";

    static QStringListModel model(stringList); // 注意model不能是局部变量，否则界面中无内容

    ui->listView->setModel(&model);
}

void MainWindow::initListWidget()
{
    ui->listWidget->addItem("Item 1");
    ui->listWidget->addItem("Item 2");
    ui->listWidget->addItem("Item 3");
}
