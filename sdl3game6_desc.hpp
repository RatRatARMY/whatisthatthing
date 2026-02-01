//
// Created by ratratarmy on 01/02/2026.
//

#ifndef WHATISTHATTHING_SDL3GAME6_DESC_HPP
#define WHATISTHATTHING_SDL3GAME6_DESC_HPP

#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui {
    class SDL3Game6_DescWND;
}

QT_END_NAMESPACE

class SDL3Game6_DescWND : public QWidget {
    Q_OBJECT

public:
    explicit SDL3Game6_DescWND(QWidget *parent = nullptr);

    ~SDL3Game6_DescWND() override;

private:
    Ui::SDL3Game6_DescWND *ui;
    void startGame();
    void ret_to_home();
};


#endif //WHATISTHATTHING_SDL3GAME6_DESC_HPP