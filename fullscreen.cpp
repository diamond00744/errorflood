#include "fullscreen.h"

FullscreenWindow::FullscreenWindow(QWidget *parent) : QWidget(parent)
{
	// Make our window without panels
	this->setWindowFlags( Qt::FramelessWindowHint | Qt::Tool );
	// Resize refer to desktop
	QDesktopWidget *desktop = new QDesktopWidget();
	this->resize( desktop->size() );

	this->setCursor(Qt::BlankCursor);
	this->setFocusPolicy( Qt::StrongFocus );
	this->setAttribute(Qt::WA_QuitOnClose, true);

	qApp->processEvents();

	layout = new QHBoxLayout();
	setLayout(layout);
}

FullscreenWindow::~FullscreenWindow()
{

}

