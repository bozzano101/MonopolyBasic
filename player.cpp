#include "player.hpp"

Player::Player()
{
    id = -1;
    name = QString();
    money = 0;
    color = QColor();
}

Player::Player(int _id, QString _name, int _money, QColor _color)
{
    id = _id;
    name = _name;
    money = _money;
    color = _color;
}

int Player::Id()
{
    return id;
}
