/***************************************************

Name:Pua Jun Ming

ID: 1141128767

Email: junming0000@gmail.com ; Phone: 017-9824232

***************************************************/



#ifndef QUESTIONSA_H
#define QUESTIONSA_H
#include "Question.h"

class QuestionSA:public Question
{
    string getQuestion();
    void setQuestion(string question);
    int getScore();
    void setScore(int score);
    string getAnswer();
    void setAnswer(string answer);

};

#endif // QUESTIONSA_H
