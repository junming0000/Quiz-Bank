/***************************************************

Name:Pua Jun Ming

ID: 1141128767

Email: junming0000@gmail.com ; Phone: 017-9824232

***************************************************/


#ifndef QUESTIONTF_H
#define QUESTIONTF_H
#include <iostream>
#include "Question.h"
using namespace std;


class QuestionTF:public Question
{
    public:
    string getQuestion();
    void setQuestion(string question);
    int getScore();
    void setScore(int score);
    string getAnswer();
    void setAnswer(string answer);

};


#endif // QUESTIONTF_H
