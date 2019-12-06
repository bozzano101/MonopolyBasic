#ifndef OFFERTOBUY_HPP
#define OFFERTOBUY_HPP

#include <QWidget>
#include <player.hpp>
#include <field.hpp>

class OfferToBuy : public QWidget
{
    Q_OBJECT
public:
    OfferToBuy();

public slots:
    void playerClickedYes();
    void playerClickedNo();

private:
    Player* m_player;
    Field* m_field;

};

#endif // OFFERTOBUY_HPP
