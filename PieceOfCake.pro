TEMPLATE = app

RESOURCES += qml.qrc

HEADERS += \
  # Controller
  Controller/AbstractController.h \
  Controller/GameController.h \
  Controller/LevelDesignerController.h \
  Controller/TestLevelController.h \
  # Core
  Core/Point2d.h \
  Core/Polygon.h \
  Core/Segment.h \
  Core/Vector2d.h \
  # Delegate
  Delegate/LevelDesignerTreeItemDelegate.h \
  # Item
  Item/TreeItem.h \
  # LineModifier
  LineModifier/Deviation.h \
  LineModifier/LineModifier.h \
  LineModifier/Mirror.h \
  LineModifier/Obstacle.h \
  LineModifier/Portal.h \
  LineModifier/Tape.h \
  # Model
  Model/GameModel.h \
  Model/LevelDesignerModel.h \
  Model/TreeModel.h \
  # View
  View/GameView.h \
  ## REMOVE View/LevelDesignerGameStatView.h \
  View/LevelDesignerScribbleView.h \
  View/LevelDesignerTreeView.h \
  ## REMOVE View/LevelDesignerWidget.h \
  # Root
  Commands.h \
  GameInfo.h \
  Hint.h \
  LevelInfo.h \
  MainWindow.h \
  ParserXML.h \
  tests.h \
  ThumbnailCreator.h \
    View/TestLevelView.h \
    LineModifier/Refractor.h \
    Model/LineModifierModel.h \
    View/TestLevelTreeView.h \
    Model/TestLevelModel.h \
    Delegate/TestLevelTreeItemDelegate.h

SOURCES += \
  # Controller
  Controller/AbstractController.cpp \
  Controller/GameController.cpp \
  Controller/LevelDesignerController.cpp \
  Controller/TestLevelController.cpp \
  # Core
  Core/Point2d.cpp \
  Core/Polygon.cpp \
  Core/Segment.cpp \
  Core/Vector2d.cpp \
  # Delegate
  Delegate/LevelDesignerTreeItemDelegate.cpp \
  # Item
  Item/TreeItem.cpp \
  # LineModifier
  LineModifier/Deviation.cpp \
  LineModifier/LineModifier.cpp \
  LineModifier/Mirror.cpp \
  LineModifier/Obstacle.cpp \
  LineModifier/Portal.cpp \
  LineModifier/Tape.cpp \
  # Model
  Model/GameModel.cpp \
  Model/LevelDesignerModel.cpp \
  Model/TreeModel.cpp \
  # View
  View/GameView.cpp \
  ## REMOVE View/LevelDesignerGameStatView.cpp \
  View/LevelDesignerScribbleView.cpp \
  View/LevelDesignerTreeView.cpp \
  ## REMOVE View/LevelDesignerWidget.cpp \
  # Root
  Commands.cpp \
  GameInfo.cpp \
  Hint.cpp \
  LevelInfo.cpp \
  main.cpp \
  MainWindow.cpp \
  ParserXML.cpp \
  ThumbnailCreator.cpp \
    View/TestLevelView.cpp \
    LineModifier/Refractor.cpp \
    Model/LineModifierModel.cpp \
    View/TestLevelTreeView.cpp \
    Model/TestLevelModel.cpp \
    Delegate/TestLevelTreeItemDelegate.cpp

INCLUDEPATH += \
  Controller \
  Core \
  Delegate \
  Item \
  LineModifier \
  Model \
  View \
  QML-Utils

CONFIG += \
  c++11

QT += \
  core \
  gui \
  qml \
  quick \
  quickwidgets \
  widgets \
  xml

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)
