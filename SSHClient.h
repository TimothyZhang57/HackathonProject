#ifndef SSHCLIENT_H
#define SSHCLIENT_H

#include <libssh/libsshpp.hpp>
#include <string>

class SSHClient {
private:
  ssh::Session m_session;
  int m_verbosity;
  int m_port;
  std::string m_user;
  std::string m_host;
  std::string m_password;

public:
  SSHClient(std::string user = "qnxuser", std::string password = "qnxuser",
            std::string host = "192.168.1.1", int port = 22,
            int verbosity = SSH_LOG_NOLOG);

  bool connect();

  bool sendCommand(const std::string &command);

  ~SSHClient() = default;
};

#endif // SSHCLIENT_H
