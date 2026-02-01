//
// Created by ratratarmy on 01/02/2026.
//

// You may need to build the project (run Qt uic code generator) to get "ui_sdl3game5_desc.h" resolved

#include "sdl3game5_desc.hpp"
#include "sdl3game5.hpp"
#include "ui_sdl3game5_desc.h"


SDL3Game5_DescWND::SDL3Game5_DescWND(QWidget *parent) : QWidget(parent), ui(new Ui::SDL3Game5_DescWND) {
    ui->setupUi(this);
}

SDL3Game5_DescWND::~SDL3Game5_DescWND() {
    delete ui;
}
void SDL3Game5_DescWND::startGame() {
    game5::launch();
}