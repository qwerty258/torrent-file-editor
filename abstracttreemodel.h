// SPDX-FileCopyrightText: 2015-2017, 2026 Ivan Romanov <drizt72@zoho.eu>
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include <QAbstractItemModel>

#include "abstracttreenode.h"

template<typename T>
class AbstractTreeModel : public QAbstractItemModel
{
public:
    explicit AbstractTreeModel(T *root, QObject *parent = nullptr)
        : QAbstractItemModel(parent)
        , _root(root)
    {
    }

    ~AbstractTreeModel() override
    {
        delete _root;
    }

    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override
    {
        if (!hasIndex(row, column, parent)) {
            return QModelIndex();
        }

        T *parentItem;

        parentItem = indexToNode(parent);

        T *childItem = nullptr;
        if (row >= 0 && row < parentItem->childCount()) {
            childItem = parentItem->children().at(row);
        }

        if (childItem) {
            return createIndex(row, column, childItem);
        }
        else {
            return QModelIndex();
        }

    }

    QModelIndex parent(const QModelIndex &index) const override
    {
        if (!index.isValid()) {
            return QModelIndex();
        }

        T *childItem = indexToNode(index);
        T *parentItem = childItem->parent();

        if (parentItem == _root) {
            return QModelIndex();
        }

        int row = 0;
        if (parentItem->parent()) {
            row = parentItem->row();
        }

        return createIndex(row, 0, parentItem);
    }

    int rowCount(const QModelIndex &parent = QModelIndex()) const override
    {
        if (parent.column() > 0) {
            return 0;
        }

        T *parentItem;
        if (!parent.isValid()) {
            parentItem = _root;
        }
        else {
            parentItem = indexToNode(parent);
        }

        return parentItem->childCount();
    }

protected:
    inline T *root() const
    {
        return _root;
    }

    inline T *indexToNode(const QModelIndex &index) const
    {
        return index.isValid() ? static_cast<T*>(index.internalPointer()) : _root;
    }

    inline QModelIndex nodeToIndex(T *node) const
    {
        Q_ASSERT(node);
        return (node == _root || !node) ? QModelIndex() : createIndex(node->row(), 0, node);
    }

private:
    T *_root;
};
