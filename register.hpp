//
// Created by ratratarmy on 01/02/2026.
//

#ifndef WHATISTHATTHING_REGISTER_HPP
#define WHATISTHATTHING_REGISTER_HPP

#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui {
    class RegisterWND;
}

QT_END_NAMESPACE

class RegisterWND : public QWidget {
    Q_OBJECT

public:
    explicit RegisterWND(QWidget *parent = nullptr);

    ~RegisterWND() override;

private:
    Ui::RegisterWND *ui;
    void btn_register_clicked();
    void ret_to_login();
};


#endif //WHATISTHATTHING_REGISTER_HPP