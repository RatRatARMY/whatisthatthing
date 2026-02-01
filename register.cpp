//
// Created by ratratarmy on 01/02/2026.
//

// You may need to build the project (run Qt uic code generator) to get "ui_register.h" resolved

#include "register.hpp"
#include "ui_register.h"


RegisterWND::RegisterWND(QWidget *parent) : QWidget(parent), ui(new Ui::RegisterWND) {
    ui->setupUi(this);
}

RegisterWND::~RegisterWND() {
    delete ui;
}