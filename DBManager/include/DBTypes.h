#ifndef DBTYPES_H
#define DBTYPES_H
#include <QVariantList>


namespace db {
enum class DBResult {
    OK,
    ERROR
};

enum class DBTables {
    Notes = 1,
    Tasks
};

enum class DBState {
    OK,
    ERROR_NO_DRIVER,
    ERROR_WORKSPACE,
    ERROR_TABLES,
    ERROR_OPENING
};

using DBEntry = QVariantList;
using DBIndex = int;
}

#endif // DBTYPES_H
