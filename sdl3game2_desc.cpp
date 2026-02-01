//
// Created by ratratarmy on 01/02/2026.
//

// You may need to build the project (run Qt uic code generator) to get "ui_sdl3game2_desc.h" resolved

#include "sdl3game2_desc.hpp"
#include "ui_sdl3game2_desc.h"


SDL3Game2_DescWND::SDL3Game2_DescWND(QWidget *parent) : QWidget(parent), ui(new Ui::SDL3Game2_DescWND) {
    ui->setupUi(this);
}

SDL3Game2_DescWND::~SDL3Game2_DescWND() {
    delete ui;
}