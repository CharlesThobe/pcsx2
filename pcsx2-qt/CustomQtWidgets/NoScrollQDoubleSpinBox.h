#pragma once
#include <QtWidgets/QDoubleSpinBox>

class NoScrollQDoubleSpinBox : public QDoubleSpinBox
{
    Q_OBJECT
    void wheelEvent(QWheelEvent* event) override
    {
        if (hasFocus())
        {
            QDoubleSpinBox::wheelEvent(event);
        }
        else
        ((QEvent*)event)->ignore();
    };
public:
    explicit NoScrollQDoubleSpinBox(QWidget *parent = nullptr) : QDoubleSpinBox(parent)
    {
        setFocusPolicy(Qt::StrongFocus);
    }
};
