#include "gamewindow.hpp"
#include "ui_gamewindow.h"

GameWindow::GameWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::sendWelcomeInfoToGame(QString _playerName, QString _playerColor, int _opponentNum)
{
    playerName = _playerName;
    playerColor = _playerColor;
    opponentsNumber = _opponentNum;
    qDebug() << playerName << "  " << playerColor << "  " << QString::number(opponentsNumber);
}
