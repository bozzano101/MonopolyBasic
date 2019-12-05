#include "playerinfofield.hpp"

PlayerInfoField::PlayerInfoField(QWidget *parent)
    : QFrame(parent)
{
    m_player = new Player(-1,"-",0,QColor(Qt::white));
}

PlayerInfoField::~PlayerInfoField()
{
    if(m_player->name() == "-")
        delete m_player;
}

void PlayerInfoField::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    QPalette plt = palette();
    plt.setColor(QPalette::Background, m_player->color());
    this->setAutoFillBackground(true);
    this->setPalette(plt);

    painter.setFont(titleFont);
    painter.drawText(15,30,m_player->name());

    painter.setFont(normalFont);
    painter.drawText(15, 65, QString("Money: ") + QString::number(m_player->money()) );
}

void PlayerInfoField::prepareField(Player *player)
{
    m_player = player;
}
