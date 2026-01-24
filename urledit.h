// SPDX-FileCopyrightText: 2014, 2017-2020, 2026 Ivan Romanov <drizt72@zoho.eu>
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include "lineeditwidget.h"

class QPushButton;

class UrlEdit : public LineEditWidget
{
    Q_OBJECT

public:
    explicit UrlEdit(QWidget *parent = 0);

protected slots:
    void openUrl();
    void copyAll();

protected:
    void retranslateUi() override;

    // Inner widgets
    QPushButton *_pbOpenUrl;
    QPushButton *_pbCopyUrl;
};
