#include "bsod.h"

BSODWindow::BSODWindow(QWidget *parent) : FullscreenWindow(parent)
{
	QPalette Pal(palette());
	Pal.setColor(QPalette::Background, QColor("#0000b5"));
	this->setAutoFillBackground(true);
	this->setPalette(Pal);

	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(showImage()));
	timer->setInterval(100);
	timer->start();
}

BSODWindow::~BSODWindow()
{

}

void BSODWindow::showImage()
{
	img = new QLabel();
	img->setPixmap(QPixmap("images/bsod.gif"));
	layout->addWidget(img, 0, Qt::AlignCenter);
	timer->stop();
}

