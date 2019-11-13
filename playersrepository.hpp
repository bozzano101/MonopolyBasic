#ifndef PLAYERSREPOSITORY_HPP
#define PLAYERSREPOSITORY_HPP

#include <QVector>
#include <QRandomGenerator>
#include <player.hpp>

class PlayersRepository
{
public:
    PlayersRepository();
    ~PlayersRepository();
    QVector<Player *> generateAiPlayers(int n);

private:
    QVector<Player*> repository;
    int numAiPlayers = 0;
};

#endif // PLAYERSREPOSITORY_HPP
