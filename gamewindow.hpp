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
#include <offertobuy.hpp>

namespace Ui {
class GameWindow;
}

class GameWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();
    void startGame();
    void generateDice1();
    void prepareFields();
    Field* findFieldById(int id);

public slots:
    void sendWelcomeInfoToGame(QString playerName, QString playerColor, int opponentNum);
    void notifyNewPosition2(Player* playerOnMove, int newId);
    void finishedOfferProposal(Player* player, Field* field);


private:
    Ui::GameWindow *ui;
    Player *m_player;
    int m_opponentsNumber;
    PlayersRepository m_playersRepo;
    QVector<Player*> m_aiPlayers;
    CircularList *m_playersWheel;

    Move *tmpObject1 = nullptr;
    OfferToBuy *tmpObject2 = nullptr;

};

#endif // GAMEWINDOW_HPP
