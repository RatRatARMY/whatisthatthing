//
// Created by ratratarmy on 01/02/2026.
//

// You may need to build the project (run Qt uic code generator) to get "ui_home.h" resolved

#include "home.hpp"
#include "ui_home.h"
#include "sdl3game1_desc.hpp"
#include "sdl3game2_desc.hpp"
#include "sdl3game3_desc.hpp"
#include "sdl3game4_desc.hpp"
#include "sdl3game5_desc.hpp"
#include "sdl3game6_desc.hpp"
HomeWND::HomeWND(QWidget *parent) : QWidget(parent), ui(new Ui::HomeWND) {
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &HomeWND::btn_game1_clicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &HomeWND::btn_game2_clicked);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &HomeWND::btn_game3_clicked);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &HomeWND::btn_game4_clicked);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &HomeWND::btn_game5_clicked);
    connect(ui->pushButton_6, &QPushButton::clicked, this, &HomeWND::btn_game6_clicked);
}

HomeWND::~HomeWND() {
    delete ui;
}
void HomeWND::btn_game1_clicked() {
    SDL3Game1_DescWND* descwnd = new SDL3Game1_DescWND();
    descwnd->show();
    this->close();
}
void HomeWND::btn_game2_clicked() {
    SDL3Game2_DescWND* descwnd = new SDL3Game2_DescWND();
    descwnd->show();
    this->close();
}
void HomeWND::btn_game3_clicked() {
    SDL3Game3_DescWND* descwnd = new SDL3Game3_DescWND();
    descwnd->show();
    this->close();
}

void HomeWND::btn_game4_clicked() {
    SDL3Game4_DescWND* descwnd = new SDL3Game4_DescWND();
    descwnd->show();
    this->close();
}
void HomeWND::btn_game5_clicked() {
    SDL3Game5_DescWND* descwnd = new SDL3Game5_DescWND();
    descwnd->show();
    this->close();
}
void HomeWND::btn_game6_clicked() {
    SDL3Game6_DescWND* descwnd = new SDL3Game6_DescWND();
    descwnd->show();
    this->close();
}