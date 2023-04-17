#ifndef CREDIT_H
#define CREDIT_H

#include <QDialog>
#include <QWidget>
#include <cmath>

namespace Ui {
class credit;
}

class credit : public QDialog {
  Q_OBJECT

 public:
  credit(QWidget *parent = nullptr);
  ~credit();

 private slots:

  void on_pushButton_credit_clicked();

 private:
  Ui::credit *ui;
};
#endif  // CREDIT_H
