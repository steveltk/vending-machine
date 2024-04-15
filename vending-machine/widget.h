#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    int money{0};
    void ChangeMoney(int diff);

private slots:
    void on_pbCOIN10_clicked();

    void on_pbCOIN50_clicked();

    void on_pbCOIN100_clicked();

    void on_pbCOIN500_clicked();

    void on_pbCoffee100_clicked();

    void on_pbTea150_clicked();

    void on_pbMilk200_clicked();

    void on_pbReset_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
