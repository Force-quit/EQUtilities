#include "EQTests.hpp"

#include <QVBoxLayout>
#include "EQIntLineEdit.hpp"

EQTests::EQTests()
{
	auto centralWidget = new QWidget;
	setCentralWidget(centralWidget);
	
	auto layout = new QVBoxLayout;
	centralWidget->setLayout(layout);

	auto intLineEdit1 = new EQIntLineEdit(0, 100, 50);
	layout->addWidget(intLineEdit1);

	auto intLineEdit2 = new EQIntLineEdit(0, 100, 50);
	layout->addWidget(intLineEdit2);

	mWorkerThread->moveObjectToThread(mWorker);
	mWorkerThread->start();

	connect(intLineEdit1, &EQIntLineEdit::valueChanged, [this](int iValue) 
	{ 
		qDebug() << "Deleting mThread";
		delete mWorkerThread;
	});
}