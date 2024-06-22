#include "MapWidget.h"
#include <QGraphicsScene>
#include <QGraphicsDropShadowEffect>
#include <QDebug>
#include <QGraphicsItem>
#include"areaa.h"
#include"areab.h"
#include"areac.h"
#include"aread.h"
AreaA *a = nullptr;
AreaB *b = nullptr;
AreaC *c = nullptr;
AreaD *d = nullptr;
MapGraphicsItem::MapGraphicsItem(const QPixmap &pixmap, QGraphicsItem *parent)
    : QGraphicsPixmapItem(pixmap, parent) {
    setAcceptHoverEvents(true);
    setTransformOriginPoint(boundingRect().center());
    //setAcceptTouchEvents(true);
}

void MapGraphicsItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
    m_isHovered = true;
    setScale(1.1);
    QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect;
    shadowEffect->setBlurRadius(25);
    shadowEffect->setOffset(0, 0);
    shadowEffect->setColor(Qt::blue);
    setGraphicsEffect(shadowEffect);
    QGraphicsPixmapItem::hoverEnterEvent(event);
}
void MapGraphicsItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) {
    m_isHovered = false;
    setScale(1.0);
    setGraphicsEffect(nullptr);
    QGraphicsPixmapItem::hoverLeaveEvent(event);
}
void MapGraphicsItem::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    QPointF scenePos = mapToScene(event->pos());
    if (scenePos.x()  >= 260 && scenePos.x()  <= 540 && scenePos.y()>= 5 && scenePos.y()<= 130) {
        a->show();
    } else if (scenePos.x()  >= 260 && scenePos.x()  <= 540 &&scenePos.y()>= 130 &&scenePos.y() <= 240) {
        b->show();
    } else if (scenePos.x()  >= 260 && scenePos.x() <= 540 && scenePos.y() >= 240 && scenePos.y() <= 330) {
        c->show();
    } else if (scenePos.x()  >= 270 && scenePos.x()  <= 540 && scenePos.y() >= 330 && scenePos.y()<= 480) {
        d->show();
    }
    QGraphicsPixmapItem::mousePressEvent(event);
}
MapWidget::MapWidget(QWidget *parent)
    : QGraphicsView(parent), scene(new QGraphicsScene(this)) {
    setWindowTitle("校园垃圾桶向导");
    setWindowIcon(QIcon(":/function2title/title3.png"));
    setScene(scene);
    setMouseTracking(true);
    QPixmap mapPixmap(":/全图with图例.png");
    QGraphicsPixmapItem *mapItem = new QGraphicsPixmapItem(mapPixmap);
    scene->addItem(mapItem);

    QPixmap regionPixmap;
    QFont font;
    font.setPointSize(17);
    font.setBold(true);
    regionPixmap = mapPixmap.copy(260, 0, 280, 120);
    MapGraphicsItem *regionItem1 = new MapGraphicsItem(regionPixmap);
    regionItem1->setPos(260, 0);
    scene->addItem(regionItem1);
    QGraphicsTextItem *textItem1 = new QGraphicsTextItem("Region 1", regionItem1);
    textItem1->setDefaultTextColor(Qt::red); // 设置文本颜色
    textItem1->setFont(font);
    textItem1->setPos((regionPixmap.width() - textItem1->boundingRect().width()) / 2,
                      (regionPixmap.height() - textItem1->boundingRect().height()) / 2);
    regionPixmap = mapPixmap.copy(260, 130, 280, 100);
    MapGraphicsItem *regionItem2 = new MapGraphicsItem(regionPixmap);
    regionItem2->setPos(260, 130);
    scene->addItem(regionItem2);
    QGraphicsTextItem *textItem2 = new QGraphicsTextItem("Region 2", regionItem2);
    textItem2->setDefaultTextColor(Qt::red);
    textItem2->setFont(font);
    textItem2->setPos((regionPixmap.width() - textItem2->boundingRect().width()) / 2,
                      (regionPixmap.height() - textItem2->boundingRect().height()) / 2);
    regionPixmap = mapPixmap.copy(260, 240, 280, 90);
    MapGraphicsItem *regionItem3 = new MapGraphicsItem(regionPixmap);
    regionItem3->setPos(260, 240);
    scene->addItem(regionItem3);
    QGraphicsTextItem *textItem3 = new QGraphicsTextItem("Region 3", regionItem3);
    textItem3->setDefaultTextColor(Qt::red);
    textItem3->setFont(font);
    textItem3->setPos((regionPixmap.width() - textItem3->boundingRect().width()) / 2,
                      (regionPixmap.height() - textItem3->boundingRect().height()) / 2);

    regionPixmap = mapPixmap.copy(270, 340, 270, 140);
    MapGraphicsItem *regionItem4 = new MapGraphicsItem(regionPixmap);
    regionItem4->setPos(270, 340);
    scene->addItem(regionItem4);
    QGraphicsTextItem *textItem4 = new QGraphicsTextItem("Region 4", regionItem4);
    textItem4->setDefaultTextColor(Qt::red);
    textItem4->setFont(font);
    textItem4->setPos((regionPixmap.width() - textItem4->boundingRect().width()) / 2,
                      (regionPixmap.height() - textItem4->boundingRect().height()) / 2);
    //textItem4->setVisible(false);

    a = new AreaA;
    b = new AreaB;
    c = new AreaC;
    d = new AreaD;

    // 连接信号和槽
    connect(a, SIGNAL(back()), this, SLOT(comeBackToPrev()));
    connect(b, SIGNAL(back()), this, SLOT(comeBackToPrev2()));
    connect(c, SIGNAL(back()), this, SLOT(comeBackToPrev3()));
    connect(d, SIGNAL(back()), this, SLOT(comeBackToPrev4()));
    setRenderHint(QPainter::Antialiasing);
}
void MapWidget::comeBackToPrev(){
    a->hide();
}
void MapWidget::comeBackToPrev2(){
    b->hide();
}
void MapWidget::comeBackToPrev3(){
    c->hide();
}
void MapWidget::comeBackToPrev4(){
    d->hide();
}
