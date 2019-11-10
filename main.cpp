#include "welcomewindow.hpp"
#include "gamewindow.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameWindow gw;
    WelcomeWindow w;
    w.setGameWindowPtr(&gw);
    w.show();
    return a.exec();
}
