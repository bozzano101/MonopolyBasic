#include "welcomewindow.hpp"
#include "ui_welcomewindow.h"

WelcomeWindow::WelcomeWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::WelcomeWindow)
{
    ui->setupUi(this);
}

WelcomeWindow::~WelcomeWindow()
{
    delete ui;
}

void WelcomeWindow::setGameWindowPtr(GameWindow *ptr)
{
    gameWindow = ptr;
}


void WelcomeWindow::on_StartGame_clicked()
{
    QString color;
    if(ui->RedColor->isChecked())
        color = "Red";
    if(ui->GreenColor->isChecked())
        color = "Green";
    if(ui->YellowColor->isChecked())
        color = "Yellow";
    if(ui->BlueColor->isChecked())
        color = "Blue";

    connect(this, &WelcomeWindow::sendWelcomeInfoToGame, gameWindow, &GameWindow::sendWelcomeInfoToGame);
    emit sendWelcomeInfoToGame(ui->PlayerName->text(), color, ui->NumbeOfOpponents->value());
    gameWindow->show();
    this->close();
}
