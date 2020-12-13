QT -= qui
QT += core sql
CONFIG += C++11
TEMPLATE = lib

DESTDIR = $$PWD/../shared/lib
CONFIG += debug

INCLUDEPATH += $$PWD/include/

HEADERS +=  \
            include/ConnectionManager.h \
            include/DBMapper.h \
            include/DBTypes.h \
            include/Executor.h \
            include/Manipulator.h \
            include/Processor.h \
            include/Selector.h


SOURCES +=  \
            src/Manipulator.cpp \
            src/ConnectionManager.cpp \
            src/Executor.cpp \
            src/Processor.cpp \
            src/Selector.cpp

headers.path = $$PWD/../shared/include
headers.files = include/DBTypes.h \
                include/Processor.h
INSTALLS += headers
