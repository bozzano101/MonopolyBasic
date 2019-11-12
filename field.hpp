#ifndef FIELD_HPP
#define FIELD_HPP

#include <QFrame>
#include <QPainter>
#include <QSizePolicy>

class Field : public QFrame
{
    Q_OBJECT
public:
    Field(QWidget *parent);
    void paintEvent(QPaintEvent *) override;
};

class StartField : public Field
{
public:
    StartField(QWidget *parent);
    void paintEvent(QPaintEvent *) override;
};

#endif // FIELD_HPP
