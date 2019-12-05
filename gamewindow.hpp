#ifndef GAMEWINDOW_HPP
#define GAMEWINDOW_HPP

#include <QWidget>
#include <QPainter>
#include <QGridLayout>
#include <QDebug>

#include <field.hpp>
#include <playersrepository.hpp>
#include <circularlist.hpp>
#include <move.hpp>

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
    //void notifyNewPosition(int newId);

private:
    Ui::GameWindow *ui;
    Player *m_player;
    int m_opponentsNumber;
    PlayersRepository m_playersRepo;
    QVector<Player*> m_aiPlayers;

    void prepareFields();
    void startGame();

    CircularList *m_playersWheel;

};

#endif // GAMEWINDOW_HPP
