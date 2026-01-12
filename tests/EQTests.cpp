#include "EQTests.hpp"

#include <QVBoxLayout>
#include "EQShortcutPicker.hpp"
#include <QSystemTrayIcon>

EQTests::EQTests()
{
	QSystemTrayIcon trayIcon;
	trayIcon.setIcon(QIcon("C:/Users/Admin/Desktop/GithubRepos/MinecraftFishingBot/resources/icon.png"));
	trayIcon.show();
	trayIcon.showMessage("EQTests", "System Tray Icon initialized.");
}