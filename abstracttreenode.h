// SPDX-FileCopyrightText: 2017, 2023, 2026 Ivan Romanov <drizt72@zoho.eu>
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include <QIODevice>
#include <QList>
#include <QStringList>
#include <QTextStream>

template<typename T>
class AbstractTreeNode
{
public:
    explicit AbstractTreeNode(T *parent = nullptr)
        : _parent(nullptr)
        , _children(QList<T*>())
    {
        setParent(parent);
    }

    virtual ~AbstractTreeNode()
    {
        qDeleteAll(_children);
        if (_parent) {
            _parent->_children.removeOne(reinterpret_cast<T*>(this));
        }
    }

    inline void setRow(int row)
    {
        Q_ASSERT(_parent);
        if (!_parent) {
            return;
        }

        _parent->_children.move(this->row(), row);
    }

    inline int row() const
    {
        return _parent ? _parent->_children.indexOf(reinterpret_cast<T*>(const_cast<AbstractTreeNode<T>*>(this))) : 0;
    }

    inline void setParent(T *newParent)
    {
        if (_parent) {
            _parent->_children.removeOne(reinterpret_cast<T*>(this));
        }

        if (newParent) {
            newParent->_children.append(reinterpret_cast<T*>(this));
        }

        _parent = newParent;
    }

    inline T *parent() const
    {
        return _parent;
    }

    inline void insertChild(int row, T *child)
    {
        Q_ASSERT(child);
        Q_ASSERT(!child->_parent);

        if (child->_parent) {
            child->_parent->removeChild(child);
        }

        child->_parent = reinterpret_cast<T*>(this);
        _children.insert(row, child);
    }

    inline void appendChild(T *child)
    {
        Q_ASSERT(child);
        Q_ASSERT(!child->_parent);

        if (child->_parent) {
            child->_parent->removeChild(child);
        }

        child->_parent = reinterpret_cast<T*>(this);
        _children.append(child);
    }

    inline void removeChild(T *child)
    {
        Q_ASSERT(child);
        Q_ASSERT(_children.contains(child));

        _children.removeOne(child);
    }

    inline T *child(int row) const
    {
        Q_ASSERT(row < childCount());
        if (row < childCount()) {
            return _children.at(row);
        }
        else {
            return nullptr;
        }
    }

    inline int childCount() const
    {
        return _children.size();
    }

    inline QList<T*> children() const
    {
        return _children;
    }

    inline T *sibling(int row) const
    {
        Q_ASSERT(_parent);
        Q_ASSERT(row < _parent->childCount()); // -V595 PVS-Studio
        return _parent ? _parent->child(row) : nullptr;
    }

    virtual T *clone() const = 0;

    QString dump(int indent = 0) const
    {
        QString fill(indent, QLatin1Char(' '));
        QString res;
        QTextStream ts(&res, QIODevice::WriteOnly);
        ts << fill << "{\n";
        ts << fill << ' ' << toString() << '\n';
        ts << fill << " this " << this << '\n';
        ts << fill << " parent " << _parent << '\n';
        ts << fill << " children ";
        for (int i = 0; i < _children.size(); ++i) {
            ts << _children.at(i);
            if (i < _children.size() - 1) {
                ts << ", ";
            }
        }
        ts << "\n";

        for (T *item: _children) {
            ts << item->dump(indent + 1);
            ts << "\n";
        }
        ts << fill << "}";

        return res;
    }

    virtual QString toString() const = 0;

private:
    T *_parent;
    QList<T*> _children;
};
