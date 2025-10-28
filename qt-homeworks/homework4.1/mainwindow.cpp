#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Виджеты");
    ui->groupBox->setTitle("Групповое поле");
    ui->radioButton->setText("Кнопка 1");
    ui->radioButton_2->setText("Кнопка 2");

    for (int i = 0; i < 10; i++) {
        ui->comboBox->addItem("Элемент " + QString::number(i + 1));
    }

    ui->pushButton->setText("Нажми на кнопку - получишь результат");
    ui->pushButton->setCheckable(true);

    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(10);
    ui->progressBar->setValue(0);

    ui->progressBar->setStyleSheet("QProgressBar {"
                                   "    text-align: center;"
                                   "}"
                                   "     QProgressBar::chunk {"
                                   "    background-color: skyblue;"
                                   "}");
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_clicked(bool checked)
{
    if (ui->progressBar->value() < ui->progressBar->maximum()) {
        ui->progressBar->setValue(ui->progressBar->value() + 1);
    }
    else {
        ui->progressBar->setValue(0);
    }
}

