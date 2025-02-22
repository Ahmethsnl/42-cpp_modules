#include <string>
#include <iostream>

class Harl
{
    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
        std::string levels[4];
        void (Harl::*logFunctions[4])(void);
    public:
        Harl();
        void complain(std::string level);
};