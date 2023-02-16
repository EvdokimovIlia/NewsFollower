#include <iostream>
#include <unistd.h>
#include <getopt.h>

#include <string>
#include <fstream>

#include <configure.h>

/// @brief Get project's version.
static std::string version()
{
     const std::string versionFileName = "VERSION";
     std::string version{};
     std::ifstream versionFile( versionFileName.c_str() );

     if( !versionFile.is_open() )
     {
         std::cerr << "File isn't open" << std::endl;
         return {};
     }

     versionFile >> version;

     return version;
}

/// @brief Print project's help.
static void help(void)
{
     std::cout << "The NewFollower: version " + version() + "\n\n" +
                    "-h, --help:      Helper\n" +
                    "-v, --version:   Version."
               << std::endl;
}

int main( int argc, char** argv )
{
     const char* const short_opts = ":hv";
     const option long_opts[] =
     {
          { "help",    no_argument, nullptr, 'h' },
          { "version", no_argument, nullptr, 'v' }
     };
     int c{};
     while( ( c = getopt_long( argc, argv, short_opts, long_opts, nullptr ) ) != -1 )
     {
          switch( c )
          {
               case 'h':
                    help();
                    break;
               case 'v':
                    std::cout << "Version: " << version() << std::endl;
                    break;
               default:
                    std::cout << "Wrong parameters! Use the following:\n";
                    help();
                    break;
          }
     }

     Configure conf;

     return EXIT_SUCCESS;
}
