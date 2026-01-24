// SPDX-FileCopyrightText: 2016-2017, 2023, 2026 Ivan Romanov <drizt72@zoho.eu>
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include <QTreeView>

class TreeView : public QTreeView
{
    Q_OBJECT

public:
    explicit TreeView(QWidget *parent = 0);

protected:
    void mouseMoveEvent(QMouseEvent *event) override;
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    void initViewItemOption(QStyleOptionViewItem *option) const override;
#else
    QStyleOptionViewItem viewOptions() const override;
#endif
};
