//
// Created by ratratarmy on 01/02/2026.
//

// You may need to build the project (run Qt uic code generator) to get "ui_login.h" resolved

#include "login.hpp"
#include "ui_login.h"
#include "home.hpp"
#include "register.hpp"
#include <QMessageBox>

LoginWND::LoginWND(QWidget *parent) : QWidget(parent), ui(new Ui::LoginWND) {
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &LoginWND::btn_login_clicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &LoginWND::go_to_register);
}

LoginWND::~LoginWND() {
    delete ui;
}
void LoginWND::btn_login_clicked() {
    if ((ui->lineEdit->text() == "admin" or ui->lineEdit->text() == "admin@gmail.com") and ui->lineEdit_2->text() == "admin123") {
        HomeWND* homewnd = new HomeWND();
        homewnd->show();
        this->close();
    }
    else {
        auto something = QMessageBox::critical(this, "Login failed", "You entered wrong username or password");
        if (something == QMessageBox::Ok) {
            num_of_invalid_login_attempt -= 1;
        }
        else if (something == QMessageBox::Cancel) {
            num_of_invalid_login_attempt = 0;
        }
        if (num_of_invalid_login_attempt == 0) {
            ui->pushButton->setEnabled(false);
            ui->pushButton_2->setEnabled(false);
            ui->lineEdit->setEnabled(false);
            ui->lineEdit_2->setEnabled(false);
        }
    }
}

void LoginWND::go_to_register() {
    RegisterWND* registerwnd = new RegisterWND();
    registerwnd->show();
    this->close();
}
