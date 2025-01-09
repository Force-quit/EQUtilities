#include <QApplication>
#include "EQTests.hpp"

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	EQTests w;
	w.show();
	return QApplication::exec();
}