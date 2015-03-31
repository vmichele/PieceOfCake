#ifndef TESTLEVELCONTROLLER_HXX
#define TESTLEVELCONTROLLER_HXX

#include "GameController.h"
#include "LevelInfo.h"

class TestLevelController: public GameController {
  Q_OBJECT

public:
  TestLevelController(GameModel* model, QUndoStack* undoStack, LevelInfo* levelInfo, QObject* parent = nullptr);
  virtual ~TestLevelController(void);

  inline void setTestIsOver(bool b) { _testIsOver = b; }

  void resetGameInfo(void);

public slots:
  void openLevel(const QString& fileName) final;
  //void saveLevel(const QString& fileName) final;
  void addNewLine(const Segment& line);
  void computeOrientedArea(void);
  void checkWinning(void) override;

signals:
  void levelCanBeSaved(bool);

private:
  bool _testIsOver;
  LevelInfo* _levelInfo;

};

#endif // TESTLEVELCONTROLLER_HXX
