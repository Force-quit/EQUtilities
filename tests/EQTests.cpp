#include "EQTests.hpp"

#include <QVBoxLayout>
#include "EQShortcutPicker.hpp"

EQTests::EQTests()
{
	auto centralWidget{ new EQShortcutPicker("Change Shortcut") };
	setCentralWidget(centralWidget);
}