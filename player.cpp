#include "player.hpp"

Player::Player()
{
    m_id = -1;
    m_name = QString();
    m_money = 0;
    m_color = QColor();
}

Player::Player(int _id, QString _name, int _money, QColor _color)
{
    m_id = _id;
    m_name = _name;
    m_money = _money;
    m_color = _color;
}

int Player::id()
{
    return m_id;
}

QColor Player::color()
{
    return m_color;
}

int Player::money()
{
    return m_money;
}

QString Player::name()
{
    return m_name;
}
