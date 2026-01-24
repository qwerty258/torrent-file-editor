// SPDX-FileCopyrightText: 2023-2024, 2026 Ivan Romanov <drizt72@zoho.eu>
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

// Order is matter! First QString leads to strange building error on Fedora 31 MinGW
#include <QVariant>
#include <QString>

class JsonConverter
{
public:
    static QVariant parse(const QString &str, int *byte = nullptr, QString *error = nullptr);
    static QString stringify(const QVariant &variant);
};

