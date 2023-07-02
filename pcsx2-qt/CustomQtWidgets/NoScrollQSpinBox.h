#pragma once
#include <QtWidgets/QSpinBox>

class NoScrollQSpinBox : public QSpinBox
{
    Q_OBJECT
    void wheelEvent(QWheelEvent* event) override
    {
        if (hasFocus())
        {
            QSpinBox::wheelEvent(event);
        }
        else
        ((QEvent*)event)->ignore();
    };
public:
    explicit NoScrollQSpinBox(QWidget *parent = nullptr) : QSpinBox(parent)
    {
        setFocusPolicy(Qt::StrongFocus);
    }
};
