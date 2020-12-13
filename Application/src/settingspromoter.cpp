    #include "settingspromoter.h"
#include <iostream>

SettingsPromoter::SettingsPromoter()
    : settingsReader()
{
    auto data = settingsReader.getSettingsInfo();
    setSizeMode(data.first);
    setIsDarkTheme(data.second);
}

int SettingsPromoter::sizeMode() const
{
    auto data = settingsReader.getSettingsInfo();
    return data.first;
}

int SettingsPromoter::isDarkTheme() const
{
    auto data = settingsReader.getSettingsInfo();
    return data.second;
}

void SettingsPromoter::setSizeMode(int sizeMode)
{
    if (m_sizeMode == sizeMode)
        return;

    m_sizeMode = sizeMode;
    settingsReader.recordSettingsInfo(sizeMode, m_isDarkTheme);

    emit sizeModeChanged(m_sizeMode);
}

void SettingsPromoter::setIsDarkTheme(int isDarkTheme)
{
    if (m_isDarkTheme == isDarkTheme)
        return;

    m_isDarkTheme = isDarkTheme;

    settingsReader.recordSettingsInfo(m_sizeMode, isDarkTheme);
    emit isDarkThemeChanged(m_isDarkTheme);
}
