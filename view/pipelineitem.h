#ifndef PIPELINEITEM_H
#define PIPELINEITEM_H

#include <QObject>
#include <QWidget>
#include <QGraphicsItem>
#include <QPainter>
class PipelineItem : public QGraphicsItem
{
public:
    PipelineItem(QGraphicsItem *parent = nullptr);
    PipelineItem(const QRectF &pipRect, const QBrush &brush, const QString &innerString, qreal penWidth=1);
    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
private:
    qreal _penWidth = 1;
    QRectF _pipRect;
    QBrush _brush;
    QString _innerString;
};

#endif // PIPELINEITEM_H
