#include "widget.h"
#include "ui_widget.h"
#include <QAction>
#include <QCloseEvent>
#include <QIcon>
#include <QMenu>
#include <QSystemTrayIcon>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // Tray Icon Setup
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->show();
    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this,
            SLOT(trayIconActivated(QSystemTrayIcon::ActivationReason)));

    QMenu *trayIconMenu = new QMenu(this);

    QAction *enableAction = new QAction(tr("&Enable"), this);
    enableAction->setCheckable(true);
    trayIconMenu->addAction(enableAction);

    QMenu *suspendMenu = new QMenu("&Suspend for", trayIconMenu);
    QAction *suspend30MinAction = new QAction(tr("&30 minutes"), this);
    QAction *suspend1HourAction = new QAction(tr("&1 hour"), this);
    QAction *suspend2HoursAction = new QAction(tr("&2 hours"), this);
    suspendMenu->addAction(suspend30MinAction);
    suspendMenu->addAction(suspend1HourAction);
    suspendMenu->addAction(suspend2HoursAction);
    trayIconMenu->addMenu(suspendMenu);

    QAction *autostartAction = new QAction(tr("&Autostart"), this);
    autostartAction->setCheckable(true);
    trayIconMenu->addAction(autostartAction);

    QAction *infoAction = new QAction(tr("&Info"), this);
    trayIconMenu->addAction(infoAction);

    QAction *quitAction = new QAction(tr("&Quit"), this);
    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
    trayIconMenu->addAction(quitAction);

    trayIcon->setContextMenu(trayIconMenu);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::closeButtonClicked()
{
    hide();
}

void Widget::closeEvent(QCloseEvent *event) {
    hide();
    event->ignore();
}

void Widget::trayIconActivated(QSystemTrayIcon::ActivationReason reason) {
  Widget::showNormal();
}
