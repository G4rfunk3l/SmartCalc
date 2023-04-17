#include "credit.h"

#include "ui_credit.h"

credit::credit(QWidget *parent) : QDialog(parent), ui(new Ui::credit) {
  ui->setupUi(this);
}

credit::~credit() { delete ui; }

void credit::on_pushButton_credit_clicked() {
  double amount_of_credit = ui->amount->value();
  int type_of_term = ui->type_of_term->value();
  int term = ui->term->value();
  double interest_rate = ui->interest_rate->value();
  int type_of_credit = ui->type_of_credit->value();
  double monthly_payment = 0.0;
  double overpayment = 0.0;
  double total_payment = 0.0;
  double first_payment = 0.0;
  double monthly_interest_rate = interest_rate / (100 * 12);
  QString monthly_payment_str;
  if (type_of_term == 1) {
    term *= 12;
  }
  if (type_of_credit == 1) {
    monthly_payment = (amount_of_credit * monthly_interest_rate) /
                      (1 - pow(1 + monthly_interest_rate, term * (-1.0)));
    monthly_payment *= 100;
    monthly_payment = lround(monthly_payment);
    monthly_payment /= 100;
    total_payment = monthly_payment * term;
    overpayment = total_payment - amount_of_credit;
    overpayment *= 100;
    overpayment = lround(overpayment);
    overpayment /= 100;
    monthly_payment_str = QString::number(monthly_payment, 'f', 2);
  } else {
    double main_payment = amount_of_credit / term;
    double percent_payment = 0;
    double loan_credit = amount_of_credit;
    first_payment = main_payment + loan_credit * monthly_interest_rate;
    while (loan_credit > 0) {
      percent_payment = loan_credit * monthly_interest_rate;
      monthly_payment = main_payment + percent_payment;
      loan_credit -= main_payment;
      total_payment += monthly_payment;
    }
    monthly_payment_str = QString::number(first_payment, 'f', 2) + " ... " +
                          QString::number(monthly_payment, 'f', 2);
    overpayment = total_payment - amount_of_credit;
  }
  QString overpayment_str = QString::number(overpayment, 'f', 2);
  QString total_payment_str = QString::number(total_payment, 'f', 2);
  ui->monthly_payment->setText(monthly_payment_str);
  ui->overpayment->setText(overpayment_str);
  ui->total_payment->setText(total_payment_str);
}
