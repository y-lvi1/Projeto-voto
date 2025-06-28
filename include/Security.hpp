#ifndef SECURITY_HPP
#define SECURITY_HPP

#include <string>

class Security{
    private:

    std::string hash_loaded;

    public:

    Security();

    bool autenticate_admin();
};

#endif // SECURITY_HPP
