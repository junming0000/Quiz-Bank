/***************************************************

Name:Pua Jun Ming

ID: 1141128767

Email: junming0000@gmail.com ; Phone: 017-9824232

***************************************************/


#ifndef HIGHSCORE_H
#define HIGHSCORE_H
#include "Player.h"


class Highscore:public Player
{
private:
    double scorePercentage;

public:
    void setFirstName(string a);
    void setLastName(string a);
    string GetFirstName();
    string GetLastName();
    int setPoints(int point);
    int GetPoints();
    void setScorePercentage(double a);
    void countScorePercentage(int numOfQuestionUserAnswer);
    double getscorePercentage();
};


#endif // HIGHSCORE_H
