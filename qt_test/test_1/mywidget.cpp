#include "mywidget.h"
#include <QPushButton>
#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent)
{
    QPushButton * button = new QPushButton("OK", this);
    QPushButton * exit_button = new QPushButton("EXIT", this);
    QHBoxLayout *hlayout = new QHBoxLayout;
    QVBoxLayout *vlayout = new QVBoxLayout;
    setLayout(vlayout);
    vlayout->addStretch(1);
    vlayout->addLayout(hlayout);
    hlayout->addWidget(exit_button);
    hlayout->addWidget(button);
    hlayout->addStretch(1);
}


int main(int argc, char ** argv)
{
    QApplication app(argc, argv);

    MyWidget w;
    w.show();
    return app.exec();
}
