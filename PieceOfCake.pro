HEADERS += \
    AbstractController.h \
    Commands.h \
    GameController.h \
    GameModel.h \
    GameView.h \
    Hint.h \
    LevelDesignerController.h \
    LevelDesignerTreeItemDelegate.h \
    LevelDesignerModel.h \
    LevelDesignerScribbleView.h \
    LevelDesignerTreeView.h \
    #MainMenuWidget.h \
    MainWindow.h \
    ParserXML.h \
    Point2d.h \
    Polygon.h \
    Segment.h \
    TreeItem.h \
    TreeModel.h \
    Vector2d.h \
    tests.h \
    LineModifier.h \
    Tape.h \
    Portal.h \
    Obstacle.h \
    Deviation.h

SOURCES += \
    AbstractController.cpp \
    Commands.cpp \
    GameController.cpp \
    GameModel.cpp \
    GameView.cpp \
    Hint.cpp \
    LevelDesignerController.cpp \
    LevelDesignerTreeItemDelegate.cpp \
    LevelDesignerModel.cpp \
    LevelDesignerScribbleView.cpp \
    LevelDesignerTreeView.cpp \
    #MainMenuWidget.cpp \
    MainWindow.cpp \
    ParserXML.cpp \
    Point2d.cpp \
    Polygon.cpp \
    Segment.cpp \
    TreeItem.cpp \
    TreeModel.cpp \
    Vector2d.cpp \
    tests.cpp \
    main.cpp \
    LineModifier.cpp \
    Tape.cpp \
    Portal.cpp \
    Obstacle.cpp \
    Deviation.cpp

CONFIG += c++11

QT += \
    core \
    gui \
    widgets \
    xml
