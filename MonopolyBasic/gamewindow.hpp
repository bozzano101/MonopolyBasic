#ifndef GAMEWINDOW_HPP
#define GAMEWINDOW_HPP

#include <QWidget>

namespace Ui {
class GameWindow;
}

class GameWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

private:
    Ui::GameWindow *ui;
};

#endif // GAMEWINDOW_HPP
