#include "controllerwindow.h"
#include "qapplication.h"
#include <qmessagebox.h>
#include <QDebug>


ControllerWindow::ControllerWindow(QWidget *parent)
    : QWidget{parent}
{
    previewWindow = new PreviewWindow();

    createTypeGroupBox();
    createHintsGroupBox();
    createWinTypeGroupBox();
    createLabelGroupBox();

    quitButton = new QPushButton(tr("&Quit"));
    openButton = new QPushButton(tr("&Open"));
    connect(quitButton, &QPushButton::clicked, qApp, &QApplication::quit);

    QHBoxLayout *bottomLayout = new QHBoxLayout;
    // bottomLayout->addStretch();
    bottomLayout->addWidget(quitButton);
    bottomLayout->addWidget(openButton);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(labelGroupBox);
    mainLayout->addWidget(winStyleGroupBox);
    mainLayout->addWidget(typeGroupBox);
    mainLayout->addWidget(hintsGroupBox);
    mainLayout->addLayout(bottomLayout);
    setLayout(mainLayout);

    setWindowTitle(tr("Window Flags"));
    updatePreview();
}

void ControllerWindow::createTypeGroupBox()
{
    typeGroupBox = new QGroupBox(tr("Window Flag: Type"));

    widgetRadioButton = createRadioButton(tr("Widget"));
    windowRadioButton = createRadioButton(tr("Window"));
    dialogRadioButton = createRadioButton(tr("Dialog"));
    sheetRadioButton = createRadioButton(tr("Sheet"));
    drawerRadioButton = createRadioButton(tr("Drawer"));
    popupRadioButton = createRadioButton(tr("Popup"));
    toolRadioButton = createRadioButton(tr("Tool"));
    toolTipRadioButton = createRadioButton(tr("Tooltip"));
    splashScreenRadioButton = createRadioButton(tr("Splash screen"));
    windowRadioButton->setChecked(true);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(widgetRadioButton, 0, 0);
    layout->addWidget(windowRadioButton, 1, 0);
    layout->addWidget(dialogRadioButton, 2, 0);
    layout->addWidget(sheetRadioButton, 3, 0);
    layout->addWidget(drawerRadioButton, 0, 1);
    layout->addWidget(popupRadioButton, 1, 1);
    layout->addWidget(toolRadioButton, 2, 1);
    layout->addWidget(toolTipRadioButton, 3, 1);
    layout->addWidget(splashScreenRadioButton, 4, 1);
    typeGroupBox->setLayout(layout);
}

void ControllerWindow::createHintsGroupBox()
    {
        hintsGroupBox = new QGroupBox(tr("Window Flag: Hints"));

    msWindowsFixedSizeDialogCheckBox = createCheckBox(tr("MS Windows fixed size dialog"));
    x11BypassWindowManagerCheckBox = createCheckBox(tr("X11 bypass window manager"));
    framelessWindowCheckBox = createCheckBox(tr("Frameless window"));
    windowNoShadowCheckBox = createCheckBox(tr("No drop shadow"));
    windowTitleCheckBox = createCheckBox(tr("Window title"));
    windowSystemMenuCheckBox = createCheckBox(tr("Window system menu"));
    windowMinimizeButtonCheckBox = createCheckBox(tr("Window minimize button"));
    windowMaximizeButtonCheckBox = createCheckBox(tr("Window maximize button"));
    windowCloseButtonCheckBox = createCheckBox(tr("Window close button"));
    windowContextHelpButtonCheckBox = createCheckBox(tr("Window context help button"));
    windowShadeButtonCheckBox = createCheckBox(tr("Window shade button"));
    windowStaysOnTopCheckBox = createCheckBox(tr("Window stays on top"));
    windowStaysOnBottomCheckBox = createCheckBox(tr("Window stays on bottom"));
    customizeWindowHintCheckBox= createCheckBox(tr("Customize window"));

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(msWindowsFixedSizeDialogCheckBox, 0, 0);
    layout->addWidget(x11BypassWindowManagerCheckBox, 1, 0);
    layout->addWidget(framelessWindowCheckBox, 2, 0);
    layout->addWidget(windowNoShadowCheckBox, 3, 0);
    layout->addWidget(windowTitleCheckBox, 4, 0);
    layout->addWidget(windowSystemMenuCheckBox, 5, 0);
    layout->addWidget(customizeWindowHintCheckBox, 6, 0);
    layout->addWidget(windowMinimizeButtonCheckBox, 0, 1);
    layout->addWidget(windowMaximizeButtonCheckBox, 1, 1);
    layout->addWidget(windowCloseButtonCheckBox, 2, 1);
    layout->addWidget(windowContextHelpButtonCheckBox, 3, 1);
    layout->addWidget(windowShadeButtonCheckBox, 4, 1);
    layout->addWidget(windowStaysOnTopCheckBox, 5, 1);
    layout->addWidget(windowStaysOnBottomCheckBox, 6, 1);
    hintsGroupBox->setLayout(layout);
}

