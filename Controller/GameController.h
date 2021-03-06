#ifndef GAMECONTROLLER_HXX
#define GAMECONTROLLER_HXX

#include "AbstractController.h"

#include "GameModel.h"
#include "GameInfo.h"

#include "Vector2d.h"

class GameController: public AbstractController {
  Q_OBJECT

public:
  enum LineType {
    goodCrossing,
    badCrossing,
    noCrossing,
    unknownCrossing
  };

  GameController(GameModel* model, QUndoStack* undoStack, QObject* parent = nullptr);
  virtual ~GameController(void);

  inline bool isLevelRunning() const { return _levelRunning; }
  GameInfo* getGameInfo(void) const;

  Point2d* getOtherBound(const Point2d* intersection, const std::vector<std::pair<Point2d*, Point2d*>>& cuttingSegments) const;
  std::vector<std::pair<Point2d*, Point2d*>> getCuttingSegments(const std::vector<Point2d*>& intersections) const;
  bool stillHasBaseVertices(const std::vector<Point2d*>& verticesGlobal, const std::vector<Point2d*>& intersections) const;
  void cleanIntersections(const poc::Polygon& polygon, std::vector<Point2d*>& intersections) const;
  void getVerticesAndIntersections(const Segment& line, const poc::Polygon& polygon,
    std::vector<Point2d*>& globalVertices, std::vector<Point2d*>& intersections) const;
  virtual void sliceIt(const std::vector<Segment>& lines);
  void computeNewPolygonList(PolygonList& newPolygonList, const Segment& line) const;

  LineType computeLineType(const std::vector<Segment>& lines) const;
  void updateStarsMax(int starsMaxCount);
  void translatePolygons(const QList<Vector2d>& shiftVectors);
  void clearGame(void);

  Deviation* getNearestDeviation(const Segment& line) const;
  void computeDeviateLines(float firstLineLength, const Segment& line, std::vector<Segment>& lines) const;

  float computePolygonPercentageArea(const poc::Polygon& polygon) const;
  Point2d computeGlobalBarycenter() const;

public slots:
  virtual void openLevel(const QString& fileName);
  virtual void saveLevel(const QString& fileName) { Q_UNUSED(fileName) }
  void replay(void);
  virtual void checkWinning(void);
  void undoSliceIt(void);

signals:
  void updateLine(LineType);
  void update(void);
  void levelEnd(QList<float>);

protected:
  GameModel* _model;
  GameInfo* _gameInfo;
  float _orientedAreaTotal;
  int _maxGapToWin;
  QString _fileName;
  bool _levelRunning;
  QList<PolygonList> _polygonListPerTurn;
};

bool pointCompare(const Point2d* A, const Point2d* B);

#endif // GAMECONTROLLER_HXX
