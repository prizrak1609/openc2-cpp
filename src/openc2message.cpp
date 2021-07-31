#include "openc2message.h"


OC::OpenC2Message& OC::OpenC2Message::setAction(std::string_view action)
{
    this->action = action;
}

OC::OpenC2Message& OC::OpenC2Message::setTarget(const Target &target)
{
    this->target = target;
}

OC::OpenC2Message& OC::OpenC2Message::setArgs(const Args &args)
{
    this->args = args;
}

OC::OpenC2Message& OC::OpenC2Message::setCommandId(std::string_view commandId)
{
    this->commandId = commandId;
}
