#pragma once

#include <QString>
#include <QAbstractListModel>
#include <QList>


class Note
{
public: 

    Note() = default;
    Note(const int id, const QString& header);
    Note(const QString& header);

    int getId() const;

    QString header() const;

    QVariantList getfullRowData() const;

private:

    int m_id;
    QString m_header;
};

