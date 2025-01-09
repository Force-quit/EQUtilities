#include "EQTests.hpp"

#include <QVBoxLayout>
#include "EQIntLineEdit.hpp"

EQTests::EQTests()
{
	auto centralWidget = new QWidget;
	setCentralWidget(centralWidget);
	
	auto layout = new QVBoxLayout;
	centralWidget->setLayout(layout);

	auto intLineEdit = new EQIntLineEdit(0, 100, 50);
	layout->addWidget(intLineEdit);
}