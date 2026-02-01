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
};


#endif //WHATISTHATTHING_HOME_HPP