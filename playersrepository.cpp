#include "playersrepository.hpp"

PlayersRepository::PlayersRepository()
{
    repository.resize(0);

    // Inserting 10 generic bot players
    Player *aiPlayer1  = new Player(1 , QString("James"),    STARTING_MONEY, QColor(Qt::darkRed));
    Player *aiPlayer2  = new Player(2 , QString("John"),     STARTING_MONEY, QColor(Qt::darkGreen));
    Player *aiPlayer3  = new Player(3 , QString("Robert"),   STARTING_MONEY, QColor(Qt::darkBlue));
    Player *aiPlayer4  = new Player(4 , QString("Michael"),  STARTING_MONEY, QColor(Qt::darkMagenta));
    Player *aiPlayer5  = new Player(5 , QString("Wiliam"),   STARTING_MONEY, QColor(Qt::cyan));
    Player *aiPlayer6  = new Player(6 , QString("David"),    STARTING_MONEY, QColor(Qt::magenta));
    Player *aiPlayer7  = new Player(7 , QString("Richard"),  STARTING_MONEY, QColor(Qt::darkYellow));
    Player *aiPlayer8  = new Player(8 , QString("Joseph"),   STARTING_MONEY, QColor(Qt::lightGray));
    Player *aiPlayer9  = new Player(9 , QString("Thomas"),   STARTING_MONEY, QColor(Qt::darkGray));
    Player *aiPlayer10 = new Player(10, QString("Charles"),  STARTING_MONEY, QColor(Qt::darkCyan));

    repository.push_back(aiPlayer1);
    repository.push_back(aiPlayer2);
    repository.push_back(aiPlayer3);
    repository.push_back(aiPlayer4);
    repository.push_back(aiPlayer5);
    repository.push_back(aiPlayer6);
    repository.push_back(aiPlayer7);
    repository.push_back(aiPlayer8);
    repository.push_back(aiPlayer9);
    repository.push_back(aiPlayer10);

    numAiPlayers = 10;
}

PlayersRepository::~PlayersRepository()
{
    for(Player* x : repository)
        delete x;
}

QVector<Player *> PlayersRepository::generateAiPlayers(int n)
{

    QVector<int> chosenIds(n,-1);
    QRandomGenerator generator = QRandomGenerator::securelySeeded();
    for(int i = 0; i != n; i++) {
       int generatedNumber;
       while(true) {
           generatedNumber = generator.bounded(0,10);
           if(!chosenIds.contains(generatedNumber))
               break;
       }
       chosenIds[i] = generatedNumber;
    }

    QVector<Player*> result;
    for(int i : chosenIds)
        result.push_back(repository[i]);

    return result;
}
