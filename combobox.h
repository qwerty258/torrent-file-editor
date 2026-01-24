// SPDX-FileCopyrightText: 2016-2020, 2026 Ivan Romanov <drizt72@zoho.eu>
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include <QComboBox>

class ComboBox : public QComboBox
{
    Q_OBJECT

public:
    ComboBox(QWidget *parent = nullptr);
    void hidePopup() override;

protected:
    void leaveEvent(QEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;

public slots:
    void close();
};
