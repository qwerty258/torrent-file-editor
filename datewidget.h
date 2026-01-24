// SPDX-FileCopyrightText: 2014, 2017, 2019-2020, 2026 Ivan Romanov <drizt72@zoho.eu>
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include "lineeditwidget.h"

#include <QDateTime>

class QPushButton;
class QCalendarWidget;

class DateWidget : public LineEditWidget
{
    Q_OBJECT

    Q_PROPERTY(QDate date
               READ date
               WRITE setDate)

    Q_PROPERTY(QTime time
               READ time
               WRITE setTime)

    Q_PROPERTY(QDateTime dateTime
               READ dateTime
               WRITE setDateTime)

public:
    explicit DateWidget(QWidget *parent = 0);

    // get/set date
    void setDate(const QDate &date);
    QDate date() const;

    // get/set time
    void setTime(const QTime &time);
    QTime time() const;

    // get/set dateTime
    void setDateTime(const QDateTime &dateTime);
    QDateTime dateTime() const;

protected slots:
    void closeCalendar(const QDate &text);
    void calendarSetDate();
    void internalClear();

protected:
    void retranslateUi() override;

private:

    // Inner widgets
    QPushButton *_tbCalendar;
    QPushButton *_tbClean;
    QCalendarWidget *_calendar;
};
