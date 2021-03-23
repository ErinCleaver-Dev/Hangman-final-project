QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    hangman/FileMangement.cpp \
    hangman/HighScore.cpp \
    hangman/Hint.cpp \
    hangman/StringList.cpp \
    hangman/hangman.cpp \
    hangman/wordControler.cpp \
    main/main.cpp \
    mainwindow/mainwindow.cpp \
    mainwindow/splashscreen.cpp \
    validation/validation.cpp


HEADERS += \
    hangman/FileMangement.h \
    hangman/HighScore.h \
    hangman/Hint.h \
    hangman/StringList.h \
    hangman/hangman.h \
    hangman/wordControler.h \
    mainwindow/mainwindow.h \
    mainwindow/splashscreen.h \
    validation/validation.h


FORMS += \
    mainwindow/mainwindow.ui



DISTFILES += \
    highScroe.txt \
    quotes.txt \
    splashIcon.png \
    termsfile.txt

RESOURCES += \
    Images.qrc

VERSION = 1.0.0.0

DEFINES += APPLICATION_VER=\\\"$$VERSION\\\"
