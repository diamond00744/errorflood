#include "warningwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	WarningWindow win;
	win.show();

	return a.exec();
}
