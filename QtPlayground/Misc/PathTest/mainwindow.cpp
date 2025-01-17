#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDir>
#include <QStandardPaths>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->label_currentPath_val->setText(QDir::currentPath());
    ui->label_homePath_val->setText(QDir::homePath());
    ui->label_rootPath_val->setText(QDir::rootPath());
    ui->label_tempPath_val->setText(QDir::tempPath());

    ui->label_applicationDirPath_val->setText(QApplication::applicationDirPath());
    ui->label_applicationDisplayName_val->setText(QApplication::applicationDisplayName());
    ui->label_applicationFilePath_val->setText(QApplication::applicationFilePath());
    ui->label_applicationName_val->setText(QApplication::applicationName());
    ui->label_desktopFileName_val->setText(QApplication::desktopFileName());

    ui->label_DesktopLocation_val->setText(
        QStandardPaths::writableLocation(QStandardPaths::DesktopLocation));
    ui->label_DocumentsLocation_val->setText(
        QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation));
    ui->label_FontsLocation_val->setText(
        QStandardPaths::writableLocation(QStandardPaths::FontsLocation));
    ui->label_ApplicationsLocation_val->setText(
        QStandardPaths::writableLocation(QStandardPaths::ApplicationsLocation));
    ui->label_MusicLocation_val->setText(
        QStandardPaths::writableLocation(QStandardPaths::MusicLocation));
    ui->label_MoviesLocation_val->setText(
        QStandardPaths::writableLocation(QStandardPaths::MoviesLocation));
    ui->label_PicturesLocation_val->setText(
        QStandardPaths::writableLocation(QStandardPaths::PicturesLocation));
    ui->label_TempLocation_val->setText(
        QStandardPaths::writableLocation(QStandardPaths::TempLocation));
    ui->label_HomeLocation_val->setText(
        QStandardPaths::writableLocation(QStandardPaths::HomeLocation));
    ui->label_AppLocalDataLocation_val->setText(
        QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation));
    ui->label_CacheLocation_val->setText(
        QStandardPaths::writableLocation(QStandardPaths::CacheLocation));
    ui->label_GenericCacheLocation_val->setText(
        QStandardPaths::writableLocation(QStandardPaths::GenericCacheLocation));
    ui->label_GenericDataLocation_val->setText(
        QStandardPaths::writableLocation(QStandardPaths::GenericDataLocation));
    ui->label_RuntimeLocation_val->setText(
        QStandardPaths::writableLocation(QStandardPaths::RuntimeLocation));
    ui->label_ConfigLocation_val->setText(
        QStandardPaths::writableLocation(QStandardPaths::ConfigLocation));
    ui->label_DownloadLocation_val->setText(
        QStandardPaths::writableLocation(QStandardPaths::DownloadLocation));
    ui->label_GenericConfigLocation_val->setText(
        QStandardPaths::writableLocation(QStandardPaths::GenericConfigLocation));
    ui->label_AppDataLocation_val->setText(
        QStandardPaths::writableLocation(QStandardPaths::AppDataLocation));
    ui->label_AppConfigLocation_val->setText(
        QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation));
    ui->label_PublicShareLocation_val->setText(
        QStandardPaths::writableLocation(QStandardPaths::PublicShareLocation));
    ui->label_TemplatesLocation_val->setText(
        QStandardPaths::writableLocation(QStandardPaths::TemplatesLocation));
}

MainWindow::~MainWindow()
{
    delete ui;
}
