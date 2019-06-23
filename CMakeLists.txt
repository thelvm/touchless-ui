CMAKE_MINIMUM_REQUIRED(VERSION 3.0.0)
PROJECT(touchless-ui VERSION 0.1.0)

FIND_PACKAGE(Threads)
SET(PKG_MODULES
        gtkmm-3.0
        gio-unix-2.0
        )

FIND_PACKAGE(PkgConfig REQUIRED)
pkg_check_modules(PKGS REQUIRED ${PKG_MODULES})

SET(LEAP_SDK_DIR /home/lucas/leapSDK/2.3.1)

SET(SOURCES
        src/main.cpp
        src/EditKeyframe.cpp
        src/EditGestureWindow.cpp
        )



LINK_LIBRARIES(
        /home/lucas/Documents/software_project/Code/gesture_parser_api/lib/libgesture_parser.a
        ${CMAKE_THREAD_LIBS_INIT}
        ${PKGS_LIBRARIES}
        ${LEAP_SDK_DIR}/lib/x64/libLeap.so
)

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

ADD_EXECUTABLE(touchless-ui ${SOURCES})
TARGET_INCLUDE_DIRECTORIES(touchless-ui PUBLIC
        "${LEAP_SDK_DIR}/include"
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
        "/home/lucas/Documents/software_project/Code/gesture_parser_api/include"
        "${PKGS_INCLUDE_DIRS}"
)

TARGET_COMPILE_OPTIONS(touchless-ui PUBLIC ${PKGS_CFLAGS_OTHERS})
