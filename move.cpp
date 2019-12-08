#include "move.hpp"

Move::Move()
{
    m_playerOnMove = nullptr;
}

Move::Move(Player *playerOnMove, Field *currentField)
{
    m_playerOnMove = playerOnMove;
    m_currentField = currentField;
}

void Move::generateNumber()
{
    QRandomGenerator generator = QRandomGenerator::securelySeeded();
    m_generatedNumMoveField = (generator.bounded(1,7) + m_currentField->Id()) % 16;
    m_playerOnMove->setFieldId(m_generatedNumMoveField);
    m_currentField->removePlayerOnField(m_playerOnMove);
    m_currentField->repaint();
    emit notifyNewPosition(m_playerOnMove, m_generatedNumMoveField);
}
