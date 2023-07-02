#pragma once
#include <QtWidgets/QSlider>

class NoScrollQSlider : public QSlider
{
    Q_OBJECT
    void wheelEvent(QWheelEvent* event) override
    {
        if (hasFocus())
        {
            QSlider::wheelEvent(event);
        }
        else
        ((QEvent*)event)->ignore();
    };
    void focusInEvent(QFocusEvent* event) override
    {
        QSlider::focusInEvent(event);
        setPalette(HighlightPalette);
    };
    void focusOutEvent(QFocusEvent* event) override
    {
        QSlider::focusOutEvent(event);
        setPalette(QPalette());
    };
    QPalette HighlightPalette;
public:
    explicit NoScrollQSlider(QWidget *parent = nullptr) : QSlider(parent)
    {
        setFocusPolicy(Qt::StrongFocus);
        HighlightPalette.setColor(QPalette::Window, palette().highlight().color());
    }
};
