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
    PipelineItem(const QRectF &pipRect, const QBrush &brush, const QString &innerString,int _aligment = Qt::AlignCenter,
                 qreal penWidth=1);
    PipelineItem(qreal penWidth, const QRectF &pipRect, const QBrush &brush, const QString &innerString, int aligment);
    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
    const QRectF &pipRect() const;
    void setPipRect(const QRectF &newPipRect);

private:
    qreal _penWidth = 1;
    QRectF _pipRect;
    QBrush _brush;
    QString _innerString;
    int _aligment;
};

#endif // PIPELINEITEM_H
