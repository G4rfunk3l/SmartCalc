#ifndef GRAPH_H
#define GRAPH_H

#include <QDialog>
#include <QVector>
#include <QWidget>

#include "qcustomplot.h"

#ifdef __cplusplus
extern "C" {
#endif
#include "../calculator.h"
#ifdef __cplusplus
}
#endif

namespace Ui {
class graph;
}

class graph : public QDialog {
  Q_OBJECT

 public:
  void slot(QString s, int X, int Y, double step);
  explicit graph(QWidget *parent = nullptr);
  ~graph();

 private:
  Ui::graph *ui;
};

#endif  // GRAPH_H
