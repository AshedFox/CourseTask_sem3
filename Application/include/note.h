#pragma once

#include <QString>
#include <QAbstractListModel>
#include <QList>


class Note
{
public: 

    Note() = default;
    Note(const int id, const QString& header, const QString& info);
    Note(const QString& header);

    int id() const;

    QString header() const;

    QString info() const;

    QVariantList getfullRowData() const;


private:

    int m_id;
    QString m_header;
    QString m_info;
};

