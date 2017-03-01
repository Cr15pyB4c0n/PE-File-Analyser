#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    setFixedSize(600, 400);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QString PEFilePath = QDir::toNativeSeparators(QFileDialog::getOpenFileName(this, tr("Select a PE-File to analyse"), QDir::currentPath(), tr("PE File (*.exe *.dll)")));

    std::ifstream PEFileStream(PEFilePath.toStdString(), std::fstream::binary);

    std::string ss = PEFilePath.toStdString();
}

void MainWindow::on_actionQuit_triggered()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Quit?", "Are you sure, that you want to quit?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        QApplication::quit();
    } else {

    }
}
