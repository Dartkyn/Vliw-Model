#include "pipelineitem.h"

PipelineItem::PipelineItem(QGraphicsItem *parent) : QGraphicsItem(parent)
{

}

QRectF PipelineItem::boundingRect() const
{
    return QRectF(_pipRect.x() + _penWidth, _pipRect.y() +_penWidth,
                  _pipRect.width() - _penWidth, _pipRect.height() - _penWidth);
}

void PipelineItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget)
{
    painter->drawRect(_pipRect);
    painter->fillRect(boundingRect(), _brush);
    painter->drawText(boundingRect(),0, _innerString);
}



PipelineItem::PipelineItem(const QRectF &pipRect, const QBrush &brush, const QString &innerString, qreal penWidth) :
    _pipRect(pipRect),
    _brush(brush),
    _innerString(innerString)
{
    _penWidth = penWidth;
}
