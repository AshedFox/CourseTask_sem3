#include "settingsreader.h"
#include <QStandardPaths>
#include <QDir>
#include <QFile>
#include <QTextStream>

SettingsReader::SettingsReader()
    : m_location {QStandardPaths::writableLocation(QStandardPaths::AppDataLocation)}
{
    QDir dir{m_location};
    if (!dir.exists()){
        dir.mkpath(m_location);
    }
    QFile settingsFile(m_location+"/settings.txt");
    if (!settingsFile.exists()) {
        if (settingsFile.open(QIODevice::WriteOnly)){
            QTextStream stream {&settingsFile};
            stream << 1 << "\n" << 1 << "\n";
            stream.flush();
            settingsFile.flush();
            settingsFile.close();
        }
    }
}

void SettingsReader::recordSettingsInfo(int sizeMode, bool isDarkTheme)
{
    QDir dir{m_location};
    if (!dir.exists()){
        dir.mkpath(m_location);
    }
    QFile settingsFile(m_location+"/settings.txt");

    if (settingsFile.open(QIODevice::WriteOnly)){
        QTextStream stream {&settingsFile};
        stream << sizeMode << "\n" << isDarkTheme << "\n";
        stream.flush();
        settingsFile.flush();
        settingsFile.close();
    }

}

QPair<int, bool> SettingsReader::getSettingsInfo() const
{
    QDir dir{m_location};

    int sizeMode;
    bool isDarkTheme;

    QFile settingsFile(m_location+"/settings.txt");
    if (settingsFile.open(QIODevice::ReadOnly)){
        QTextStream stream{&settingsFile};
        QString info = stream.readLine();
        sizeMode = info.toInt();

        info = stream.readLine();
        isDarkTheme = info.toInt();

        stream.flush();
        settingsFile.close();
    }
    return {sizeMode, isDarkTheme};
}
