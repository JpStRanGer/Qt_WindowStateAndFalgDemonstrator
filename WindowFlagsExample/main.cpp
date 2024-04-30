#include <QCoreApplication>
#include <QApplication>
#include "controllerwindow.h"
#include "previewwindow.h"

int main(int argc, char *argv[])
{
    // QCoreApplication a(argc, argv);
    QApplication a(argc, argv);

    ControllerWindow w;
    w.show();

    // // TEST from GPT

    // QWidget mainWindow;
    // mainWindow.setGeometry(500, 500, 400, 300);
    // mainWindow.setWindowTitle("Main Window");

    // QWidget newWindow;
    // newWindow.setGeometry(500, 500, 400, 300);
    // newWindow.setFixedSize(500, 400);
    // newWindow.setWindowTitle("New Window");
    // // newWindow.show();

    // PreviewWindow testWindow;
    // testWindow.show();

    // QPushButton *button = new QPushButton("Open New Window", &mainWindow);
    // button->setGeometry(100, 50, 200, 30);

    // QObject::connect(button,&QPushButton::clicked,[&](){
    //     newWindow.show();
    // });


    // mainWindow.show();

    return a.exec();
}
