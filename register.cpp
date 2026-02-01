//
// Created by ratratarmy on 01/02/2026.
//

// You may need to build the project (run Qt uic code generator) to get "ui_register.h" resolved

#include "register.hpp"
#include "ui_register.h"
#include "home.hpp"
#include "login.hpp"
#include <QMessageBox>
RegisterWND::RegisterWND(QWidget *parent) : QWidget(parent), ui(new Ui::RegisterWND) {
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &RegisterWND::btn_register_clicked);
}

RegisterWND::~RegisterWND() {
    delete ui;
}

void RegisterWND::btn_register_clicked() {
    if (ui->lineEdit->text() != "" and ui->lineEdit_2->text() != "" and ui->lineEdit_3->text() != ""
        and ui->lineEdit_4->text() != "" and ui->lineEdit_3->text() == ui->lineEdit_4->text()) {
        HomeWND* homewnd = new HomeWND();
        homewnd->show();
        this->close();
    }
    else {
        QMessageBox::critical(this, "Register failed", "Some fields are empty or not matching");
    }
}
void RegisterWND::ret_to_login() {
    LoginWND* loginwnd = new LoginWND();
    loginwnd->show();
    this->close();
}