#ifndef BSODWINDOW_H
#define BSODWINDOW_H

#include "fullscreen.h"
#include <QLabel>
#include <QTimer>

class BSODWindow : public FullscreenWindow
{
	Q_OBJECT

public:
	explicit BSODWindow(QWidget *parent = 0);
	~BSODWindow();

private slots:
	void showImage();

private:
	QTimer *timer;
	QLabel *img;
};

#endif // BSODWINDOW_H
