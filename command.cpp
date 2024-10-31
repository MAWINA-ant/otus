#include "command.h"

Command::Command() 
{

}

Command::Command(const std::string& name, u_int8_t level) : commandName{name}, nestedLevel{level} 
{

}

Command::~Command() 
{

}