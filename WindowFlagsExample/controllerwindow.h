#ifndef TESTWIDGET_H
#define TESTWIDGET_H

#include <QWidget>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QPushButton>
#include <QRadioButton>
#include <QCheckBox>
#include <QLabel>
#include <QDesktopServices>

#include "previewwindow.h"


class NewWindow : public QWidget {
public:
    NewWindow(QWidget *parent = nullptr) : QWidget(parent) {
        setGeometry(500, 500, 400, 300);
        setFixedSize(300, 200);
        setWindowTitle("New Window");
        show();
    }
};

class ControllerWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ControllerWindow(QWidget *parent = nullptr);
    QString windowFlagsToString(Qt::WindowFlags flags);

private slots:
    void updatePreview();
    void on_myLabel_linkActivated(const QString &link);

private:
    void createTypeGroupBox();
    void createHintsGroupBox();
    void createWinTypeGroupBox();
    void createLabelGroupBox();
    QCheckBox *createCheckBox(const QString &text);
    QRadioButton *createRadioButton(const QString &text);
    QLabel *createLinkLable(const QString &text);

    PreviewWindow *previewWindow;
    NewWindow *newWindow;

    QGroupBox *typeGroupBox;
    QGroupBox *hintsGroupBox;
    QGroupBox *winStyleGroupBox;
    QGroupBox *labelGroupBox;
    QPushButton *quitButton;
    QPushButton *openButton;

    QRadioButton *widgetRadioButton;
    QRadioButton *windowRadioButton;
    QRadioButton *dialogRadioButton;
    QRadioButton *sheetRadioButton;
    QRadioButton *drawerRadioButton;
    QRadioButton *popupRadioButton;
    QRadioButton *toolRadioButton;
    QRadioButton *toolTipRadioButton;
    QRadioButton *splashScreenRadioButton;

    QCheckBox *msWindowsFixedSizeDialogCheckBox;
    QCheckBox *x11BypassWindowManagerCheckBox;
    QCheckBox *framelessWindowCheckBox;
    QCheckBox *windowNoShadowCheckBox;
    QCheckBox *windowTitleCheckBox;
    QCheckBox *windowSystemMenuCheckBox;
    QCheckBox *windowMinimizeButtonCheckBox;
    QCheckBox *windowMaximizeButtonCheckBox;
    QCheckBox *windowCloseButtonCheckBox;
    QCheckBox *windowContextHelpButtonCheckBox;
    QCheckBox *windowShadeButtonCheckBox;
    QCheckBox *windowStaysOnTopCheckBox;
    QCheckBox *windowStaysOnBottomCheckBox;
    QCheckBox *customizeWindowHintCheckBox;


    QCheckBox *WindowNoStateButton;
    QCheckBox *WindowMinimizedButton;
    QCheckBox *WindowMaximizedButton;
    QCheckBox *WindowFullScreenButton;
    QCheckBox *WindowActiveButton;
signals:
};


#endif // TESTWIDGET_H
