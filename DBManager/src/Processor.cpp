#include "Processor.h"
#include "Selector.h"
#include "DBMapper.h"
#include "Manipulator.h"
#include <mutex>

namespace db {
    struct Processor::ProcessorPrivate{
        Selector selector;
        Manipulator manipulator;
    #ifdef BUILD_TESTS
        std::once_flag initialized;
        void insertMockData();
    #endif
    };


#ifdef BUILD_TESTS
void Processor::ProcessorPrivate::insertMockData()
{
//    manipulator.insertRow("Notes", {{"Jhon", "Jhonson", "+375291236157", "25", "St. Louis"}});
//    manipulator.insertRow("Notes", {{"Ash", "Walker", "+375172229643", "17", "St. Louis"}});
//    manipulator.insertRow("Notes", {{"Markus", "Devil", "+81234567", "44", "New-York"}});
//    manipulator.insertRow("Notes", {{"Angel", "May", "+37529cry", "77", "Paris"}});
//    manipulator.insertRow("Notes", {{"Chester", "Miles", "80296621043", "65", "Moskow"}});
//    manipulator.insertRow("Notes", {{"Stuart", "Wright", "+380813526568", "19", "Machester"}});
//    manipulator.insertRow("Notes", {{"Leonard", "Tanner", "+380813526568", "33", "Kiev"}});
//    manipulator.insertRow("Notes", {{"Christopher", "Dillon", "+380565828659", "40", "Seatle"}});
//    manipulator.insertRow("Notes", {{"", "Ivanov", "+380501728834", "15", "Chelyabinsk"}});

//    manipulator.insertRow("Notes", {{"Jhon", "Jhonson", "+375291236157", "25", "St. Louis"}});
//    manipulator.insertRow("Notes", {{"Ash", "Walker", "+375172229643", "17", "St. Louis"}});
//    manipulator.insertRow("Notes", {{"Markus", "Devil", "+81234567", "44", "New-York"}});
//    manipulator.insertRow("Notes", {{"Angel", "May", "+37529cry", "77", "Paris"}});
//    manipulator.insertRow("Notes", {{"Chester", "Miles", "80296621043", "65", "Moskow"}});
//    manipulator.insertRow("Notes", {{"Stuart", "Wright", "+380813526568", "19", "Machester"}});
//    manipulator.insertRow("Notes", {{"Leonard", "Tanner", "+380813526568", "33", "Kiev"}});
//    manipulator.insertRow("Notes", {{"Christopher", "Dillon", "+380565828659", "40", "Seatle"}});
//    manipulator.insertRow("Notes", {{"", "Ivanov", "+380501728834", "15", "Chelyabinsk"}});

}
#endif

    Processor::Processor()
        : m_deepPtr {new ProcessorPrivate()}
    {

    }

    Processor::~Processor()
    {

    }

    QPair<DBResult, QVector<DBEntry>> Processor::requestTableData(DBTables table)
    {
#ifdef BUILD_TESTS
    auto inserter = [this] {
        m_deepPtr->insertMockData();
    };
    std::call_once(m_deepPtr->initialized, inserter);
#endif
        const auto& result = m_deepPtr->selector.SelectAll(tableMapper.value(table));
        return result;
    }

    void Processor::insertData(const QString &tableName, const QVariantList &rowData)
    {
        m_deepPtr->manipulator.insertRow(tableName,rowData);
    }
}

