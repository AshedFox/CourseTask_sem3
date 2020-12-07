#ifndef SETTINGSPROMOTER_H
#define SETTINGSPROMOTER_H

#include <QtCore/QObject>
#include "settingsreader.h"

class SettingsPromoter: public QObject
{
    Q_OBJECT

    Q_PROPERTY(int sizeMode READ sizeMode WRITE setSizeMode NOTIFY sizeModeChanged)
    Q_PROPERTY(int isDarkTheme READ isDarkTheme WRITE setIsDarkTheme NOTIFY isDarkThemeChanged)

    int m_sizeMode;

    int m_isDarkTheme;

    SettingsReader settingsReader;

public:
    SettingsPromoter();

    Q_INVOKABLE int sizeMode() const;

    Q_INVOKABLE int isDarkTheme() const;

public slots:
    void setSizeMode(int sizeMode);
    void setIsDarkTheme(int isDarkTheme);

signals:
    void sizeModeChanged(int sizeMode);
    void isDarkThemeChanged(int isDarkTheme);
};

#endif // SETTINGSPROMOTER_H
