//
// Created by ratratarmy on 01/02/2026.
//

// You may need to build the project (run Qt uic code generator) to get "ui_home.h" resolved

#include "home.hpp"
#include "ui_home.h"


HomeWND::HomeWND(QWidget *parent) : QWidget(parent), ui(new Ui::HomeWND) {
    ui->setupUi(this);
}

HomeWND::~HomeWND() {
    delete ui;
}