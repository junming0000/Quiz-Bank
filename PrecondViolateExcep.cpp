/***************************************************

Name:Pua Jun Ming

ID: 1141128767

Email: junming0000@gmail.com ; Phone: 017-9824232

***************************************************/

#include "PrecondViolateExcep.h"


PrecondViolatedExcep::PrecondViolatedExcep(const string& message): logic_error("Precondition Violated Exception: " + message)
{
}
