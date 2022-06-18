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
    painter->drawText(boundingRect(),_aligment, _innerString);
}

const QRectF &PipelineItem::pipRect() const
{
    return _pipRect;
}

void PipelineItem::setPipRect(const QRectF &newPipRect)
{
    _pipRect = newPipRect;
}



PipelineItem::PipelineItem(const QRectF &pipRect, const QBrush &brush, const QString &innerString, int aligment, qreal penWidth) :
    _pipRect(pipRect),
    _brush(brush),
    _innerString(innerString)
{
    _penWidth = penWidth;
    _aligment = aligment;
}
