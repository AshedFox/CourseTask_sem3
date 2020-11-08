#pragma once
#include "DBTypes.h"

namespace db
{

static const QMap<DBTables, QString> tableMapper {
    {DBTables::Notes, "Notes"},
    {DBTables::Tasks, "Tasks"}
};

static const QMap<QString, QString> tablesMapping {
    {"Notes", "id, Header, Info"},
    {"Tasks", "id, Header, Date, Time, Info"}
};

static const QMap<QString, QString> tablesMappingWithoutID {
    {"Notes", "Header, Info"},
    {"Tasks", "Header, Date, Time, Info"}
};
}
