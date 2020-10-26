#pragma once
#include <memory>

namespace db {
    class ConnectionManager
    {
    public:
        ConnectionManager(const ConnectionManager&) = delete;
        ConnectionManager& operator=(const ConnectionManager&) = delete;
        ~ConnectionManager();
        bool isValid() const;
        static ConnectionManager& instance();
    private:
        ConnectionManager();;
        struct ConnectionManagerPrivate;
        std::unique_ptr<ConnectionManagerPrivate> m_deepPtr;
    };
}
