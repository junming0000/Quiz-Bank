/***************************************************

Name:Pua Jun Ming

ID: 1141128767

Email: junming0000@gmail.com ; Phone: 017-9824232

***************************************************/


#include "Highscore.h"

void Highscore::setScorePercentage(double a)
{
    scorePercentage = a;
}


void Highscore::countScorePercentage(int totalmark)
{
    int temp = GetPoints();
    if(temp <0)
    {
        scorePercentage = 0.00;
    }
    else
    {
        scorePercentage = (temp*100.00)/  totalmark;
    }

}

double Highscore::getscorePercentage()
{
    return scorePercentage;
}

string Highscore::GetFirstName()
{
    return firstName;

}

void Highscore::setFirstName(string a)
{
    firstName = a;
}

void Highscore::setLastName(string a)
{
    lastName = a;
}

string Highscore::GetLastName()
{
    return lastName;
}


int Highscore::setPoints(int point)
{
    this->points = points + point;
}

int Highscore::GetPoints()
{
    return points;
}
