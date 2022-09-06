#ifndef CONNECTION_H
#define CONNECTION_H

#include <pqxx/pqxx>
#include <string>

class ConnectionParams
{
private:
    std::string user;
    std::string host;
    std::string database;
    std::string password;
    int port;
public:
    ConnectionParams(std::string user, std::string host, std::string database, std::string password, int port);
    ConnectionParams(ConnectionParams *params);
    ConnectionParams() = default;
    ~ConnectionParams() = default;
    std::string getUser();
    std::string getHost();
    std::string getDBName();
    std::string getPassword();
    std::string getString();
    int getPort();
};

class Connection
{
private:
    ConnectionParams params;
    pqxx::connection *connect;
public:
    Connection(ConnectionParams *params);
    ~Connection() = default;
    pqxx::connection* getConnection();
    ConnectionParams getParams();
    void setConnection(pqxx::connection *connect);
};

#endif // CONNECTION_H
