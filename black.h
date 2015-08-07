#ifndef BLACKWINDOW_H
#define BLACKWINDOW_H

#include "fullscreen.h"
#include <QTimer>
#include <QPainter>

class BlackWindow : public FullscreenWindow
{
	Q_OBJECT

public:
	explicit BlackWindow(QWidget *parent = 0);
	~BlackWindow();

protected:
	void paintEvent(QPaintEvent *event);

public slots:
	void update();

private:
	short frame;
	QTimer *timer;
};

#endif // BLACKWINDOW_H
