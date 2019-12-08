#include "offertobuy.hpp"

OfferToBuy::OfferToBuy(Player *player, Field *field)
{
    m_player = player;
    m_field = field;
}

void OfferToBuy::playerClickedYes()
{
    m_player->removeMoney(m_field->PriceForBuy());
    m_field->setOwner(m_player);
    emit finishedOffer(m_player, m_field);
}

void OfferToBuy::playerClickedNo()
{
    emit finishedOffer(m_player, m_field);
}
