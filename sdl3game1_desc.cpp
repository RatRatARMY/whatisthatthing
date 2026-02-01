//
// Created by ratratarmy on 01/02/2026.
//

// You may need to build the project (run Qt uic code generator) to get "ui_sdl3game1_desc.h" resolved

#include "sdl3game1_desc.hpp"
#include "ui_sdl3game1_desc.h"


SDL3Game1_DescWND::SDL3Game1_DescWND(QWidget *parent) : QWidget(parent), ui(new Ui::SDL3Game1_DescWND) {
    ui->setupUi(this);
}

SDL3Game1_DescWND::~SDL3Game1_DescWND() {
    delete ui;
}