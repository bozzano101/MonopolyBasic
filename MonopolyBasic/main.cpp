#include "welcomewindow.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WelcomeWindow w;
    w.show();
    return a.exec();
}
