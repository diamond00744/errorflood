#include "black.h"

BlackWindow::BlackWindow(QWidget *parent) : FullscreenWindow(parent)
{
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);

	QPalette Pal(palette());
	Pal.setColor(QPalette::Background, Qt::black);
	this->setAutoFillBackground(true);
	this->setPalette(Pal);

	frame = 0;
	update();
	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(update()));
	timer->setInterval(50);
	timer->start();
}

BlackWindow::~BlackWindow()
{

}

void BlackWindow::update()
{
	QWidget::update();
}

void BlackWindow::paintEvent(QPaintEvent*)
{
	QColor white(255, 255, 255);
	QColor grey(200, 200, 200);
	QColor darkgrey(100, 100, 100);

	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.setPen(Qt::NoPen);
	painter.setBrush(white);

	if (frame == 0)
		painter.drawRect(0, 0, this->width(), this->height());
	if (frame == 1)
		painter.drawRect(0, this->height() / 6, this->width(), this->height() - this->height() / 3);
	if (frame == 2)
		painter.drawRect(0, this->height() / 4, this->width(), this->height() - this->height() / 2);
	if (frame == 3)
		painter.drawRect(0, this->height() / 2 - 5, this->width(), 10);
	if (frame > 3)
		painter.setBrush(grey);
	if (frame == 4)
		painter.drawRect(this->width() / 6, this->height() / 2 - 5, 4 * this->width() / 6, 10);
	if (frame == 5)
		painter.drawRect(this->width() / 5, this->height() / 2 - 5, 3 * this->width() / 5, 10);
	if (frame == 6)
		painter.drawRect(this->width() / 4, this->height() / 2 - 5, 2 * this->width() / 4, 10);
	if (frame == 7)
		painter.drawRect(this->width() / 3, this->height() / 2 - 5, 1 * this->width() / 3, 10);
	if (frame == 8)
		painter.drawRect(this->width() / 2 - 5, this->height() / 2 - 5, 10, 10);
	if (frame == 9) {
		painter.setBrush(darkgrey);
		painter.drawRect(this->width() / 2 - 5, this->height() / 2 - 5, 10, 10);
	}
	frame++;
}

