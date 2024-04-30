#ifndef PREVIEWWINDOW_H
#define PREVIEWWINDOW_H

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDebug>

class PreviewWindow : public QWidget
{
    Q_OBJECT

public:
    PreviewWindow(QWidget *parent = nullptr);

    void setWindowFlags(Qt::WindowFlags flags, Qt::WindowStates state);

private:
    QTextEdit *textEdit;
    QPushButton *closeButton;
};

#endif // PREVIEWWINDOW_H