void ControllerWindow::createWinTypeGroupBox(){
    winStyleGroupBox = new QGroupBox(tr("Window Style"));

    WindowNoStateButton = createCheckBox(tr("WindowNoState"));
    WindowMinimizedButton = createCheckBox(tr("WindowMinimized"));
    WindowMaximizedButton = createCheckBox(tr("WindowMaximized"));
    WindowFullScreenButton = createCheckBox(tr("WindowFullScreen"));
    WindowActiveButton = createCheckBox(tr("WindowActive"));

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(WindowNoStateButton, 0, 0);
    layout->addWidget(WindowMinimizedButton, 1, 0);
    layout->addWidget(WindowMaximizedButton, 2, 0);
    layout->addWidget(WindowFullScreenButton, 0, 1);
    layout->addWidget(WindowActiveButton, 1, 1);

    winStyleGroupBox->setLayout(layout);
}

void ControllerWindow::createLabelGroupBox(){
    labelGroupBox = new QGroupBox(tr("&Links"));

    QLabel *externalLinkHelpLbl = createLinkLable("<a href=\"https://stackoverflow.com/questions/8427446/making-qlabel-behave-like-a-hyperlink\">How to make external links</a>");
    QLabel *stateFlagLbl = createLinkLable("<a href=\"https://doc.qt.io/qt-6/qt.html#WindowState-enum\">Go To Reference Page</a>");

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(stateFlagLbl);
    layout->addWidget(externalLinkHelpLbl);

    labelGroupBox->setLayout(layout);
}

QCheckBox *ControllerWindow::createCheckBox(const QString &text)
{
    QCheckBox *checkBox = new QCheckBox(text);
    connect(checkBox, &QCheckBox::clicked,
            this, &ControllerWindow::updatePreview);
    return checkBox;
}

QRadioButton *ControllerWindow::createRadioButton(const QString &text)
{
    QRadioButton *button = new QRadioButton(text);
    connect(button, &QRadioButton::clicked,
            this, &ControllerWindow::updatePreview);
    return button;
}

QLabel *ControllerWindow::createLinkLable(const QString &text)
{
    QLabel *myLabel = new QLabel(text);
    myLabel->setText(text);
//    myLabel->setText("<a href=\"https://stackoverflow.com/questions/8427446/making-qlabel-behave-like-a-hyperlink\">How to make external links</a><br/><a href=\"https://doc.qt.io/qt-6/qt.html#WindowState-enum\">Go To Reference Page</a>");
    myLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);
    connect(myLabel, &QLabel::linkActivated, this, &ControllerWindow::on_myLabel_linkActivated);
    return myLabel;
}

