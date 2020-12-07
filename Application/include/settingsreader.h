#ifndef SETTINGSREADER_H
#define SETTINGSREADER_H

#include <QPair>
#include <QString>

class SettingsReader
{
    QString m_location;

public:
    SettingsReader();
    void recordSettingsInfo(int sizeMode, bool isDarkTheme);
    QPair<int, bool> getSettingsInfo() const;
};

#endif // SETTINGSREADER_H
