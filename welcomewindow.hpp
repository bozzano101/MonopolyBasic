#ifndef WELCOMEWINDOW_HPP
#define WELCOMEWINDOW_HPP

#include <QDialog>
#include "gamewindow.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class WelcomeWindow; }
QT_END_NAMESPACE

class WelcomeWindow : public QDialog
{
    Q_OBJECT

public:
    WelcomeWindow(QWidget *parent = nullptr);
    ~WelcomeWindow();
    void setGameWindowPtr(GameWindow *ptr);

signals:
    void sendWelcomeInfoToGame(QString playerName, QString playerColor, int opponentNum);

private slots:
    void on_StartGame_clicked();

private:
    Ui::WelcomeWindow *ui;
    GameWindow *gameWindow;
};
#endif // WELCOMEWINDOW_HPP
