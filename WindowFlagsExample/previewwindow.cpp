#include "previewwindow.h"

PreviewWindow::PreviewWindow(QWidget *parent)
    : QWidget(parent)
{
    textEdit = new QTextEdit;
    textEdit->setReadOnly(true);
    textEdit->setLineWrapMode(QTextEdit::NoWrap);

    closeButton = new QPushButton(tr("&Close"));
    connect(closeButton, &QPushButton::clicked, this, &PreviewWindow::close);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(textEdit);
    layout->addWidget(closeButton);
    setLayout(layout);
    setWindowTitle(tr("Preview"));
}

void PreviewWindow::setWindowFlags(Qt::WindowFlags flags, Qt::WindowStates state)
{
    QWidget::setWindowState(state);
    QWidget::setWindowFlags(flags);

    QString stateText;
    QString flagText;
    QString text;

    // Qt::WindowFlags state = (flags & Qt::WindowType_Mask);
    if (state & Qt::WindowState::WindowNoState)
        stateText += "\n| Qt::WindowNoState";
    if (state & Qt::WindowState::WindowActive)
        stateText = "\n| Qt::WindowActive";
    if (state & Qt::WindowState::WindowFullScreen)
        stateText += "\n| Qt::WindowFullScreen";
    if (state & Qt::WindowState::WindowMaximized)
        stateText += "\n| Qt::WindowMaximized";
    if (state & Qt::WindowState::WindowMinimized)
        stateText += "\n| Qt::WindowMinimized";

    Qt::WindowFlags type = (flags & Qt::WindowType_Mask);
    if (type == Qt::Widget)
        flagText += "Qt::Widget";
    else if (type == Qt::Window)
        flagText += "Qt::Window";
    else if (type == Qt::Dialog)
        flagText = "Qt::Dialog";
    else if (type == Qt::Sheet)
        flagText += "Qt::Sheet";
    else if (type == Qt::Drawer)
        flagText += "Qt::Drawer";
    else if (type == Qt::Popup)
        flagText += "Qt::Popup";
    else if (type == Qt::Tool)
        flagText += "Qt::Tool";
    else if (type == Qt::ToolTip)
        flagText += "Qt::ToolTip";
    else if (type == Qt::SplashScreen)
        flagText += "Qt::SplashScreen";

    if (flags & Qt::MSWindowsFixedSizeDialogHint)
        flagText += "\n| Qt::MSWindowsFixedSizeDialogHint";
    if (flags & Qt::X11BypassWindowManagerHint)
        flagText += "\n| Qt::X11BypassWindowManagerHint";
    if (flags & Qt::FramelessWindowHint)
        flagText += "\n| Qt::FramelessWindowHint";
    if (flags & Qt::NoDropShadowWindowHint)
        flagText += "\n| Qt::NoDropShadowWindowHint";
    if (flags & Qt::WindowTitleHint)
        flagText += "\n| Qt::WindowTitleHint";
    if (flags & Qt::WindowSystemMenuHint)
        flagText += "\n| Qt::WindowSystemMenuHint";
    if (flags & Qt::WindowMinimizeButtonHint)
        flagText += "\n| Qt::WindowMinimizeButtonHint";
    if (flags & Qt::WindowMaximizeButtonHint)
        flagText += "\n| Qt::WindowMaximizeButtonHint";
    if (flags & Qt::WindowCloseButtonHint)
        flagText += "\n| Qt::WindowCloseButtonHint";
    if (flags & Qt::WindowContextHelpButtonHint)
        flagText += "\n| Qt::WindowContextHelpButtonHint";
    if (flags & Qt::WindowShadeButtonHint)
        flagText += "\n| Qt::WindowShadeButtonHint";
    if (flags & Qt::WindowStaysOnTopHint)
        flagText += "\n| Qt::WindowStaysOnTopHint";
    if (flags & Qt::WindowStaysOnBottomHint)
        flagText += "\n| Qt::WindowStaysOnBottomHint";
    if (flags & Qt::CustomizeWindowHint)
        flagText += "\n| Qt::CustomizeWindowHint";


    text += "Window State:\n" + stateText;
    text += "\n\nFlags:\n" + flagText;

    qDebug() << this << text;
    textEdit->setPlainText(text);
}
