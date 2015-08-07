#ifndef FULLSCREEN_H
#define FULLSCREEN_H

#include <QApplication>
#include <QWidget>
#include <QDesktopWidget>
#include <QBoxLayout>

class FullscreenWindow : public QWidget
{
	Q_OBJECT

public:
	explicit FullscreenWindow(QWidget *parent = 0);
	~FullscreenWindow();

private slots:

signals:

public slots:

protected:
	QHBoxLayout *layout;
};

#endif // FULLSCREEN_H
