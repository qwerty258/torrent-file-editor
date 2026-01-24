// SPDX-FileCopyrightText: 2014, 2016-2017, 2026 Ivan Romanov <drizt72@zoho.eu>
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include <QApplication>
#include <QDateTime>

class MainWindow;

class Application : public QApplication
{
    Q_OBJECT

public:
    Application(int &argc, char **argv);
    bool event(QEvent *event);
    void setMainWindow(MainWindow *mainWindow);
    static QDateTime buildDateTime();

private:
    MainWindow *_mainWindow;
};
