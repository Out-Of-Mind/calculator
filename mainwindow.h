#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void num_to_res();
    void operations();
    void on_clear_btn_clicked();
    void on_dot_btn_clicked();
    void on_calc_btn_clicked();
};
#endif // MAINWINDOW_H
