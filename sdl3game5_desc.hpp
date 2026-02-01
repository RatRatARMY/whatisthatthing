//
// Created by ratratarmy on 01/02/2026.
//

#ifndef WHATISTHATTHING_SDL3GAME5_DESC_HPP
#define WHATISTHATTHING_SDL3GAME5_DESC_HPP

#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui {
    class SDL3Game5_DescWND;
}

QT_END_NAMESPACE

class SDL3Game5_DescWND : public QWidget {
    Q_OBJECT

public:
    explicit SDL3Game5_DescWND(QWidget *parent = nullptr);

    ~SDL3Game5_DescWND() override;

private:
    Ui::SDL3Game5_DescWND *ui;
};


#endif //WHATISTHATTHING_SDL3GAME5_DESC_HPP