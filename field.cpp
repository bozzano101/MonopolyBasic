#include "field.hpp"

Field::Field(QWidget *parent)
    :QFrame(parent)
{
    this->resize(100,100);
    QSizePolicy s(QSizePolicy::Fixed,QSizePolicy::Fixed);
    this->setSizePolicy(s);

    m_id = -1;
    m_streetName = "Not initialized.";
    m_priceForBuy = -1;
    m_priceForRenting = -1;
    m_owner = nullptr;
    m_playersOnField.resize(0);
}


void Field::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.setFont(streetNameFont);
    painter.drawText(5,40, m_streetName);

    painter.setFont(priceFont);
    painter.drawText(5,55, "Buy for: " + QString::number(m_priceForBuy));
    painter.drawText(5,70, "Rent price: " + QString::number(m_priceForRenting));
}

void Field::setId(int id)
{
    m_id = id;
}

void Field::setStreetName(QString name)
{
    m_streetName = name;
}

void Field::setPriceForBuy(int price)
{
    m_priceForBuy = price;
}

void Field::setPriceForRenting(int price)
{
    m_priceForRenting = price;
}

void Field::setOwner(Player *owner)
{
    m_owner = owner;
}

void Field::addPlayerOnField(Player *p)
{
    m_playersOnField.push_back(p);
}

void Field::removePlayerOnField(Player *p)
{
    m_playersOnField.removeOne(p);
}

void Field::prepareField(int id, QString name, int priceForBuy, int priceForRent)
{
    setId(id);
    setStreetName(name);
    setPriceForBuy(priceForBuy);
    setPriceForRenting(priceForRent);
}

StartField::StartField(QWidget *parent)
    :Field(parent)
{

}

void StartField::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.setFont(startFont);
    painter.drawText(28,55,"START");
}
