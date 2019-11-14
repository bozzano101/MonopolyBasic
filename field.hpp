#ifndef FIELD_HPP
#define FIELD_HPP

#include <QFrame>
#include <QPainter>
#include <QSizePolicy>

#include <player.hpp>

class Field : public QFrame
{
    Q_OBJECT
public:
    Field(QWidget *parent);
    void paintEvent(QPaintEvent *) override;
private:
    int m_id;
    QString m_streetName;
    int m_priceForBuy;
    int m_priceForRenting;
    QVector<Player*> m_playersOnField;
};

class StartField : public Field
{
public:
    StartField(QWidget *parent);
    void paintEvent(QPaintEvent *) override;
};

#endif // FIELD_HPP
