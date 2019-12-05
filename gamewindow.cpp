#include "gamewindow.hpp"
#include "ui_gamewindow.h"

GameWindow::GameWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    prepareFields();
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

    for(int i = 0; i < m_aiPlayers.size(); i++)
        ui->field0Frame->addPlayerOnField(m_aiPlayers[i]);
    ui->field0Frame->addPlayerOnField(m_player);

    // TODO : Refactor this code; If player exist, give him field
    ui->centralPlayer1Frame->prepareField(m_aiPlayers[0]);
    ui->centralPlayer2Frame->prepareField(m_aiPlayers[1]);
    //

    ui->centralGamerFrame->prepareField(m_player);

}

void GameWindow::prepareFields()
{

    ui->field0Frame->prepareField();
    ui->field1Frame->prepareField(1, "Allen Street", 500, 50);
    ui->field2Frame->prepareField(2, "Beekman Place", 750, 75);
    ui->field3Frame->prepareField(3, "Cabrini Bvd", 300, 30);
    ui->field4Frame->prepareField(4, "Delancey Street", 1000, 100);
    ui->field5Frame->prepareField(5, "Eldridge Street", 650, 65);
    ui->field6Frame->prepareField(6, "Fulton Street", 400, 40);
    ui->field7Frame->prepareField(7, "Gey Street", 800, 80);
    ui->field8Frame->prepareField(8, "Houston Street", 500, 50);
    ui->field9Frame->prepareField(9, "Irving place", 1200, 120);
    ui->field10Frame->prepareField(10, "Lafayette Street", 700, 70);
    ui->field11Frame->prepareField(11, "Madison Avenue", 900, 90);
    ui->field12Frame->prepareField(12, "Nassau street", 1100, 110);
    ui->field13Frame->prepareField(13, "Rutgers street", 600, 60);
    ui->field14Frame->prepareField(14, "St Marks place", 1050, 105);
    ui->field15Frame->prepareField(15, "Stanton Street", 200, 20);
}
