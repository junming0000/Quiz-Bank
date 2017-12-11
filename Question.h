/***************************************************

Name:Pua Jun Ming

ID: 1141128767

Email: junming0000@gmail.com ; Phone: 017-9824232

***************************************************/


#ifndef QUESTION_H
#define QUESTION_H
#include <iostream>
using namespace std;

class Question
{
protected:
    int score;
    string question, questionType, answer;
    string selections1,selections2,selections3,selections4,selections5,selections6;
    int numOfChoise;
public:
    virtual int getScore()=0;
    virtual void setScore(int score)=0;
    virtual string getQuestion()=0;
    virtual void setQuestion(string question)=0;
    virtual string getAnswer()=0;
    virtual void setAnswer(string answer) =0;

    void setSelections(string selection1);
    void setSelections(string selection1,string selection2);
    void setSelections(string selection1,string selection2,string selection3);
    void setSelections(string selection1,string selection2,string selection3,string selection4);
    void setSelections(string selection1,string selection2,string selection3,string selection4,string selection5);
    void setSelections(string selection1,string selection2,string selection3,string selection4,string selection5,string selection6);

    string getSelections1();
    string getSelections2();
    string getSelections3();
    string getSelections4();
    string getSelections5();
    string getSelections6();

    void setNumOfChoise(int num);
    int getNumOfChoise();
    void setQuestionType(string type);
    string getQuestionType();

};


#endif // QUESTION_H
