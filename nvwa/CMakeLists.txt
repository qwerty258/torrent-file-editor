# SPDX-FileCopyrightText: 2017, 2026 Ivan Romanov <drizt72@zoho.eu>
# SPDX-License-Identifier: GPL-3.0-or-later

set(SOURCES
    debug_new.cpp
)

set(PLAIN_HEADERS
    c++11.h
    debug_new.h
    fast_mutex.h
    _nvwa.h
    static_assert.h
)

add_library(nvwa OBJECT ${SOURCES} ${PLAIN_HEADERS})
