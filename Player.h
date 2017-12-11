/***************************************************

Name:Pua Jun Ming

ID: 1141128767

Email: junming0000@gmail.com ; Phone: 017-9824232

***************************************************/


#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
using namespace std;



class Player
{
protected:
    int points;
    string firstName, lastName;
public:
    Player();
    virtual void setFirstName(string a)=0;
    virtual void setLastName(string a)=0;
    virtual string GetFirstName()=0;
    virtual string GetLastName()=0;
    virtual int setPoints(int point)=0;
    virtual int GetPoints()=0;
    virtual void setScorePercentage(double a)=0;
    virtual void countScorePercentage(int numOfQuestionUserAnswer)=0;
    virtual double getscorePercentage()=0;



};

#endif // PLAYER_H
