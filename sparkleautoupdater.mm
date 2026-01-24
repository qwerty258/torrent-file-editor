// SPDX-FileCopyrightText: 2008  Remko Troncon
// SPDX-FileCopyrightText: 2015, 2026 Ivan Romanov <drizt72@zoho.eu>
// SPDX-License-Identifier: GPL-3.0-or-later

#include "sparkleautoupdater.h"

// MacOSX10.7 SDK has missed NS_ENUM

#ifndef NS_ENUM
# if (__cplusplus && __cplusplus >= 201103L && (__has_extension(cxx_strong_enums) || __has_feature(objc_fixed_enum))) || (!__cplusplus && __has_feature(objc_fixed_enum))
#  define NS_ENUM(_type, _name) enum _name : _type _name; enum _name : _type
#  if (__cplusplus)
#   define NS_OPTIONS(_type, _name) _type _name; enum : _type
#  else
#   define NS_OPTIONS(_type, _name) enum _name : _type _name; enum _name : _type
#  endif
# else
#  define NS_ENUM(_type, _name) _type _name; enum
#  define NS_OPTIONS(_type, _name) _type _name; enum
# endif
#endif

#include <Cocoa/Cocoa.h>
#include <Sparkle/Sparkle.h>

class SparkleAutoUpdater::Private
{
public:
    SUUpdater* updater;
};

SparkleAutoUpdater::SparkleAutoUpdater()
{
    d = new Private;

    d->updater = [SUUpdater sharedUpdater];
    [d->updater retain];
}

SparkleAutoUpdater::~SparkleAutoUpdater()
{
    [d->updater release];
    delete d;
}

void SparkleAutoUpdater::checkForUpdates()
{
    [d->updater checkForUpdatesInBackground];
}
