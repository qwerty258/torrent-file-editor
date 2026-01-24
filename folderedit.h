// SPDX-FileCopyrightText: 2014, 2016-2017, 2020, 2026 Ivan Romanov <drizt72@zoho.eu>
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include "lineeditwidget.h"

class QPushButton;

class FolderEdit final : public LineEditWidget
{
    Q_OBJECT

public:
    explicit FolderEdit(QWidget *parent = 0);
    void setFolder(const QString &path);

public slots:
    void openFolder();

protected:
    void retranslateUi() override;

private:
    // Inner widgets
    QPushButton *_pbOpenFolder;
    QString _path;
};
