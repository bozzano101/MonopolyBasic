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
    int Id();

private:
    int id;
    QString name;
    int money;
    QColor color;
};

#endif // PLAYER_HPP
