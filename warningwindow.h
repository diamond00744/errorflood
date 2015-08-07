#ifndef WARNINGWINDOW_H
#define WARNINGWINDOW_H

#include <QApplication>
#include <QDialog>
#include <QDesktopWidget>
#include <QTimer>
#include <QFile>
#include <QTextStream>
#include "bsod.h"
#include "black.h"

namespace Ui {
class WarningWindow;
}

class WarningWindow : public QDialog
{
	Q_OBJECT

public:
	explicit WarningWindow(QWidget *parent = 0);
	~WarningWindow();

private slots:
	void on_btnOK_clicked();
	void on_timer_tick();

private:
	QTimer *timer;
	short currentClick; // current OK button click counter
	short currentTick; // current timer tick counter
	enum state {stBegin, stBSOD, stOff}; // flags of current state
	state currentState;
	short deskWidth, deskHeight; // system resolution

	Ui::WarningWindow *ui; // window UI

	WarningWindow *sec[20]; // array of secondary windows
	BSODWindow *bsod;
	BlackWindow *black;
};

#endif // WARNINGWINDOW_H
