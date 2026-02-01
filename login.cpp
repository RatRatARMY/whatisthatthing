//
// Created by ratratarmy on 01/02/2026.
//

// You may need to build the project (run Qt uic code generator) to get "ui_login.h" resolved

#include "login.hpp"
#include "ui_login.h"


LoginWND::LoginWND(QWidget *parent) : QWidget(parent), ui(new Ui::LoginWND) {
    ui->setupUi(this);
}

LoginWND::~LoginWND() {
    delete ui;
}