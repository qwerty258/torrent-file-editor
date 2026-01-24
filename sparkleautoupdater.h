// SPDX-FileCopyrightText: 2008  Remko Troncon
// SPDX-FileCopyrightText: 2015, 2017, 2026 Ivan Romanov <drizt72@zoho.eu>
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include <QString>

class SparkleAutoUpdater
{
public:
    SparkleAutoUpdater();
    ~SparkleAutoUpdater();

    void checkForUpdates();

private:
    class Private;
    Private *d;
};
