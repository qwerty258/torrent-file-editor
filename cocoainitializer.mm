// SPDX-FileCopyrightText: 2008  Remko Troncon
// SPDX-FileCopyrightText: 2015, 2017, 2026 Ivan Romanov <drizt72@zoho.eu>
// SPDX-License-Identifier: GPL-3.0-or-later

#include "cocoainitializer.h"

#include <AppKit/AppKit.h>
#include <Cocoa/Cocoa.h>

class CocoaInitializer::Private
{
public:
    NSAutoreleasePool *autoReleasePool_;
};

CocoaInitializer::CocoaInitializer()
{
    d = new CocoaInitializer::Private();
    NSApplicationLoad();
    d->autoReleasePool_ = [[NSAutoreleasePool alloc] init];
}

CocoaInitializer::~CocoaInitializer()
{
    [d->autoReleasePool_ release];
    delete d;
}
