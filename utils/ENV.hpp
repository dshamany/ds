#if !defined(_ENV_HPP_)
#define _ENV_HPP_

#include <fstream>
#include <map>
#include <string>

typedef std::map<std::string, std::string> VAR_LIST;
typedef const std::map<std::string, std::string> CONST_VAR_LIST;
typedef const std::string VALUE;

namespace PROCESS
{
class ENV
{
public:
    static ENV& instance() {

        // Singleton Object
        static ENV instance;

        // Open File
        std::ifstream ifile(".env");
        // Hold One Line at a Time
        std::string line;

        while (std::getline(ifile, line))
        {
            // Find Delimiter
            std::size_t pos = line.find("=");

            // Get Key and Value Sizes
            const int key_length = pos;
            const int val_length = (line.length() - pos - 1);

            // Set Variables to Map
            const std::string key = line.substr(0, key_length);
            const std::string val = line.substr(pos + 1, val_length);

            instance._variables.insert({key, val});
        }
        return instance;
    }

    CONST_VAR_LIST all() {
        return _variables;
    }

    VALUE value(const VALUE val){
        return _variables.find(val)->second;
    }

    void operator=(ENV const&) = delete;
private:
    ENV();
    VAR_LIST _variables;
};

ENV::ENV(){};

} // namespace PROCESS

#endif // _ENV_HPP_
