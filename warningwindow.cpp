#include "warningwindow.h"
#include "ui_warningwindow.h"

WarningWindow::WarningWindow(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::WarningWindow)
{
	currentClick = 0;

	QDesktopWidget *desktop = new QDesktopWidget();
	deskWidth = desktop->geometry().width();
	deskHeight = desktop->geometry().height();

	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(on_timer_tick()));

	ui->setupUi(this);
}

WarningWindow::~WarningWindow()
{
	delete ui;
}

void WarningWindow::on_btnOK_clicked()
{
	currentClick++;
	if (currentClick == 6) {
		state = 1; //begin state
		currentTick = 0;
		timer->setInterval(500);
		timer->start();
	}
}

void WarningWindow::on_timer_tick()
{
	int nextWidth, nextHeight;
	if (state == 1) {
		if (currentTick < 5) {
			nextWidth = 30 + 50 * currentTick;
			nextHeight = 30 + 50 * currentTick;
		} else {
			nextWidth = rand() % (deskWidth - this->geometry().width());
			nextHeight = rand() % (deskHeight - this->geometry().height());
		}

		if (currentTick == 2)
			timer->setInterval(150);
		if (currentTick == 5)
			timer->setInterval(100);

		sec[currentTick] = new WarningWindow(this);
		sec[currentTick]->move(nextWidth, nextHeight);
		sec[currentTick]->show();
		sec[currentTick]->setFocus();

		if (currentTick == 16) {
			for (int i = 0; i <= currentTick; i++)
				sec[i]->close();

			currentTick = -2;
			state = 2; //bsod state
			bsod = new BSODWindow();
			bsod->show();
			bsod->setFocus();
			hide();
			timer->setInterval(2000);
		}

	} else if (state == 2) {
		if (currentTick == -1) {
			timer->setInterval(50);
		} else {
			nextWidth = rand() % (deskWidth - this->geometry().width());
			nextHeight = rand() % (deskHeight - this->geometry().height());
			sec[currentTick] = new WarningWindow(this);
			sec[currentTick]->move(nextWidth, nextHeight);
			sec[currentTick]->show();
			sec[currentTick]->setFocus();

			if (currentTick == 16) {
				for (int i = 0; i <= currentTick; i++)
					sec[i]->close();
				bsod->hide();
				state = 3; //black state
				show();
				black = new BlackWindow();
				black->show();
				black->setFocus();
				hide();
				timer->setInterval(5000);
			}
		}

	} else if (state == 3) {
		timer->stop();
		bsod->close();
		black->close();

		// Do it again if you want!
		state = 1;
		currentClick = 0;
		show();
		setWindowTitle("Created by Diamond00744");
	}

	currentTick++;
}