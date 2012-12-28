#ifndef CANVASWIDGET_H
#define	CANVASWIDGET_H

#include "utils.h"

#include <QWidget>;

class QString;
class QPaintEvent;

class CanvasWidget : public QWidget {
public:
    CanvasWidget();
    virtual ~CanvasWidget();
    
    void setText(QString text);

protected:
    virtual void paintEvent(QPaintEvent *event);

private:
    QString text;
};

#endif
