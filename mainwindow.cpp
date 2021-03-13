#include "mainwindow.h"
#include "ui_mainwindow.h"

double first_number;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->zero_btn,SIGNAL(clicked()),this,SLOT(num_to_res()));
    connect(ui->one_btn,SIGNAL(clicked()),this,SLOT(num_to_res()));
    connect(ui->two_btn,SIGNAL(clicked()),this,SLOT(num_to_res()));
    connect(ui->three_btn,SIGNAL(clicked()),this,SLOT(num_to_res()));
    connect(ui->four_btn,SIGNAL(clicked()),this,SLOT(num_to_res()));
    connect(ui->five_btn,SIGNAL(clicked()),this,SLOT(num_to_res()));
    connect(ui->six_btn,SIGNAL(clicked()),this,SLOT(num_to_res()));
    connect(ui->seven_btn,SIGNAL(clicked()),this,SLOT(num_to_res()));
    connect(ui->eight_btn,SIGNAL(clicked()),this,SLOT(num_to_res()));
    connect(ui->nine_btn,SIGNAL(clicked()),this,SLOT(num_to_res()));
    connect(ui->sub_btn,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->add_btn,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->mult_btn,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->divide_btn,SIGNAL(clicked()),this,SLOT(operations()));

    ui->sub_btn->setCheckable(true);
    ui->add_btn->setCheckable(true);
    ui->mult_btn->setCheckable(true);
    ui->divide_btn->setCheckable(true);

    this->setWindowTitle("Calculator");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::num_to_res()
{
    QPushButton *btn = (QPushButton *)sender();

    double all_nums;
    QString res;

    if (ui->output->text().contains(".") && btn->text() == "0")
    {
        res = ui->output->text() + btn->text();
    }
    else
    {
        all_nums = (ui->output->text() + btn->text()).toDouble();
        res = QString::number(all_nums, 'g', 15);
    }

    ui->output->setText(res);
}

void MainWindow::operations()
{
    QPushButton *btn = (QPushButton *)sender();
    btn->setChecked(true);

    first_number = ui->output->text().toDouble();

    ui->output->setText("");
}

void MainWindow::on_clear_btn_clicked()
{
    first_number = 0;
    ui->output->setText("0");
}

void MainWindow::on_dot_btn_clicked()
{
    if (!ui->output->text().contains("."))
    {
        ui->output->setText(ui->output->text() + ".");
    }
}

void MainWindow::on_calc_btn_clicked()
{
    double res_number, second_number;
    QString res;

    second_number = ui->output->text().toDouble();

    if (ui->sub_btn->isChecked())
    {
        res_number = first_number - second_number;
        res = QString::number(res_number, 'g', 15);

        ui->output->setText(res);

        ui->sub_btn->setChecked(false);
    }
    else if (ui->add_btn->isChecked())
    {
        res_number = first_number + second_number;
        res = QString::number(res_number, 'g', 15);

        ui->output->setText(res);

        ui->add_btn->setChecked(false);
    }
    else if (ui->mult_btn->isChecked())
    {
        res_number = first_number * second_number;
        res = QString::number(res_number, 'g', 15);

        ui->output->setText(res);

        ui->mult_btn->setChecked(false);
    }
    else if (ui->divide_btn->isChecked())
    {
        if (!(second_number == 0))
        {
            res_number = first_number / second_number;
            res = QString::number(res_number, 'g', 15);

            ui->output->setText(res);

            ui->divide_btn->setChecked(false);
        }
        else {
            ui->output->setText("0");

            ui->divide_btn->setChecked(false);
        }
    }
}
