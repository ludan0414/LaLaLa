#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneHoverEvent>
#include "areaa.h"
#include "areab.h"
#include "areac.h"
#include "aread.h"
class AreaA;
class AreaB;
class AreaC;
class AreaD;
extern AreaA *a;
extern AreaB *b;
extern AreaC *c;
extern AreaD *d;
class MapGraphicsItem : public QObject, public QGraphicsPixmapItem {

    Q_OBJECT

public:
    MapGraphicsItem(const QPixmap &pixmap, QGraphicsItem *parent = nullptr);

signals:
    void regionHovered(bool isHovered);

protected:
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private:
    bool m_isHovered;
};
class MapWidget : public QGraphicsView {

    Q_OBJECT

public:
    MapWidget(QWidget *parent = nullptr);
private slots:
    void comeBackToPrev();
    void comeBackToPrev2();
    void comeBackToPrev3();
    void comeBackToPrev4();
private:
    QGraphicsScene *scene;
};

#endif // MAPWIDGET_H
