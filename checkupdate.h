// SPDX-FileCopyrightText: 2017, 2019, 2026 Ivan Romanov <drizt72@zoho.eu>
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include <QObject>

class CheckUpdate : public QObject
{
    Q_OBJECT

public:
    CheckUpdate(QObject *parent = nullptr);

private slots:
    void start();

signals:
    void finished(const QString &version, const QString &url);
};
