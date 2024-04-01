cmake_minimum_required(VERSION 3.5)

project(ObserverPatern LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ObserverPatern main.cpp
    Observer/Observer.h Observer/Observer.cpp
    Subject/Subject.h Subject/Subject.cpp
    Observer/IObserver.h
    Subject/ISubject.h
    Driver/Driver.h Driver/Driver.cpp
    Driver/IDriver.h)

include(GNUInstallDirs)
install(TARGETS ObserverPatern
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
