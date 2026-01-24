// SPDX-FileCopyrightText: 2017-2019, 2023-2024, 2026 Ivan Romanov <drizt72@zoho.eu>
// SPDX-License-Identifier: GPL-3.0-or-later

#include "checkupdate.h"

#include "jsonconverter.h"

#include <QVariantMap>

#include <tchar.h>
#include <windows.h>
#include <wininet.h>

#define CHUNK_SIZE 1024 * 1024 /* 1MiB */
#define CAST_URL _T("https://torrent-file-editor.github.io/appcast/appcast.json")

CheckUpdate::CheckUpdate(QObject *parent)
    : QObject(parent)
{
}

void CheckUpdate::start()
{
    HINTERNET hInternetSession;
    HINTERNET hURL;
    char cBuffer[CHUNK_SIZE];
    DWORD dwBytesRead;

    // Make internet connection.
    hInternetSession = InternetOpen(_T("Microsoft Internet Explorer"), // agent
                                    INTERNET_OPEN_TYPE_PRECONFIG, // access
                                    NULL,
                                    NULL,
                                    0); // defaults

    // Make connection to desired page.
    hURL = InternetOpenUrl(hInternetSession, // session handle
                           CAST_URL, // URL to access
                           NULL,
                           -1L,
                           0,
                           0); // defaults

    // Read page into memory buffer.
    InternetReadFile(hURL, // handle to URL
                     (LPSTR)cBuffer, // pointer to buffer
                     (DWORD)sizeof(cBuffer), // size of buffer
                     &dwBytesRead); // pointer to var to hold return value

    InternetCloseHandle(hURL);

    if (dwBytesRead == 0) {
        InternetCloseHandle(hInternetSession);
        emit finished(QString(), QString());
        return;
    }

    if (dwBytesRead < sizeof(cBuffer)) {
        cBuffer[dwBytesRead] = '\0';
    } else {
        cBuffer[sizeof(cBuffer) - 1] = '\0';
    }

    QByteArray ba(cBuffer, dwBytesRead);

    QVariantMap variant = JsonConverter::parse(QString::fromUtf8(ba)).toMap();

    if (variant.empty()) {
        emit finished(QString(), QString());
        return;
    }

    QString version = variant.value(QLatin1String("version")).toString();
#ifdef Q_OS_WIN64
    QString url = variant.value(QLatin1String("url-win-x64")).toString();
#elif defined Q_OS_WIN32
    QString url = variant.value(QLatin1String("url-win-x32")).toString();
#endif

    emit finished(version, url);
}
