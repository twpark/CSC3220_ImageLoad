#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    loadImage();
}

void MainWindow::loadImage() {
    QString bearFileName = "images/bears.jpg";

    if(imageBears.load(bearFileName)) {
        std::cout << "Bear image loaded successfully" << std::endl;
        imageBears = imageBears.scaled(ui->label->size(), Qt::KeepAspectRatioByExpanding);
    }

    ui->label->setPixmap(imageBears);
}

MainWindow::~MainWindow()
{
    delete ui;
}
