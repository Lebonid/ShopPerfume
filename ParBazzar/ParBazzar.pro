QT += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    auth.cpp \
    d_account.cpp \
    d_sum.cpp \
    dcreate_user.cpp \
    dialog.cpp \
    dialog2.cpp \
    dialog_insert.cpp \
    dialog_stor.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    auth.h \
    d_account.h \
    d_sum.h \
    dcreate_user.h \
    dialog.h \
    dialog2.h \
    dialog_insert.h \
    dialog_stor.h \
    mainwindow.h

FORMS += \
    auth.ui \
    d_account.ui \
    d_sum.ui \
    dcreate_user.ui \
    dialog.ui \
    dialog2.ui \
    dialog_insert.ui \
    dialog_stor.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
