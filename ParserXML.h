#ifndef PARSERXML_H
#define PARSERXML_H

#include <QtXml>

#include "Point2d.h"
#include "Segment.h"
#include "Polygon.h"
#include "Tape.h"
#include "Mirror.h"
#include "Portal.h"
#include "Refractor.h"
#include "Hint.h"

typedef QList<poc::Polygon> PolygonList;
typedef QList<Tape> TapeList;
typedef QList<Mirror> MirrorList;
typedef QList<Portal> PortalList;
typedef QList<Refractor> RefractorList;
typedef QList<Hint> HintList;

class ParserXML {
public:
  ParserXML(void);
  ParserXML(const QString& xmlFileName);
  ParserXML(const ParserXML& parserXML);
  virtual ~ParserXML(void);

  inline int getPolygonNodesCount(void) const { return _polygonNodesCount; }
  //inline void setFileName(const QString& xmlFileName) { _xmlFileName = xmlFileName; }

  QDomElement intToNode(int value, const QString& nodeName);
  QDomElement pointToNode(const Point2d& point, const QString& nodeName);
  QDomElement segmentToNode(const Segment& segment);
  QDomElement partscountToNode(unsigned int partscount = 1);
  QDomElement linescountToNode(unsigned int linescount = 0);
  QDomElement starscountToNode(unsigned int starscount = 0);
  QDomElement tolerancesToNode(unsigned int tolerances = 1);
  QDomElement polygonToNode(const poc::Polygon& polygon, int id);
  QDomElement tapeToNode(const Tape& tape, int id);
  QDomElement mirrorToNode(const Mirror& mirror, int id);
  QDomElement portalToNode(const Portal& portal, int id);
  QDomElement refractorToNode(const Refractor& refractor, int id);
  QDomElement hintToNode(const Hint& hint, int id);

  void addPolygon(const poc::Polygon& polygon);
  void addTape(const Tape& tape);
  void addMirror(const Mirror& mirror);
  void addPortal(const Portal& portal);
  void addRefractor(const Refractor& refractor);
  void addHint(const Hint& hint);

  QDomElement getElementById(const QDomElement& parent, const QString& name, int id);
  QDomElement getPolygon(int id);
  QDomElement getTape(int id);
  QDomElement getMirror(int id);
  QDomElement getPortal(int id);
  QDomElement getRefractor(int id);
  QDomElement getHint(int id);

  void setPartsCount(int partscount);
  void setLinesCount(int linescount);
  void setMaxGapToWin(int maxgaptowin);
  void setStarsCount(int starscount);
  void setTolerances(int tolerances);

  void replacePolygon(const poc::Polygon& polygon, int id);
  void replaceTape(const Tape& tape, int id);
  void replaceMirror(const Mirror& mirror, int id);
  void replacePortal(const Portal& portal, int id);
  void replaceRefractor(const Refractor& refractor, int id);
  void replaceHint(const Hint& hint, int id);

  bool removeElement(QDomElement& supElement, QDomElement& subElement, int id);
  bool removePolygon(int id);
  bool removeTape(int id);
  bool removeMirror(int id);
  bool removePortal(int id);
  bool removeRefractor(int id);
  bool removeHint(int id);

  int createInt(const QDomElement& element, const QString& attributeName);
  float createFloat(const QDomElement& element, const QString& attributeName);
  Point2d createPoint(const QDomElement& element);
  Segment createSegment(const QDomElement& element);

  int getIntValue(const QString& tagName, const QString& attributeName = "value");
  int getPartsCount(void);
  int getLinesCount(void);
  int getMaxGapToWin(void);
  int getStarsCount(void);
  int getTolerances(void);

  poc::Polygon createPolygon(const QDomElement& element);
  Tape createTape(const QDomElement& element);
  Mirror createMirror(const QDomElement& element);
  Portal createPortal(const QDomElement& element);
  Refractor createRefractor(const QDomElement& element);
  Hint createHint(const QDomElement& element);

  PolygonList createPolygonList(void);
  TapeList createTapeList(void);
  MirrorList createMirrorList(void);
  PortalList createPortalList(void);
  RefractorList createRefractorList(void);
  HintList createHintList(void);

  inline QDomDocument getDoc() const { return _doc; }
  inline void initFileName(const QString& fileName) { if (_xmlFileName.isEmpty()) _xmlFileName = fileName; }

  ParserXML& operator=(const ParserXML& parser);

  void writeXML(int indent = 4);

private:
  QString _xmlFileName;

  QDomDocument _doc;

  QDomElement _polygons;
  QDomElement _lineModifiers;
  QDomElement _tapes;
  QDomElement _mirrors;
  QDomElement _portals;
  QDomElement _refractors;
  QDomElement _hints;

  int _polygonNodesCount;
  int _tapeNodesCount;
  int _mirrorNodesCount;
  int _portalNodesCount;
  int _refractorNodesCount;
  int _hintNodesCount;
};

#endif // PARSERXML_H
