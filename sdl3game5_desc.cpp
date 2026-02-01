//
// Created by ratratarmy on 01/02/2026.
//

// You may need to build the project (run Qt uic code generator) to get "ui_sdl3game5_desc.h" resolved

#include "sdl3game5_desc.hpp"
#include "sdl3game5.hpp"
#include "ui_sdl3game5_desc.h"
#include "home.hpp"

SDL3Game5_DescWND::SDL3Game5_DescWND(QWidget *parent) : QWidget(parent), ui(new Ui::SDL3Game5_DescWND) {
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &SDL3Game5_DescWND::startGame);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &SDL3Game5_DescWND::ret_to_home);
}

SDL3Game5_DescWND::~SDL3Game5_DescWND() {
    delete ui;
}
void SDL3Game5_DescWND::startGame() {
    game5::launch();
}
void SDL3Game5_DescWND::ret_to_home() {
    HomeWND* homewnd = new HomeWND();
    homewnd->show();
    this->close();
}