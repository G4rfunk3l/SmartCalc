#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "credit.h"
#include "graph.h"

#ifdef __cplusplus
extern "C" {
#endif
#include "../calculator.h"
#ifdef __cplusplus
}
#endif

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:

  void on_pushButton_0_clicked();

  void on_pushButton_1_clicked();

  void on_pushButton_2_clicked();

  void on_pushButton_3_clicked();

  void on_pushButton_4_clicked();

  void on_pushButton_5_clicked();

  void on_pushButton_6_clicked();

  void on_pushButton_7_clicked();

  void on_pushButton_8_clicked();

  void on_pushButton_9_clicked();

  void on_pushButton_dot_clicked();

  void on_pushButton_plus_clicked();

  void on_pushButton_minus_clicked();

  void on_pushButton_mul_clicked();

  void on_pushButton_div_clicked();

  void on_pushButton_openB_clicked();

  void on_pushButton_closeB_clicked();

  void on_pushButton_AC_clicked();

  void on_pushButton_pow_clicked();

  void on_pushButton_mod_clicked();

  void on_pushButton_sqrt_clicked();

  void on_pushButton_ln_clicked();

  void on_pushButton_log_clicked();

  void on_pushButton_cos_clicked();

  void on_pushButton_sin_clicked();

  void on_pushButton_tan_clicked();

  void on_pushButton_acos_clicked();

  void on_pushButton_asin_clicked();

  void on_pushButton_atan_clicked();

  void on_pushButton_x_clicked();

  void on_pushButton_eq_clicked();

  void on_pushButton_graph_clicked();

  void on_pushButton_Credit_clicked();

 private:
  Ui::MainWindow *ui;
};
#endif  // MAINWINDOW_H
