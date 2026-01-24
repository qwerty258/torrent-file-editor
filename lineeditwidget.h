// SPDX-FileCopyrightText: 2014, 2017, 2020, 2023, 2026 Ivan Romanov <drizt72@zoho.eu>
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include <QLineEdit>
#include <QToolButton>
#include <QList>

class QFrame;
class QHBoxLayout;

class LineEditWidget : public QLineEdit
{
    Q_OBJECT
    Q_PROPERTY(int optimalLength READ optimalLenth WRITE setOptimalLength)
    Q_PROPERTY(QString rxValidator READ rxValidator WRITE setRxValidator)
public:
    explicit LineEditWidget(QWidget *parent = 0);
    ~LineEditWidget();

    // reimplemented
    QSize sizeHint() const override;
    void showEvent(QShowEvent *e) override;
    bool eventFilter(QObject *o, QEvent *e) override;

    // Properties
    int optimalLenth() const { return _optimalLength; }
    void setOptimalLength(int optimalLength) { _optimalLength = optimalLength; }

    QString rxValidator() const { return _rxValidator; }
    void setRxValidator(const QString &str);

protected:
    // reimplemented
    void changeEvent(QEvent *event) override;

    void addWidget(QWidget *w);
    void setPopup(QWidget* w);
    QFrame *popup() const { return _popup; }
    virtual void retranslateUi() {}

protected slots:
    virtual void showPopup();
    virtual void hidePopup();

private:

    QHBoxLayout *_layout;
    QList<QWidget*> _toolbuttons;
    QFrame *_popup;

    // Properties
    int _optimalLength;
    QString _rxValidator;
};
