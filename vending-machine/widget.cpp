#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <string>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::ChangeMoney(int diff)
{
    money += diff;
    if(money < 0){
        money -=diff;
    }
    ui->lcdNumber->display(money);
    if (money < 100) {
        ui->pbCoffee100->setEnabled(false);
    }
    else {
        ui->pbCoffee100->setEnabled(true);
    }

    if (money < 150) {
        ui->pbTea150->setEnabled(false);
    }
    else {
        ui->pbTea150->setEnabled(true);
    }

    if (money < 200) {
        ui->pbMilk200->setEnabled(false);
    }
    else {
        ui->pbMilk200->setEnabled(true);
    }
}

void Widget::on_pbCOIN10_clicked()
{
    ChangeMoney(10);
}


void Widget::on_pbCOIN50_clicked()
{
    ChangeMoney(50);
}


void Widget::on_pbCOIN100_clicked()
{
    ChangeMoney(100);
}


void Widget::on_pbCOIN500_clicked()
{
    ChangeMoney(500);
}


void Widget::on_pbCoffee100_clicked()
{
    ChangeMoney(-100);
}


void Widget::on_pbTea150_clicked()
{
    ChangeMoney(-150);
}


void Widget::on_pbMilk200_clicked()
{
    ChangeMoney(-200);
}


void Widget::on_pbReset_clicked()
{
    QMessageBox mb;
    int c1 = money/500;
    ChangeMoney((-1)*c1*500);
    int c2 = money/100;
    ChangeMoney((-1)*c2*100);
    int c3 = money/50;
    ChangeMoney((-1)*c3*50);
    int c4 = money/10;
    ChangeMoney((-1)*c4*10);

    char content[50];
    sprintf(content, "500 coin: %d\n100 coin: %d\n50 coin: %d\n10 coin: %d", c1, c2, c3, c4);

    mb.information(this, "changes", content);
}


