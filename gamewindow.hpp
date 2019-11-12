#ifndef GAMEWINDOW_HPP
#define GAMEWINDOW_HPP

#include <QWidget>
#include <QPainter>
#include <QGridLayout>
#include <QDebug>

#include <field.hpp>

namespace Ui {
class GameWindow;
}

class GameWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

public slots:
    void sendWelcomeInfoToGame(QString playerName, QString playerColor, int opponentNum);

private:
    Ui::GameWindow *ui;
    QString playerName;
    QString playerColor;
    int opponentsNumber;

    Field *myField = new Field(this);
};

#endif // GAMEWINDOW_HPP
