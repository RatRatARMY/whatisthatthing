//
// Created by ratratarmy on 01/02/2026.
//

// You may need to build the project (run Qt uic code generator) to get "ui_sdl3game6_desc.h" resolved

#include "sdl3game6_desc.hpp"
#include "home.hpp"
#include "ui_sdl3game6_desc.h"
#include "sdl3game6.hpp"

SDL3Game6_DescWND::SDL3Game6_DescWND(QWidget *parent) : QWidget(parent), ui(new Ui::SDL3Game6_DescWND) {
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &SDL3Game6_DescWND::startGame);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &SDL3Game6_DescWND::ret_to_home);
}

SDL3Game6_DescWND::~SDL3Game6_DescWND() {
    delete ui;
}
void SDL3Game6_DescWND::startGame() {
    game6::launch();
}
void SDL3Game6_DescWND::ret_to_home() {
    HomeWND* homewnd = new HomeWND();
    homewnd->show();
    this->close();
}