#include "LevelInfo.h"

LevelInfo::LevelInfo(QObject* parent):
  QObject(parent),
  _levelReadyToBeTested(false),
  _levelReadyToBeCut(false) {
}

bool LevelInfo::levelReadyToBeTested(void) const {
  return _levelReadyToBeTested;
}

void LevelInfo::setLevelReadyToBeTested(bool value) {
  if (value != _levelReadyToBeTested) {
    _levelReadyToBeTested = value;
    emit levelReadyToBeTestedChanged();
  }
}

void LevelInfo::updateLevelReadyToBeTested(const PolygonList& polygonList) {
  for (const poc::Polygon& polygon: polygonList) {
    if (polygon.getVertices().size() < 3) {
      setLevelReadyToBeTested(false);
      return;
    }
  }

  setLevelReadyToBeTested(true);
}

bool LevelInfo::levelReadyToBeCut(void) const {
  return _levelReadyToBeCut;
}

void LevelInfo::setLevelReadyToBeCut(bool value) {
  if (value != _levelReadyToBeCut) {
    _levelReadyToBeCut = value;
    emit levelReadyToBeCutChanged();
  }
}

void LevelInfo::updateLevelReadyToBeCut(int linesDrawn) {
  setLevelReadyToBeCut(linesDrawn > 0);
}
