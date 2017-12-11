#ifndef PRECONDVIOLATEDEXCEP_H
#define PRECONDVIOLATEDEXCEP_H

#include <stdexcept>
#include <string>

using namespace std;

class PrecondViolatedExcep: public logic_error
{
public:
   PrecondViolatedExcep(const string& message = "");
};


#endif // PRECONDVIOLATEDEXCEP_H
