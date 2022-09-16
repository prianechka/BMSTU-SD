#include "connection.h"

ConnectionParams::ConnectionParams(std::string user, std::string host, std::string database, std::string password, int port)
{
    this->user = user;
    this->host = host;
    this->database = database;
    this->password = password;
    this->port = port;
}

ConnectionParams::ConnectionParams(ConnectionParams *params)
{
    this->user = params->getUser();
    this->host = params->getHost();
    this->database = params->getDBName();
    this->password = params->getPassword();
    this->port = params->getPort();
}

std::string ConnectionParams::getHost()
{
    return this->host;
}

std::string ConnectionParams::getUser()
{
    return this->user;
}

std::string ConnectionParams::getDBName()
{
    return this->database;
}

std::string ConnectionParams::getPassword()
{
    return this->password;
}

int ConnectionParams::getPort()
{
    return this->port;
}

Connection::Connection(ConnectionParams *params)
{
    this->params = *params;
    this->connect = NULL;
}

ConnectionParams Connection::getParams()
{
    return this->params;
}

pqxx::connection* Connection::getConnection()
{
    return this->connect;
}

void Connection::setConnection(pqxx::connection *connect)
{
    this->connect = connect;
}

std::string ConnectionParams::getString()
{
    return "dbname = " + this->getDBName() +
           " user = " + this->getUser() +
           " password = " + this->getPassword() +
           " host = " + this->getHost() +
           " port = " + std::to_string(this->getPort());
}
