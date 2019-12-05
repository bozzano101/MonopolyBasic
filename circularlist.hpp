#ifndef CIRCULARLIST_HPP
#define CIRCULARLIST_HPP

#include <player.hpp>
#include <QVector>

class CircularList
{
public:
    CircularList(Player* player, QVector<Player*> aiPlayers);
    Player* next();

private:
    int i = 0;
    QVector<Player*> m_players;
};

#endif // CIRCULARLIST_HPP
