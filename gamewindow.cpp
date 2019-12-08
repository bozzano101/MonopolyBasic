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

    ui->centralPlayer1Frame->prepareField(m_aiPlayers[0]);
    if(m_aiPlayers.size() >= 2 ) {
        ui->centralPlayer2Frame->prepareField(m_aiPlayers[1]);
        if(m_aiPlayers.size() == 3)
            ui->centralPlayer3Frame->prepareField(m_aiPlayers[2]);
    }
    ui->centralGamerFrame->prepareField(m_player);

    m_playersWheel = new CircularList(m_player, m_aiPlayers);

    startGame();

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

Field *GameWindow::findFieldById(int id)
{
    switch (id) {
    case 0:
        return ui->field0Frame;
    case 1:
        return ui->field1Frame;
    case 2:
        return ui->field2Frame;
    case 3:
        return ui->field3Frame;
    case 4:
        return ui->field4Frame;
    case 5:
        return ui->field5Frame;
    case 6:
        return ui->field6Frame;
    case 7:
        return ui->field7Frame;
    case 8:
        return ui->field8Frame;
    case 9:
        return ui->field9Frame;
    case 10:
        return ui->field10Frame;
    case 11:
        return ui->field11Frame;
    case 12:
        return ui->field12Frame;
    case 13:
        return ui->field13Frame;
    case 14:
        return ui->field14Frame;
    case 15:
        return ui->field15Frame;
    default:
        break;
    }
    return ui->field0Frame;
}

void GameWindow::startGame()
{
    generateDice1();

}

void GameWindow::generateDice1()
{
    Player* nextOnMove = m_playersWheel->next();                                            // Choose which player will play next
    ui->onMovePlayerName->setText(nextOnMove->name());                                      // Change label text
    tmpObject1 = new Move(nextOnMove, findFieldById(nextOnMove->fieldId()));                // Create his next move-object
    connect(ui->onMoveButton, &QPushButton::clicked, tmpObject1, &Move::generateNumber);    // Connect button to move-object
    connect(tmpObject1, &Move::notifyNewPosition, this, &GameWindow::notifyNewPosition2);   // Connect move-object to add to new field
    ui->onMoveButton->setEnabled(true);                                                     // Enable button for click
}

void GameWindow::notifyNewPosition2(Player *playerOnMove, int newId)
{   
    disconnect(ui->onMoveButton, &QPushButton::clicked, tmpObject1, &Move::generateNumber);

    Field *currentField = findFieldById(newId);
    currentField->addPlayerOnField(playerOnMove);                               // Add player on new field
    currentField->repaint();                                                    // Refresh GUI
    ui->onMoveButton->setEnabled(false);                                        // Disable generate button

    if(currentField->Owner() == nullptr) {
        tmpObject2 = new OfferToBuy(playerOnMove, currentField);
        ui->offerToBuyNO->setEnabled(true);
        ui->offerToBuyYES->setEnabled(true);
        connect(ui->offerToBuyYES, &QPushButton::clicked, tmpObject2, &OfferToBuy::playerClickedYes);
        connect(ui->offerToBuyNO, &QPushButton::clicked, tmpObject2, &OfferToBuy::playerClickedNo);
        connect(tmpObject2, &OfferToBuy::finishedOffer, this, &GameWindow::finishedOfferProposal);
    }
    else {
        // playerOnMove must pay rent
    }

    /* IMPORTANT :
     * Start field cannot be bought !
     * You cannot buy a field if you don't have money
     */
}

void GameWindow::finishedOfferProposal(Player *player, Field *field)
{
    disconnect(ui->offerToBuyYES, &QPushButton::clicked, tmpObject2, &OfferToBuy::playerClickedYes);
    disconnect(ui->offerToBuyNO, &QPushButton::clicked, tmpObject2, &OfferToBuy::playerClickedNo);
    // Remove player atribute
    player->id();
    field->repaint();
    startGame();
}
