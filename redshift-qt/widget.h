#ifndef WIDGET_H
#define WIDGET_H

#include <QSystemTrayIcon>
#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget {
  Q_OBJECT

public:
  explicit Widget(QWidget *parent = 0);
  ~Widget();

protected:
  void closeEvent(QCloseEvent *event);

private slots:
  void closeButtonClicked();
  void trayIconActivated(QSystemTrayIcon::ActivationReason reason);

private:
  Ui::Widget *ui;
  QSystemTrayIcon *trayIcon;
};

#endif // WIDGET_H
