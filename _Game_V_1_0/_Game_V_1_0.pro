TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lgdi32 -luser32 -mwindows
SOURCES += \
        Types/Attack.cpp \
        Types/Board_V_1_0.cpp \
        Graph/Create_Display.cpp \
        Graph/Create_GButton.cpp \
        Graph/Create_GProgress_Bar.cpp \
        Graph/DisplayWndProc.cpp \
        Graph/Game_Proc.cpp \
        Graph/Game_Window.cpp \
        Graph/GetCDisplay.cpp \
        Graph/GetGWindow.cpp \
        Types/Get_Stone.cpp \
        Types/Get_Type.cpp \
        Types/Put_Stone.cpp \
        Graph/RegisterGWindowClass.cpp \
        Graph/Set_GButton_Image.cpp \
        Types/Set_Stone.cpp \
        Types/Stone_V_1_0.cpp \
        Types/Take_Stone_from_Board.cpp \
        main.cpp

HEADERS += \
    Types/Board_V_1_0.h \
    Game_Constants_V_1_0.hpp \
    Graph/Game_Graph_V_1_0.hpp \
    Game_Lib_V_1_0.hpp \
    Graph/Game_Proc_V_1_0.hpp \
    Types/Game_Types_V_1_0.hpp \
    Graph_Constants_V_1_0.h \
    Types/Stone_V_1_0.h \
    Types/cell.h \
    Types/damage.h \
    Types/player.h \
    Types/stone_type.h


RC_FILE += \
    Game_Resource.rc

DISTFILES +=
