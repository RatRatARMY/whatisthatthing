//
// Created by ratratarmy on 01/02/2026.
//

// You may need to build the project (run Qt uic code generator) to get "ui_sdl3game3_desc.h" resolved

#include "sdl3game3_desc.hpp"
#include "sdl3game3.hpp"
#include "ui_sdl3game3_desc.h"


SDL3Game3_DescWND::SDL3Game3_DescWND(QWidget *parent) : QWidget(parent), ui(new Ui::SDL3Game3_DescWND) {
    ui->setupUi(this);
}

SDL3Game3_DescWND::~SDL3Game3_DescWND() {
    delete ui;
}
void SDL3Game3_DescWND::startGame() {
    game3::launch();
}