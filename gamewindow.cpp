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
    m_player = new Player(0, _playerName, STARTING_MONEY, QColor(_playerColor));
    m_opponentsNumber = _opponentNum;
    m_aiPlayers = m_playersRepo.generateAiPlayers(m_opponentsNumber);

}
