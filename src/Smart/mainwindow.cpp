#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_0_clicked() {
  ui->result->setText(ui->result->text() + "0");
}

void MainWindow::on_pushButton_1_clicked() {
  ui->result->setText(ui->result->text() + "1");
}

void MainWindow::on_pushButton_2_clicked() {
  ui->result->setText(ui->result->text() + "2");
}

void MainWindow::on_pushButton_3_clicked() {
  ui->result->setText(ui->result->text() + "3");
}

void MainWindow::on_pushButton_4_clicked() {
  ui->result->setText(ui->result->text() + "4");
}

void MainWindow::on_pushButton_5_clicked() {
  ui->result->setText(ui->result->text() + "5");
}

void MainWindow::on_pushButton_6_clicked() {
  ui->result->setText(ui->result->text() + "6");
}

void MainWindow::on_pushButton_7_clicked() {
  ui->result->setText(ui->result->text() + "7");
}

void MainWindow::on_pushButton_8_clicked() {
  ui->result->setText(ui->result->text() + "8");
}

void MainWindow::on_pushButton_9_clicked() {
  ui->result->setText(ui->result->text() + "9");
}

void MainWindow::on_pushButton_dot_clicked() {
  ui->result->setText(ui->result->text() + ".");
}

void MainWindow::on_pushButton_plus_clicked() {
  ui->result->setText(ui->result->text() + "+");
}

void MainWindow::on_pushButton_minus_clicked() {
  ui->result->setText(ui->result->text() + "-");
}

void MainWindow::on_pushButton_mul_clicked() {
  ui->result->setText(ui->result->text() + "*");
}

void MainWindow::on_pushButton_div_clicked() {
  ui->result->setText(ui->result->text() + "/");
}

void MainWindow::on_pushButton_openB_clicked() {
  ui->result->setText(ui->result->text() + "(");
}

void MainWindow::on_pushButton_closeB_clicked() {
    QString input_str= ui->result->text().toLatin1();
    int open_count = 0;
    int close_count = 0;
    QString::const_iterator it = input_str.begin();
    for (; it != input_str.end(); ++it) {
        if (*it == '(') {
          ++open_count;
        }
        if (*it == ')') {
          ++close_count;
        }
    }
    if (open_count > close_count) {
  ui->result->setText(ui->result->text() + ")");
    }
}

void MainWindow::on_pushButton_AC_clicked() { ui->result->setText(""); }

void MainWindow::on_pushButton_pow_clicked() {
  ui->result->setText(ui->result->text() + "^(");
}

void MainWindow::on_pushButton_mod_clicked() {
  ui->result->setText(ui->result->text() + "mod");
}

void MainWindow::on_pushButton_sqrt_clicked() {
  ui->result->setText(ui->result->text() + "(sqrt(");
}

void MainWindow::on_pushButton_ln_clicked() {
  ui->result->setText(ui->result->text() + "(ln(");
}

void MainWindow::on_pushButton_log_clicked() {
  ui->result->setText(ui->result->text() + "(log(");
}

void MainWindow::on_pushButton_cos_clicked() {
  ui->result->setText(ui->result->text() + "(cos(");
}

void MainWindow::on_pushButton_sin_clicked() {
  ui->result->setText(ui->result->text() + "(sin(");
}

void MainWindow::on_pushButton_tan_clicked() {
  ui->result->setText(ui->result->text() + "(tan(");
}

void MainWindow::on_pushButton_acos_clicked() {
  ui->result->setText(ui->result->text() + "(acos(");
}

void MainWindow::on_pushButton_asin_clicked() {
  ui->result->setText(ui->result->text() + "(asin(");
}

void MainWindow::on_pushButton_atan_clicked() {
  ui->result->setText(ui->result->text() + "(atan(");
}

void MainWindow::on_pushButton_x_clicked() {
  ui->result->setText(ui->result->text() + "x");
}

void MainWindow::on_pushButton_eq_clicked() {
  char input_str[256];
  double x = ui->x_value->value();
  QByteArray byte = ui->result->text().toLatin1();
  strlcpy(input_str, byte, 256);
  double answer = m_proccesing(input_str, x);
  QString answerStr = QString::number(answer, 'g', 15);
  ui->result->setText(answerStr);
}

void MainWindow::on_pushButton_graph_clicked() {
    int X = ui->X->text().toInt();
    int Y = ui->Y->text().toInt();
  if (X != 0 && Y != 0) {
      QByteArray byte = (ui->result->text()).toLatin1();
      double step = ui->step->text().toDouble();
      graph *gr = new graph;
      gr->slot(byte, X, Y, step);
      gr->show();
      }
}

void MainWindow::on_pushButton_Credit_clicked() {
  credit *cr = new credit;
  cr->show();
}
