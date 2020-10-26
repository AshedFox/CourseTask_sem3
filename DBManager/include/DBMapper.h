#pragma once
#include "DBTypes.h"

namespace db
{

static const QMap<DBTables, QString> tableMapper {
    {DBTables::Notes, "Notes"}
};

static const QMap<QString, QString> tablesMapping {
    {"Notes", "Header"}
};
}
