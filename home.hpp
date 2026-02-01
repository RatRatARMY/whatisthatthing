//
// Created by ratratarmy on 01/02/2026.
//

#ifndef WHATISTHATTHING_HOME_HPP
#define WHATISTHATTHING_HOME_HPP

#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui {
    class HomeWND;
}

QT_END_NAMESPACE

class HomeWND : public QWidget {
    Q_OBJECT

public:
    explicit HomeWND(QWidget *parent = nullptr);

    ~HomeWND() override;

private:
    Ui::HomeWND *ui;
    void btn_game1_clicked();
    void btn_game2_clicked();
    void btn_game3_clicked();
    void btn_game4_clicked();
    void btn_game5_clicked();
    void btn_game6_clicked();
};


#endif //WHATISTHATTHING_HOME_HPP