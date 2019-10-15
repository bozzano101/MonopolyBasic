#ifndef WELCOMEWINDOW_HPP
#define WELCOMEWINDOW_HPP

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class WelcomeWindow; }
QT_END_NAMESPACE

class WelcomeWindow : public QDialog
{
    Q_OBJECT

public:
    WelcomeWindow(QWidget *parent = nullptr);
    ~WelcomeWindow();

private:
    Ui::WelcomeWindow *ui;
};
#endif // WELCOMEWINDOW_HPP
