#pragma once

#include <QThread>
#include <QObject>

class EQThread : public QThread
{
public:
    ~EQThread() override
    {
        quit();
        wait();
    }

    void moveObjectToThread(QObject* object) 
    {
        object->moveToThread(this);
        connect(this, &QThread::finished, object, &QObject::deleteLater);
    }
};