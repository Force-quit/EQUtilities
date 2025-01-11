#pragma once

#include <QMainWindow>
#include "EQThread.hpp"
#include <QDebug>

class Worker : public QObject
{
	Q_OBJECT
public:
	Worker()
	{
		qDebug() << "Worker created";
	}

	~Worker()
	{
		qDebug() << "Worker destroyed";
	}
};

class EQTests : public QMainWindow
{
	Q_OBJECT
public:
	EQTests();
private:
	EQThread* mWorkerThread{ new EQThread };
	Worker* mWorker{ new Worker };
};