#include <configure.h>

#include <iostream>

uint64_t Configure::CalculateChecksum( const std::string& file )
{
     std::cout << file << std::endl;
     return 0;
}

bool Configure::CheckIntegrity()
{
     return checksum_ == CalculateChecksum( configureFile_ );
}

Configure::Configure( const std::string configure_file ):
     configureFile_( configure_file )
{
     checksum_ = CalculateChecksum( configureFile_ );
     last_launch_ = std::chrono::system_clock::to_time_t( std::chrono::system_clock::now() );
}

Configure::~Configure()
{}
