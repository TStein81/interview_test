TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
#CONFIG+= c++14

QMAKE_CXXFLAGS -= -O2 -std=gnu++1y
QMAKE_CFLAGS -= -O2 -std=gnu++1y
QMAKE_CXXFLAGS_RELEASE -= -O2 -std=gnu++1y
QMAKE_CXXFLAGS_DEBUG -= -O1 -g -std=gnu++1y
QMAKE_CXX -= -std=gnu++1y
QMAKE_CXXFLAGS += -O3 -std=c++14
SOURCES += \
        main.cpp
message($QMAKE_CXXFLAGS_RELEASE)

HEADERS += \
    factorial_test.h \
    list_of_names_test.h
