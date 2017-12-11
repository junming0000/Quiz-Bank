/***************************************************

Name:Pua Jun Ming

ID: 1141128767

Email: junming0000@gmail.com ; Phone: 017-9824232

***************************************************/


#ifndef QUESTIONMC_H
#define QUESTIONMC_H
#include "Question.h"

class QuestionMC: public Question{
private:



public:
    string getQuestion();
    void setQuestion(string question);
    int getScore();
    void setScore(int score);
    string getAnswer();
    void setAnswer(string answer);


};

#endif // QUESTIONMC_H



