// SPDX-FileCopyrightText: 2015, 2017-2018, 2026 Ivan Romanov <drizt72@zoho.eu>
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

class CocoaInitializer
{
public:
    CocoaInitializer();
    ~CocoaInitializer();

private:
    class Private;
    Private *d;
};
