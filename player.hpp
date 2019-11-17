#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <QString>
#include <QColor>

const int STARTING_MONEY = 10000;

class Player
{
public:
    Player();
    Player(int _id, QString _name, int _money, QColor _color);
    int id();
    QColor color();

private:
    int m_id;
    QString m_name;
    int m_money;
    QColor m_color;
};

#endif // PLAYER_HPP
