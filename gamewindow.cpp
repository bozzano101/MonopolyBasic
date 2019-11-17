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


}

void GameWindow::prepareFields()
{
    ui->field1Frame->prepareField(0, "Allen Street", 500, 50);
    ui->field2Frame->prepareField(0, "Beekman Place", 750, 75);
    ui->field3Frame->prepareField(0, "Cabrini Bvd", 300, 30);
    ui->field4Frame->prepareField(0, "Delancey Street", 1000, 100);
    ui->field5Frame->prepareField(0, "Eldridge Street", 650, 65);
    ui->field6Frame->prepareField(0, "Fulton Street", 400, 40);
    ui->field7Frame->prepareField(0, "Gey Street", 800, 80);
    ui->field8Frame->prepareField(0, "Houston Street", 500, 50);
    ui->field9Frame->prepareField(0, "Irving place", 1200, 120);
    ui->field10Frame->prepareField(0, "Lafayette Street", 700, 70);
    ui->field11Frame->prepareField(0, "Madison Avenue", 900, 90);
    ui->field12Frame->prepareField(0, "Nassau street", 1100, 110);
    ui->field13Frame->prepareField(0, "Rutgers street", 600, 60);
    ui->field14Frame->prepareField(0, "St Marks place", 1050, 105);
    ui->field15Frame->prepareField(0, "Stanton Street", 200, 20);
}
