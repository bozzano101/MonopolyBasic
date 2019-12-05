#ifndef PLAYERINFOFIELD_HPP
#define PLAYERINFOFIELD_HPP

#include <QFrame>
#include <QPainter>
#include <QSizePolicy>
#include <QFont>

#include <player.hpp>

const QFont titleFont("Times", 11, 63, true);
const QFont normalFont("Times", 9,-1,false);

class PlayerInfoField : public QFrame
{
    Q_OBJECT
public:
    PlayerInfoField(QWidget *parent);
    ~PlayerInfoField() override;
    void paintEvent(QPaintEvent *) override;
    void prepareField(Player *player);

private:
    Player *m_player;
};

#endif // PLAYERINFOFIELD_HPP
