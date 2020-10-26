#pragma once

#include <QString>
#include <QAbstractListModel>
#include <QList>


class Note
{
public: 

    Note() = default;
    Note(const QString& name);

    QString header() const;

private:

    QString m_header;
};

