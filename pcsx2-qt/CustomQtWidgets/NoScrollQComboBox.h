#pragma once
#include <QtWidgets/QComboBox>

class NoScrollQComboBox : public QComboBox
{
    Q_OBJECT
    void wheelEvent(QWheelEvent* event) override
    {
        if (hasFocus())
        {
            QComboBox::wheelEvent(event);
        }
        else
        ((QEvent*)event)->ignore();
    };
    void focusInEvent(QFocusEvent* event) override
    {
        QComboBox::focusInEvent(event);
        setPalette(HighlightPalette);
    };
    void focusOutEvent(QFocusEvent* event) override
    {
        QComboBox::focusOutEvent(event);
        setPalette(QPalette());
    };
    QPalette HighlightPalette;
public:
    explicit NoScrollQComboBox(QWidget *parent = nullptr) : QComboBox(parent)
    {
        setFocusPolicy(Qt::StrongFocus);
        HighlightPalette.setColor(QPalette::Window, palette().highlight().color());
    }
};
