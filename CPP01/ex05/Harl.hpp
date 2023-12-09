#ifndef HARL_HPP
#define  HARL_HPP

#include <iostream>
#include <string>

class Harl{
    private:
    typedef void (Harl::*MemberFunction)();

    struct LevelFunctionPair {
        const char* level;
        MemberFunction function;
    };

    static const LevelFunctionPair levelFunctions[];

        void debug(void);
        void info( void );
        void warning( void );
        void error( void );

    public:
        Harl();
		~Harl();
        void complain(std::string level);

};

#endif