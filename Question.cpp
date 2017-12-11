/***************************************************

Name:Pua Jun Ming

ID: 1141128767

Email: junming0000@gmail.com ; Phone: 017-9824232

***************************************************/


#include "Question.h"

void Question::setSelections(string selection1)
{
    this->selections1=selection1;
}
void Question::setSelections(string selection1,string selection2)
{
    this->selections1=selection1;
    this->selections2=selection2;
}
void Question::setSelections(string selection1,string selection2,string selection3)
{
    this->selections1=selection1;
    this->selections2=selection2;
    this->selections3=selection3;
}
void Question::setSelections(string selection1,string selection2,string selection3,string selection4)
{
    this->selections1=selection1;
    this->selections2=selection2;
    this->selections3=selection3;
    this->selections4=selection4;
}
void Question::setSelections(string selection1,string selection2,string selection3,string selection4,string selection5)
{
    this->selections1=selection1;
    this->selections2=selection2;
    this->selections3=selection3;
    this->selections4=selection4;
    this->selections5=selection5;
}
void Question::setSelections(string selection1,string selection2,string selection3,string selection4,string selection5,string selection6)
{
    this->selections1=selection1;
    this->selections2=selection2;
    this->selections3=selection3;
    this->selections4=selection4;
    this->selections5=selection5;
    this->selections6=selection6;
}

string Question::getSelections1()
{
    return selections1;
}
string Question::getSelections2()
{
    return selections2;
}
string Question::getSelections3()
{
    return selections3;
}
string Question::getSelections4()
{
    return selections4;
}
string Question::getSelections5()
{
    return selections5;
}
string Question::getSelections6()
{
    return selections6;
}

void Question::setNumOfChoise(int num)
{
    this->numOfChoise=num;
}
int Question::getNumOfChoise()
{
    return numOfChoise;
}

void Question::setQuestionType(string type)
{
    questionType = type;
}

string Question::getQuestionType()
{
    return questionType;
}
