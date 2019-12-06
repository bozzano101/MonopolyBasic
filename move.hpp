#ifndef MOVE_HPP
#define MOVE_HPP

#include <QObject>
#include <QRandomGenerator>

#include <player.hpp>
#include <field.hpp>

class Move : public QObject
{
    Q_OBJECT
public:
    Move();
    Move(Player* playerOnMove, Field *currentField);

public slots:
    void generateNumber();

signals:
    void notifyNewPosition(Player* playerOnMove, int newId);

private:
    Player* m_playerOnMove;
    Field* m_currentField;
    int m_generatedNumMoveField = -1;
};

#endif // MOVE_HPP
