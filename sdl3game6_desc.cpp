//
// Created by ratratarmy on 01/02/2026.
//

// You may need to build the project (run Qt uic code generator) to get "ui_sdl3game6_desc.h" resolved

#include "sdl3game6_desc.hpp"
#include "ui_sdl3game6_desc.h"
#include "sdl3game6.hpp"

SDL3Game6_DescWND::SDL3Game6_DescWND(QWidget *parent) : QWidget(parent), ui(new Ui::SDL3Game6_DescWND) {
    ui->setupUi(this);
}

SDL3Game6_DescWND::~SDL3Game6_DescWND() {
    delete ui;
}
void SDL3Game6_DescWND::startGame() {
    game6::launch();
}