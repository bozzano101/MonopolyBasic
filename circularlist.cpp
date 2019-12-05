#include "circularlist.hpp"

CircularList::CircularList(Player *player, QVector<Player*> aiPlayers)
{
    m_players = aiPlayers;
    m_players.push_front(player);
}

Player *CircularList::next()
{
    if(i == m_players.size())
        i = 0;
    i += 1;
    return m_players[i-1];
}
