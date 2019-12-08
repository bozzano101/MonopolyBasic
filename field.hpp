#ifndef FIELD_HPP
#define FIELD_HPP

#include <QFrame>
#include <QPainter>
#include <QSizePolicy>
#include <QDebug>
#include <QFont>
#include <QPen>

#include <player.hpp>

const QFont streetNameFont("Times", 11,-1,true);
const QFont startFont("Times", 11, 63, true);
const QFont priceFont("Times", 9,-1,false);

class Field : public QFrame
{
    Q_OBJECT
public:
    Field(QWidget *parent);
    void paintEvent(QPaintEvent *) override;
    void setId(int id);
    void setStreetName(QString name);
    void setPriceForBuy(int price);
    void setPriceForRenting(int price);
    void setOwner(Player *owner);
    void addPlayerOnField(Player *p);
    void removePlayerOnField(Player *p);
    void prepareField(int id, QString name, int priceForBuy, int priceForRent);
    int Id();
    Player *Owner();
    int PriceForBuy();

protected:
    int m_id;
    QString m_streetName;
    int m_priceForBuy;
    int m_priceForRenting;
    Player *m_owner = nullptr;
    QVector<Player*> m_playersOnField;
};

class StartField : public Field
{
public:
    StartField(QWidget *parent);
    void prepareField();
    void paintEvent(QPaintEvent *) override;
};

#endif // FIELD_HPP
