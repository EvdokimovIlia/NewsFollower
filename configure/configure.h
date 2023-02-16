#pragma once
#ifndef CONFIGURE_H
#define CONFIGURE_H

#include <string>
#include <chrono>

// @brief Daemon configuration.
class Configure
{
private:
     // @brief check configure integrity.
     bool CheckIntegrity();

     uint64_t CalculateChecksum( const std::string& file );
public:
     Configure( const Configure& ) = delete;
     Configure( const Configure&& ) = delete;
     Configure& operator=( const Configure& ) = delete;
     Configure&& operator=( const Configure&& ) = delete;

     Configure( const std::string configure_file = "/tmp/news_follower.conf" );
     virtual ~Configure();
private:
     const std::string configureFile_; ///< daemon's configuration file.
     uint64_t checksum_;               ///< crc32 checksum of configuration.
     std::time_t last_launch_;         ///< Time of last launching daemon.
};

#endif // CONFIGURE_H
