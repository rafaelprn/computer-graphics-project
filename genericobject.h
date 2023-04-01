#ifndef GENERICOBJECT_H
#define GENERICOBJECT_H

#include <QLine>
#include <QList>
#include <QPainter>

class GenericObject
{
public:
    GenericObject();
    virtual void draw(QPainter *painter);
};

#endif // GENERICOBJECT_H