void ControllerWindow::updatePreview()
{
    Qt::WindowStates state = Qt::WindowNoState;
    Qt::WindowFlags flags;

    if (WindowNoStateButton->isChecked())
        state |= Qt::WindowState::WindowNoState;
    if (WindowMinimizedButton->isChecked())
        state |= Qt::WindowState::WindowMinimized;
    if (WindowMaximizedButton->isChecked())
        state |= Qt::WindowState::WindowMaximized;
    if (WindowFullScreenButton->isChecked())
        state |= Qt::WindowState::WindowFullScreen;
    if (WindowActiveButton->isChecked())
        state |= Qt::WindowState::WindowActive;


    if (windowRadioButton->isChecked())
        flags = Qt::Widget;
    else if (windowRadioButton->isChecked())
        flags = Qt::Window;
    else if (dialogRadioButton->isChecked())
        flags = Qt::Dialog;
    else if (sheetRadioButton->isChecked())
        flags = Qt::Sheet;
    else if (drawerRadioButton->isChecked())
        flags = Qt::Drawer;
    else if (popupRadioButton->isChecked())
        flags = Qt::Popup;
    else if (toolRadioButton->isChecked())
        flags = Qt::Tool;
    else if (toolTipRadioButton->isChecked())
        flags = Qt::ToolTip;
    else if (splashScreenRadioButton->isChecked())
        flags = Qt::SplashScreen;

    if (msWindowsFixedSizeDialogCheckBox->isChecked())
        flags |= Qt::MSWindowsFixedSizeDialogHint;
    if (x11BypassWindowManagerCheckBox->isChecked())
        flags |= Qt::X11BypassWindowManagerHint;
    if (framelessWindowCheckBox->isChecked())
        flags |= Qt::FramelessWindowHint;
    if (windowNoShadowCheckBox->isChecked())
        flags |= Qt::NoDropShadowWindowHint;
    if (windowTitleCheckBox->isChecked())
        flags |= Qt::WindowTitleHint;
    if (windowSystemMenuCheckBox->isChecked())
        flags |= Qt::WindowSystemMenuHint;
    if (windowMinimizeButtonCheckBox->isChecked())
        flags |= Qt::WindowMinimizeButtonHint;
    if (windowMaximizeButtonCheckBox->isChecked())
        flags |= Qt::WindowMaximizeButtonHint;
    if (windowCloseButtonCheckBox->isChecked())
        flags |= Qt::WindowCloseButtonHint;
    if (windowContextHelpButtonCheckBox->isChecked())
        flags |= Qt::WindowContextHelpButtonHint;
    if (windowShadeButtonCheckBox->isChecked())
        flags |= Qt::WindowShadeButtonHint;
    if (windowStaysOnTopCheckBox->isChecked())
        flags |= Qt::WindowStaysOnTopHint;
    if (windowStaysOnBottomCheckBox->isChecked())
        flags |= Qt::WindowStaysOnBottomHint;
    if (customizeWindowHintCheckBox->isChecked())
        flags |= Qt::CustomizeWindowHint;

    qDebug() << this << "ControllerWindow::updatePreview(): " << windowFlagsToString(flags);

    previewWindow->setWindowFlags(flags, state);

    QPoint pos = previewWindow->pos();
    if (pos.x() < 0)
        pos.setX(150);
    if (pos.y() < 0)
        pos.setY(150);
    previewWindow->move(pos);
    // previewWindow->setGeometry(120,130,140,150);
    previewWindow->show();
}

void ControllerWindow::on_myLabel_linkActivated(const QString &link)
{
    qDebug() << this << "on_myLabel_linkActivated(const QString &link) -> link = " << link;
    // QDesktopServices::openUrl(QUrl("http://www.example.com/"));
    QDesktopServices::openUrl(QUrl(link));
}

QString ControllerWindow::windowFlagsToString(Qt::WindowFlags flags) {
    QStringList flagStrings;

    if (flags & Qt::Window) flagStrings.append("Qt::Window");
    if (flags & Qt::Dialog) flagStrings.append("Qt::Dialog");
    if (flags & Qt::Sheet) flagStrings.append("Qt::Sheet");
    if (flags & Qt::Drawer) flagStrings.append("Qt::Drawer");
    if (flags & Qt::Popup) flagStrings.append("Qt::Popup");
    if (flags & Qt::Tool) flagStrings.append("Qt::Tool");
    if (flags & Qt::ToolTip) flagStrings.append("Qt::ToolTip");
    if (flags & Qt::SplashScreen) flagStrings.append("Qt::SplashScreen");

    if (flags & Qt::MSWindowsFixedSizeDialogHint) flagStrings.append("Qt::MSWindowsFixedSizeDialogHint");
    if (flags & Qt::X11BypassWindowManagerHint) flagStrings.append("Qt::X11BypassWindowManagerHint");
    if (flags & Qt::FramelessWindowHint) flagStrings.append("Qt::FramelessWindowHint");
    if (flags & Qt::NoDropShadowWindowHint) flagStrings.append("Qt::NoDropShadowWindowHint");
    if (flags & Qt::WindowTitleHint) flagStrings.append("Qt::WindowTitleHint");
    if (flags & Qt::WindowSystemMenuHint) flagStrings.append("Qt::WindowSystemMenuHint");
    if (flags & Qt::WindowMinimizeButtonHint) flagStrings.append("Qt::WindowMinimizeButtonHint");
    if (flags & Qt::WindowMaximizeButtonHint) flagStrings.append("Qt::WindowMaximizeButtonHint");
    if (flags & Qt::WindowCloseButtonHint) flagStrings.append("Qt::WindowCloseButtonHint");
    if (flags & Qt::WindowContextHelpButtonHint) flagStrings.append("Qt::WindowContextHelpButtonHint");
    if (flags & Qt::WindowShadeButtonHint) flagStrings.append("Qt::WindowShadeButtonHint");
    if (flags & Qt::WindowStaysOnTopHint) flagStrings.append("Qt::WindowStaysOnTopHint");
    if (flags & Qt::WindowStaysOnBottomHint) flagStrings.append("Qt::WindowStaysOnBottomHint");
    if (flags & Qt::CustomizeWindowHint) flagStrings.append("Qt::CustomizeWindowHint");

    return flagStrings.join(" | ");
}
