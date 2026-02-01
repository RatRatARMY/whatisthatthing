//
// Created by ratratarmy on 01/02/2026.
//

// You may need to build the project (run Qt uic code generator) to get "ui_sdl3game4_desc.h" resolved

#include "sdl3game4_desc.hpp"
#include "ui_sdl3game4_desc.h"


SDL3Game4_DescWND::SDL3Game4_DescWND(QWidget *parent) : QWidget(parent), ui(new Ui::SDL3Game4_DescWND) {
    ui->setupUi(this);
}

SDL3Game4_DescWND::~SDL3Game4_DescWND() {
    delete ui;
}