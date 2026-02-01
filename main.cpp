#include <QApplication>
#include "login.hpp"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    LoginWND* w = new LoginWND();
    w->show();
    return QApplication::exec();
}