#include "SSHClient.h"
#include <iostream>
#include <unistd.h>

SSHClient::SSHClient(
    std::string user, std::string password, std::string host, int port, int verbosity)
    : m_user(user)
    , m_password(password)
    , m_host(host)
    , m_port(port)
    , m_verbosity(verbosity)
{}

bool SSHClient::connect()
{
    try {
        m_session.setOption(SSH_OPTIONS_LOG_VERBOSITY, &m_verbosity);
        m_session.setOption(SSH_OPTIONS_PORT, &m_port);
        m_session.setOption(SSH_OPTIONS_USER, m_user.c_str());
        m_session.setOption(SSH_OPTIONS_HOST, m_host.c_str());

        m_session.connect();

        if (m_session.isServerKnown() != SSH_SERVER_KNOWN_OK) {
            if (m_session.writeKnownhost() != SSH_OK) {
                std::cout << "writeKnownHost failed" << std::endl;
                return false;
            } else {
                m_session.connect();
            }
        }

        if (m_session.userauthPassword(m_password.c_str()) != SSH_AUTH_SUCCESS) {
            std::cout << "failed auth" << std::endl;
            return false;
        }

        return true;
    } catch (ssh::SshException &e) {
        std::cout << "Error during connection: " << e.getError() << std::endl;
        return false;
    }
}

bool SSHClient::sendCommand(const std::string &command)
{
    try {
        ssh::Channel channel(m_session);
        channel.openSession();
        channel.requestExec(command.c_str());
        channel.close();
        channel.sendEof();

        sleep(1);

        return true;
    } catch (ssh::SshException &e) {
        std::cout << "Error during command execution: " << e.getError() << std::endl;
        return false;
    }
}
