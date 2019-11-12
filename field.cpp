#include "field.hpp"

Field::Field(QWidget *parent)
    :QFrame(parent)
{
    this->resize(100,100);
    QSizePolicy s(QSizePolicy::Fixed,QSizePolicy::Fixed);
    this->setSizePolicy(s);
}


void Field::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawEllipse(10,10,20,20);
}

StartField::StartField(QWidget *parent)
    :Field(parent)
{

}

void StartField::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawText(30,55,"START");
}
