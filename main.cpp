/***************************************************

Name:Pua Jun Ming

ID: 1141128767

Email: junming0000@gmail.com ; Phone: 017-9824232

***************************************************/


#include <iostream>
#include <iomanip>
#include "Question.h"
#include "QuestionTF.h"
#include "QuestionMC.h"
#include "QuestionSA.h"
#include "Player.h"
#include "Highscore.h"
#include "Node.h"
#include "LinkedList.h"
#include "PrecondViolateExcep.h"
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;


int main()
{
    string player1FirstName,player1LastName;
    string questionFileName;
    int totalQuestion;
    int insertQuestionNumber=1;
    int removeCounter=1;
    int editCounter=1;
    int checkNumQuestionInserted=0;
    string line;



    LinkedList <Question*> allQuestion;
    LinkedList <Question*> removeQuestionLinkedList;
    LinkedList <Question*> editQuestionLinkedList;
    LinkedList <Player*> playerHighScore;
    Player* player1 = new Highscore;

    cout<< "What is your first name: "<<endl;
    getline(cin,player1FirstName);
    cout<< "What is your last name: "<<endl;
    getline(cin,player1LastName);

    player1->setFirstName(player1FirstName);
    player1->setLastName(player1LastName);



////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////          ADD QUESTION            ////////////////////////////////////////
    string adminAnswer,newQuestionType, newQuestion, newAnswer,addFileName,newMCSelection[6];
    int newQuestionScore,newNumberOfMCSelection;
    cout<<endl<<"Do You Want to Add Any Question into Any Database?('Y' / 'N')"<<endl;
    cin>> adminAnswer;

    if(adminAnswer == "y" || adminAnswer == "Y")
    {
        cout<<endl<<"Please Enter the file name you want to edit."<<endl;
        cin>>addFileName;

        ofstream quizOut;
        quizOut.open(addFileName.c_str(),fstream::app);
        quizOut<<endl;
        while(adminAnswer == "y" || adminAnswer == "Y")
        {
            cout<<endl<<"Please insert the type of question you want to insert. ( MC / SA / TF )"<<endl;
            cin>> newQuestionType;
            cout<<endl<<"How Many Point(s) Do You Want to Set for the Question? (ONLY INTEGER ALLOWED)"<<endl;
            cin>>newQuestionScore;
            cout<<endl<<"Please Enter the Question."<<endl;
            cin.ignore();
            getline(cin,newQuestion);

            if(newQuestionType == "MC")
            {
                cout<<endl<<"How many selection(s) for the Question you inserted? (MIN = 1 MAX = 6)"<<endl;
                cin>>newNumberOfMCSelection;
                cin.ignore();
                for(int i=0; i <newNumberOfMCSelection ; i++)
                {
                    cout<<endl<<"Please insert the selection. "<<endl;
                    getline(cin,newMCSelection[i]);
                }
                cout<<endl<<"Please Insert the answer for the Question. (A / B / C / D / E / F)"<<endl;
                getline(cin,newAnswer);
            }
            else
            {
                if(newQuestionType == "TF")
                {
                    cout<<endl<<"Please Insert the answer for the Question. (true/false)"<<endl;
                    getline(cin,newAnswer);
                }
                else
                {
                    cout<<endl<<"Please Insert the answer for the Question."<<endl;
                    getline(cin,newAnswer);
                }
            }


            if(newQuestionType == "MC")
            {

                quizOut<<newQuestionType<<" "<<newQuestionScore<<endl;
                quizOut<<newQuestion<<endl;
                quizOut<<newNumberOfMCSelection<<endl;
                for(int a =0 ; a<newNumberOfMCSelection; a++)
                {
                    quizOut<<newMCSelection[a]<<endl;
                }
                quizOut<<newAnswer<<endl;
            }
            else
            {
                quizOut<<newQuestionType<<" "<<newQuestionScore<<endl;
                quizOut<< newQuestion<<endl;
                quizOut<<newAnswer<<endl;
            }
            cout<<endl<<"Do You Want to Add Anymore Question into the Database?('Y' / 'N')"<<endl;
            cin>> adminAnswer;
            checkNumQuestionInserted = checkNumQuestionInserted +1;


        }

        quizOut.close();

        //FINALIZE THE FILE AFTER UPDATE THE QUESTION INTO FILE
        ifstream updateFile(addFileName.c_str());
        int temp1;
        int newestInsertNumberOfQuestion;

        ofstream temp("temp.txt");

        if(updateFile.is_open())
        {

            updateFile>>newestInsertNumberOfQuestion;
            temp1 = newestInsertNumberOfQuestion;

            getline(updateFile,line);
            temp1 = temp1 + checkNumQuestionInserted;
            temp<<temp1<<endl;

            while(!updateFile.eof())
            {
                getline(updateFile,line);
                    temp<<line<<endl;
            }
            updateFile.close();
            temp.close();
            // delete the original file
            remove(addFileName.c_str());
            // rename old to new
            rename("temp.txt",addFileName.c_str());
        }
    }


////////////////////////////////////////////////////////////////////////////////////////////////
// ***************           REMOVE QUESTION            *****************************************
        string removeUserAnswer,removeFileName;
        int questionToRemove;


        cout<<endl<<"Do you want to remove any question from the database? ( Y / N )"<<endl;
        cin>>removeUserAnswer;

        if(removeUserAnswer == "y" || removeUserAnswer == "Y")
        {
            Question* removeQuestion;

            cout<<endl<<"Which file would you like to choose for removing Question?"<<endl;
            cin>>removeFileName;

            ifstream removeQuestionFromFile(removeFileName.c_str());
            ofstream tempRemove ("tempRemoveFile.txt");

            if (removeQuestionFromFile.is_open())
            {
                removeQuestionFromFile>>totalQuestion;

                //LOAD ALL THE QUESTION FROMT THE FILE THAT ARE GOING TO REMOVE QUETION
                while(!removeQuestionFromFile.eof())
                {
                    string removequestionType,removeskipNewLine,removeques,removeanswer,removemcChoise[6];
                    int removescore,removenumOfMCChoise;

                  removeQuestionFromFile>>removequestionType>>removescore;
                    getline(removeQuestionFromFile,removeskipNewLine);
                    if (removequestionType == "TF")
                    {
                        getline(removeQuestionFromFile,removeques);
                        getline(removeQuestionFromFile,removeanswer);
                        Question* TF = new QuestionTF;
                        TF->setQuestion(removeques);
                        TF->setAnswer(removeanswer);
                        TF->setScore(removescore);
                        TF->setQuestionType(removequestionType);
                        removeQuestionLinkedList.insert(removeCounter,TF);
                    }

                    if(removequestionType == "SA")
                    {
                        getline(removeQuestionFromFile,removeques);
                        getline(removeQuestionFromFile,removeanswer);
                        Question* SA = new QuestionSA;
                        SA->setAnswer(removeanswer);
                        SA->setQuestion(removeques);
                        SA->setScore(removescore);
                        SA->setQuestionType(removequestionType);
                        removeQuestionLinkedList.insert(removeCounter,SA);
                    }

                    if (removequestionType=="MC")
                    {
                        getline(removeQuestionFromFile,removeques);
                        removeQuestionFromFile>>removenumOfMCChoise;
                        getline(removeQuestionFromFile,removeskipNewLine);
                        Question* MC = new QuestionMC;

                        for(int i=0 ; i<removenumOfMCChoise ; i++)
                            {
                                getline(removeQuestionFromFile,removemcChoise[i]);
                            }

                        if(removenumOfMCChoise==1)
                        {
                            MC->setSelections(removemcChoise[0]);
                        }
                        else
                        {
                            if(removenumOfMCChoise==2)
                            {
                                MC->setSelections(removemcChoise[0],removemcChoise[1]);
                            }
                            else
                            {
                                if(removenumOfMCChoise==3)
                                {
                                    MC->setSelections(removemcChoise[0],removemcChoise[1],removemcChoise[2]);
                                }
                                else
                                {
                                    if(removenumOfMCChoise==4)
                                    {
                                        MC->setSelections(removemcChoise[0],removemcChoise[1],removemcChoise[2],removemcChoise[3]);
                                    }
                                    else
                                    {
                                        if(removenumOfMCChoise==5)
                                        {
                                            MC->setSelections(removemcChoise[0],removemcChoise[1],removemcChoise[2],removemcChoise[3],removemcChoise[4]);
                                        }
                                        else
                                        {
                                            MC->setSelections(removemcChoise[0],removemcChoise[1],removemcChoise[2],removemcChoise[3],removemcChoise[4],removemcChoise[5]);

                                        }
                                    }
                                }
                            }
                        }
                        getline(removeQuestionFromFile,removeanswer);
                        MC->setAnswer(removeanswer);
                        MC->setQuestion(removeques);
                        MC->setScore(removescore);
                        MC->setQuestionType(removequestionType);
                        MC->setNumOfChoise(removenumOfMCChoise);
                        removeQuestionLinkedList.insert(removeCounter,MC);
                    }

                    removeCounter= removeCounter +1;
                }

                cout<<endl;
                cout<<"*****************************************************"<<endl;

                while(removeUserAnswer == "y" || removeUserAnswer == "Y")
                {
                    // PRINT ALL THE QUESTION IN THE DATABASE FOR USER TO CHOOSE
                    for(int i =1 ; i <= removeQuestionLinkedList.getLength() ; i++)
                    {
                        removeQuestion = removeQuestionLinkedList.retrieve(i);

                        cout<<"Question "<<i<<":"<<endl;
                        cout<<removeQuestion->getQuestion()<<endl<<endl;
                    }
                    cout<<"*****************************************************"<<endl;

                    cout<<"Which question would you like to remove? (1/2/3/4 ......)"<<endl;
                    cin>>questionToRemove;

                    if(questionToRemove >0 && questionToRemove <= removeQuestionLinkedList.getLength())
                    {
                        removeQuestionLinkedList.erase(questionToRemove);
                    }
                    else
                    {
                        cout<<"Invalid Input"<<endl<<endl;
                    }
                    cout<<endl<<"Do you want to remove anymore question? ( Y / N )"<<endl;
                    cin>>removeUserAnswer;
                    cout<<endl;
                }

                tempRemove<<removeQuestionLinkedList.getLength()<<endl;

                /////////////// LOAD FILE TO TEMP FILE TO BECOME THE ORIGINAL FILE
                for(int counter = 1; counter<=removeQuestionLinkedList.getLength() ; counter++)
                {
                    removeQuestion = removeQuestionLinkedList.retrieve(counter);

                    if(removeQuestion->getQuestionType() == "MC")
                    {
                        tempRemove<<removeQuestion->getQuestionType()<<" "<<removeQuestion->getScore()<<endl;
                        tempRemove<<removeQuestion->getQuestion()<<endl;
                        tempRemove<<removeQuestion->getNumOfChoise()<<endl;
                        if(removeQuestion->getNumOfChoise() == 1)
                        {
                            tempRemove<<removeQuestion->getSelections1()<<endl;
                        }
                        else
                        {
                            if(removeQuestion->getNumOfChoise() == 2)
                            {
                               tempRemove<<removeQuestion->getSelections1()<<endl;
                                    tempRemove<<removeQuestion->getSelections2()<<endl;
                            }
                            else
                            {
                                if(removeQuestion->getNumOfChoise() == 3)
                                {
                                    tempRemove<<removeQuestion->getSelections1()<<endl;
                                    tempRemove<<removeQuestion->getSelections2()<<endl;
                                    tempRemove<<removeQuestion->getSelections3()<<endl;
                                }
                                else
                                {
                                    if(removeQuestion->getNumOfChoise() == 4)
                                    {
                                        tempRemove<<removeQuestion->getSelections1()<<endl;
                                        tempRemove<<removeQuestion->getSelections2()<<endl;
                                        tempRemove<<removeQuestion->getSelections3()<<endl;
                                        tempRemove<<removeQuestion->getSelections4()<<endl;
                                    }
                                    else
                                    {
                                        if(removeQuestion->getNumOfChoise() == 5)
                                        {
                                            tempRemove<<removeQuestion->getSelections1()<<endl;
                                            tempRemove<<removeQuestion->getSelections2()<<endl;
                                            tempRemove<<removeQuestion->getSelections3()<<endl;
                                            tempRemove<<removeQuestion->getSelections4()<<endl;
                                            tempRemove<<removeQuestion->getSelections5()<<endl;
                                        }
                                        else
                                        {
                                            tempRemove<<removeQuestion->getSelections1()<<endl;
                                            tempRemove<<removeQuestion->getSelections2()<<endl;
                                            tempRemove<<removeQuestion->getSelections3()<<endl;
                                            tempRemove<<removeQuestion->getSelections4()<<endl;
                                            tempRemove<<removeQuestion->getSelections5()<<endl;
                                            tempRemove<<removeQuestion->getSelections6()<<endl;
                                        }
                                    }
                                }
                            }
                        }
                        tempRemove<<removeQuestion->getAnswer()<<endl;

                    }
                    else
                    {
                        tempRemove<<removeQuestion->getQuestionType()<<" "<<removeQuestion->getScore()<<endl;
                        tempRemove<<removeQuestion->getQuestion()<<endl;
                        tempRemove<<removeQuestion->getAnswer()<<endl;
                    }

                }
                removeQuestionFromFile.close();
                tempRemove.close();
                remove(removeFileName.c_str());
                rename("tempRemoveFile.txt",removeFileName.c_str());
            }
            else
            {
                cout<<"NO SUCH FILE TO BE EDIT!!"<<endl<<endl;
            }
        }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////          EDIT FILE                     /////////////////////////////////////////////

    string editUserAnswer,editFileName,editWordToFind,editTemp,editNewQuestion;
    int editTotalQuestion;
    int editCounter2 =1;

    Question* editQuestion;

    cout<<endl<<"Do you want to edit any File? ( Y / N )"<<endl;
    cin>>editUserAnswer;

    if(editUserAnswer == "y" || editUserAnswer == "Y")
    {
            cout<< endl<< "Which file would you like to edit?"<<endl;
            cin>>editFileName;

            ifstream editOpenFile(editFileName.c_str());

            //LOAD ALL THE QUESTION  FROMTHE FILE SELECTED TO EDIT
            if (editOpenFile.is_open())
            {
                editOpenFile>>editTotalQuestion;

                while(!editOpenFile.eof())
                {
                    string editquestionType,editskipNewLine,editques,editanswer,editmcChoise[6];
                    int editscore,editnumOfMCChoise;

                    editOpenFile>>editquestionType>>editscore;
                    getline(editOpenFile,editskipNewLine);
                    if (editquestionType == "TF")
                    {
                        getline(editOpenFile,editques);
                        getline(editOpenFile,editanswer);
                        Question* TF = new QuestionTF;
                        TF->setQuestion(editques);
                        TF->setAnswer(editanswer);
                        TF->setScore(editscore);
                        TF->setQuestionType(editquestionType);
                        editQuestionLinkedList.insert(editCounter,TF);
                    }

                    if(editquestionType == "SA")
                    {
                        getline(editOpenFile,editques);
                        getline(editOpenFile,editanswer);
                        Question* SA = new QuestionSA;
                        SA->setAnswer(editanswer);
                        SA->setQuestion(editques);
                        SA->setScore(editscore);
                        SA->setQuestionType(editquestionType);
                        editQuestionLinkedList.insert(editCounter,SA);
                    }

                    if (editquestionType=="MC")
                    {
                        getline(editOpenFile,editques);
                        editOpenFile>>editnumOfMCChoise;
                        getline(editOpenFile,editskipNewLine);
                        Question* MC = new QuestionMC;

                        for(int i=0 ; i<editnumOfMCChoise ; i++)
                            {
                                getline(editOpenFile,editmcChoise[i]);
                            }

                        if(editnumOfMCChoise==1)
                        {
                            MC->setSelections(editmcChoise[0]);
                        }
                        else
                        {
                            if(editnumOfMCChoise==2)
                            {
                                MC->setSelections(editmcChoise[0],editmcChoise[1]);
                            }
                            else
                            {
                                if(editnumOfMCChoise==3)
                                {
                                    MC->setSelections(editmcChoise[0],editmcChoise[1],editmcChoise[2]);
                                }
                                else
                                {
                                    if(editnumOfMCChoise==4)
                                    {
                                        MC->setSelections(editmcChoise[0],editmcChoise[1],editmcChoise[2],editmcChoise[3]);
                                    }
                                    else
                                    {
                                        if(editnumOfMCChoise==5)
                                        {
                                            MC->setSelections(editmcChoise[0],editmcChoise[1],editmcChoise[2],editmcChoise[3],editmcChoise[4]);
                                        }
                                        else
                                        {
                                            MC->setSelections(editmcChoise[0],editmcChoise[1],editmcChoise[2],editmcChoise[3],editmcChoise[4],editmcChoise[5]);

                                        }
                                    }
                                }
                            }
                        }
                        getline(editOpenFile,editanswer);
                        MC->setAnswer(editanswer);
                        MC->setQuestion(editques);
                        MC->setScore(editscore);
                        MC->setQuestionType(editquestionType);
                        MC->setNumOfChoise(editnumOfMCChoise);
                        editQuestionLinkedList.insert(editCounter,MC);
                    }

                    editCounter = editCounter+1;

                }








            }

            cout<<endl<<"Insert to Seach for Specific Word/Phrase in  the Question to edit"<<endl;
            cin.ignore();
            getline(cin,editWordToFind);
            cout<<endl;
            while(editCounter2<= editQuestionLinkedList.getLength() )
            {
                editQuestion = editQuestionLinkedList.retrieve(editCounter2);
                editTemp = editQuestion->getQuestion();
                if(editTemp.find(editWordToFind) != string::npos)
                {
                    cout<<endl<<"Please Insert the new Question for Question "<<editCounter2<<endl;
                    getline(cin,editNewQuestion);
                    editQuestion->setQuestion(editNewQuestion);

                    cout<<endl<<"DONE EDITING THE FILE!!"<<endl;
                    cout<<"**************************************************************"<<endl<<endl;
                    break;
                }
                else
                {
                    cout<<"Question "<<editCounter2<<" do not have any specific word/phrase you find!!"<<endl;
                }
                editCounter2= editCounter2 + 1;
            }
            ofstream editTempFile("editTemp.txt");

            //LOAD EDITED LINKED LIST INTO new fILe AND CHANGE NAME To ORIGINAL FILE
            editTempFile<<editQuestionLinkedList.getLength()<<endl;
            for(int counter = 1; counter<=editQuestionLinkedList.getLength() ; counter++)
            {
                editQuestion = editQuestionLinkedList.retrieve(counter);

                if(editQuestion->getQuestionType() == "MC")
                {
                    editTempFile<<editQuestion->getQuestionType()<<" "<<editQuestion->getScore()<<endl;
                    editTempFile<<editQuestion->getQuestion()<<endl;
                    editTempFile<<editQuestion->getNumOfChoise()<<endl;
                    if(editQuestion->getNumOfChoise() == 1)
                    {
                        editTempFile<<editQuestion->getSelections1()<<endl;
                    }
                    else
                    {
                        if(editQuestion->getNumOfChoise() == 2)
                        {
                            editTempFile<<editQuestion->getSelections1()<<endl;
                            editTempFile<<editQuestion->getSelections2()<<endl;
                        }
                        else
                        {
                            if(editQuestion->getNumOfChoise() == 3)
                            {
                                editTempFile<<editQuestion->getSelections1()<<endl;
                                editTempFile<<editQuestion->getSelections2()<<endl;
                                editTempFile<<editQuestion->getSelections3()<<endl;
                            }
                            else
                            {
                                if(editQuestion->getNumOfChoise() == 4)
                                {
                                    editTempFile<<editQuestion->getSelections1()<<endl;
                                    editTempFile<<editQuestion->getSelections2()<<endl;
                                    editTempFile<<editQuestion->getSelections3()<<endl;
                                    editTempFile<<editQuestion->getSelections4()<<endl;
                                }
                                else
                                {
                                    if(editQuestion->getNumOfChoise() == 5)
                                    {
                                        editTempFile<<editQuestion->getSelections1()<<endl;
                                        editTempFile<<editQuestion->getSelections2()<<endl;
                                        editTempFile<<editQuestion->getSelections3()<<endl;
                                        editTempFile<<editQuestion->getSelections4()<<endl;
                                        editTempFile<<editQuestion->getSelections5()<<endl;
                                    }
                                    else
                                    {
                                        editTempFile<<editQuestion->getSelections1()<<endl;
                                        editTempFile<<editQuestion->getSelections2()<<endl;
                                        editTempFile<<editQuestion->getSelections3()<<endl;
                                        editTempFile<<editQuestion->getSelections4()<<endl;
                                        editTempFile<<editQuestion->getSelections5()<<endl;
                                        editTempFile<<editQuestion->getSelections6()<<endl;
                                    }
                                }
                            }
                        }
                    }
                    editTempFile<<editQuestion->getAnswer()<<endl;

                }
                else
                {
                    editTempFile<<editQuestion->getQuestionType()<<" "<<editQuestion->getScore()<<endl;
                    editTempFile<<editQuestion->getQuestion()<<endl;
                    editTempFile<<editQuestion->getAnswer()<<endl;
                }

            }

            editOpenFile.close();
            editTempFile.close();
            remove(editFileName.c_str());
            rename("editTemp.txt",editFileName.c_str());
    }


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////   USER START TO CHOOSE WHICH FILE TO ANSWER   ///////////////////////////////


        cout<<endl<<"What file do you wish to answer?"<<endl;
        cin>>questionFileName;
        int totalScoreUserAnswer = 0;

        ifstream quiz(questionFileName.c_str());

        if (quiz.is_open())
        {
            quiz>>totalQuestion;

            //LOAD ALL THE QUESTION
            while(!quiz.eof())
            {

                string questionType,skipNewLine,ques,answer,mcChoise[6];
                int score,numOfMCChoise;
                quiz>>questionType>>score;
                getline(quiz,skipNewLine);
                if (questionType == "TF")
                {
                    getline(quiz,ques);
                    getline(quiz,answer);
                    Question* TF = new QuestionTF;
                    TF->setQuestion(ques);
                    TF->setAnswer(answer);
                    TF->setScore(score);
                    TF->setQuestionType(questionType);
                    allQuestion.insert(insertQuestionNumber,TF);
                }

                if(questionType == "SA")
                {
                    getline(quiz,ques);
                    getline(quiz,answer);
                    Question* SA = new QuestionSA;
                    SA->setAnswer(answer);
                    SA->setQuestion(ques);
                    SA->setScore(score);
                    SA->setQuestionType(questionType);
                    allQuestion.insert(insertQuestionNumber,SA);
                }

                if (questionType=="MC")
                {
                    getline(quiz,ques);
                    quiz>>numOfMCChoise;
                    getline(quiz,skipNewLine);
                    Question* MC = new QuestionMC;

                    for(int i=0 ; i<numOfMCChoise ; i++)
                        {
                            getline(quiz,mcChoise[i]);
                        }

                    if(numOfMCChoise==1)
                    {
                        MC->setSelections(mcChoise[0]);
                    }
                    else
                    {
                        if(numOfMCChoise==2)
                        {
                            MC->setSelections(mcChoise[0],mcChoise[1]);
                        }
                        else
                        {
                            if(numOfMCChoise==3)
                            {
                                MC->setSelections(mcChoise[0],mcChoise[1],mcChoise[2]);
                            }
                            else
                            {
                                if(numOfMCChoise==4)
                                {
                                    MC->setSelections(mcChoise[0],mcChoise[1],mcChoise[2],mcChoise[3]);
                                }
                                else
                                {
                                    if(numOfMCChoise==5)
                                    {
                                        MC->setSelections(mcChoise[0],mcChoise[1],mcChoise[2],mcChoise[3],mcChoise[4]);
                                    }
                                    else
                                    {
                                        MC->setSelections(mcChoise[0],mcChoise[1],mcChoise[2],mcChoise[3],mcChoise[4],mcChoise[5]);

                                    }
                                }
                            }
                        }
                    }


                    getline(quiz,answer);
                    MC->setAnswer(answer);
                    MC->setQuestion(ques);
                    MC->setScore(score);
                    MC->setQuestionType(questionType);
                    MC->setNumOfChoise(numOfMCChoise);
                    allQuestion.insert(insertQuestionNumber,MC);




                }

                insertQuestionNumber= insertQuestionNumber +1;
            }

            quiz.close();

            //SHUFFLE ALL THE QUESTION
            allQuestion.randomize();

    //////////////////////////////////////////////////////////////////////
    ////////////          User start to answer     //////////////////////
            int numOfQuestion;
            int totalScoreUserAnswer = 0;
            cout<<endl<<"How many questions would you like (out of "<<totalQuestion<<")?"<<endl;
            cin>>numOfQuestion;
            while(!cin>>numOfQuestion || numOfQuestion>totalQuestion)
            {
                cout<<"Sorry,that is not valid."<<endl;
                cout<<"How many questions would you like (out of "<<totalQuestion<<")?"<<endl;
                cin.clear();
                cin.ignore(100,'\n');
                cin>>numOfQuestion;
            }
            int userScore = 0 ;
            Question *storeQuestion;


///////////////////////Print Question///////////////////////////////
            for(int i =1; i <= numOfQuestion;i++)
            {

                cout<<endl;
                string userAnswer,checkQuestionType,checkUserAnswer;

                storeQuestion=allQuestion.retrieve(i);
                totalScoreUserAnswer =totalScoreUserAnswer + storeQuestion->getScore();

                if (storeQuestion->getQuestionType() == "TF")
                {
                    cout<<"Question "<<i<<" ("<<storeQuestion->getScore()<<" points)"<<endl;
                    cout<<storeQuestion->getQuestion()<<"(true / false)"<<endl<<endl;
                    cout<<"Answer : ";
                    cin>>userAnswer;

                    if(userAnswer == storeQuestion->getAnswer())
                    {
                        cout<<"Correct! You get "<<storeQuestion->getScore()<<" points."<<endl<<endl;
                        userScore = userScore + storeQuestion->getScore();
                    }
                    else
                    {
                        cout<<"Incorrect, the answer was "<<storeQuestion->getAnswer()<<". You lose "<<storeQuestion->getScore()<<" points."<<endl<<endl;
                        userScore = userScore - storeQuestion->getScore();
                    }
                }


                if (storeQuestion->getQuestionType() == "SA")
                {
                    cout<<"Question "<<i<<" ("<<storeQuestion->getScore()<<" points)"<<endl;
                    cout<<storeQuestion->getQuestion()<<endl<<endl;
                    cout<<"Answer: ";
                    cin>>userAnswer;

                    if(userAnswer == storeQuestion->getAnswer())
                    {
                        cout<<"Correct! You get "<<storeQuestion->getScore()<<" points."<<endl<<endl;
                        userScore=userScore + storeQuestion->getScore();
                    }
                    else
                    {
                        cout<< "Incorrect, the answer was "<<storeQuestion->getAnswer()<<". You lose "<<storeQuestion->getScore()<<" points. "<<endl<<endl;
                        userScore=userScore - storeQuestion->getScore();
                    }
                }

                if( storeQuestion->getQuestionType() == "MC")
                {
                    int selectionSize = storeQuestion->getNumOfChoise();
                    cout<<"Question "<<i<<" ("<<storeQuestion->getScore()<<" points)"<<endl;
                    cout<<storeQuestion->getQuestion()<<endl;
                    if(selectionSize==1)
                    {
                        cout<<"Selection A= "<<storeQuestion->getSelections1()<<endl<<endl;
                    }
                    else
                    {
                        if(selectionSize==2)
                        {
                            cout<<"Selection A= "<<storeQuestion->getSelections1()<<endl;
                            cout<<"Selection B= "<<storeQuestion->getSelections2()<<endl<<endl;
                        }
                        else
                        {
                            if(selectionSize==3)
                            {
                                cout<<"Selection A= "<<storeQuestion->getSelections1()<<endl;
                                cout<<"Selection B= "<<storeQuestion->getSelections2()<<endl;
                                cout<<"Selection C= "<<storeQuestion->getSelections3()<<endl<<endl;
                            }
                            else
                            {
                                if(selectionSize==4)
                                {
                                    cout<<"Selection A= "<<storeQuestion->getSelections1()<<endl;
                                    cout<<"Selection B= "<<storeQuestion->getSelections2()<<endl;
                                    cout<<"Selection C= "<<storeQuestion->getSelections3()<<endl;
                                    cout<<"Selection D= "<<storeQuestion->getSelections4()<<endl<<endl;
                                }
                                else
                                {
                                    if(selectionSize==5)
                                    {
                                        cout<<"Selection A= "<<storeQuestion->getSelections1()<<endl;
                                        cout<<"Selection B= "<<storeQuestion->getSelections2()<<endl;
                                        cout<<"Selection C= "<<storeQuestion->getSelections3()<<endl;
                                        cout<<"Selection D= "<<storeQuestion->getSelections4()<<endl;
                                        cout<<"Selection E= "<<storeQuestion->getSelections5()<<endl<<endl;
                                    }
                                    else
                                    {
                                        cout<<"Selection A= "<<storeQuestion->getSelections1()<<endl;
                                        cout<<"Selection B= "<<storeQuestion->getSelections2()<<endl;
                                        cout<<"Selection C= "<<storeQuestion->getSelections3()<<endl;
                                        cout<<"Selection D= "<<storeQuestion->getSelections4()<<endl;
                                        cout<<"Selection E= "<<storeQuestion->getSelections5()<<endl;
                                        cout<<"Selection F= "<<storeQuestion->getSelections6()<<endl<<endl;
                                    }
                                }
                            }
                        }
                    }

                    cout<<"Answer: ";
                    cin>>userAnswer;

                    if(userAnswer == storeQuestion->getAnswer())
                    {
                        cout<<"Correct! You got "<<storeQuestion->getScore()<<" points."<<endl<<endl;
                        userScore=userScore + storeQuestion->getScore();
                    }
                    else
                    {
                        cout<<"Incorrect, the answer is "<<storeQuestion->getAnswer()<<". You lose "<<storeQuestion->getScore()<<" points."<<endl<<endl;
                        userScore = userScore - storeQuestion->getScore();
                    }



                }


            }
             //SHOW USER SCORE
            player1->setPoints(userScore);
            player1->countScorePercentage(totalScoreUserAnswer);
            //player1->setScorePercentage(numOfQuestion);
            cout<<player1->GetFirstName()<<" "<<player1->GetLastName()<<", your game is over!"<<endl;
            cout<<"Your final score is "<<player1->GetPoints()<<" points."<<endl<<endl;

        }
        else
        {
            cout<<" NO SUCH FILE!!"<<endl;
        }


    //////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////                 HIGH SCORE                ///////////////////////////////////////////
        string userHighscoreAnswer;
        ifstream highscoreFile("highscore.txt");


        cout<<endl<< "Do you want to see the Highscore? ( Y / N )"<<endl;
        cin>>userHighscoreAnswer;

        if(userHighscoreAnswer == "y" || userHighscoreAnswer == "Y")
        {

            string tempFirstName, tempLastName,tempSkip;
            int tempScore;
            double tempScorePerncentage;
            int highscoreCounter =1;


            //LOAD ALL HIGH FROM FILE into linked list node
            while(!highscoreFile.eof())
            {
                getline(highscoreFile,tempFirstName);
                getline(highscoreFile,tempLastName);
                highscoreFile>>tempScore;
                highscoreFile>>tempScorePerncentage;
                getline(highscoreFile,tempSkip);
                Player* allPlayerScore = new Highscore;
                allPlayerScore->setFirstName(tempFirstName);
                allPlayerScore->setLastName(tempLastName);
                allPlayerScore->setPoints(tempScore);
                allPlayerScore->setScorePercentage(tempScorePerncentage);
                playerHighScore.insert(highscoreCounter,allPlayerScore);
                highscoreCounter = highscoreCounter + 1;
            }
            playerHighScore.sortedInsertDesc(player1);

            Player *showAllInfo;
            ofstream tempFile("temp.txt");

            cout<<endl;
            //cout<<"FIRST NAME"<<setw(20)<<"LAST NAME"<<setw(20)<<"SCORE"<<setw(20)<<"SCORE PERCENTAGE"<<endl;
            if(playerHighScore.getLength() <=10)
            {
                for(int z=1; z<=playerHighScore.getLength();z++)
                {
                    cout<<"**************************************************************************"<<endl;
                    showAllInfo = playerHighScore.retrieve(z);
                    cout<<"TOP "<<z<<": "<<endl;
                    cout<<"NAME: "<<showAllInfo->GetFirstName()<<" "<<showAllInfo->GetLastName()<<endl;
                    cout<<"SCORE: "<<showAllInfo->GetPoints()<<endl;
                    cout<<"SCORE PERCENTAGE: "<<showAllInfo->getscorePercentage()<<endl<<endl;
                    tempFile<<showAllInfo->GetFirstName()<<endl;
                    tempFile<<showAllInfo->GetLastName()<<endl;
                    tempFile<<showAllInfo->GetPoints()<<endl;
                    tempFile<<showAllInfo->getscorePercentage()<<endl;
                }
                cout<<"**************************************************************************"<<endl;
            }
            else
            {
                for(int z=1; z<=10;z++)
                {
                    cout<<"**************************************************************************"<<endl;
                    showAllInfo = playerHighScore.retrieve(z);
                    cout<<"TOP "<<z<<": "<<endl;
                    cout<<"NAME: "<<showAllInfo->GetFirstName()<<" "<<showAllInfo->GetLastName()<<endl;
                    cout<<"SCORE: "<<showAllInfo->GetPoints()<<endl;
                    cout<<"SCORE PERCENTAGE: "<<showAllInfo->getscorePercentage()<<"%"<<endl<<endl;
                    tempFile<<showAllInfo->GetFirstName()<<endl;
                    tempFile<<showAllInfo->GetLastName()<<endl;
                    tempFile<<showAllInfo->GetPoints()<<endl;
                    tempFile<<showAllInfo->getscorePercentage()<<endl;


                }
                cout<<"**************************************************************************"<<endl;
            }

            highscoreFile.close();
            tempFile.close();
            remove("highscore.txt");
            rename("temp.txt","highscore.txt");
        }
        else
        {
            if(userHighscoreAnswer != "n" || userHighscoreAnswer != "N")
            {
                cout<<"NO SUCH FILE!!!"<<endl<<endl;
            }
        }


        cout<<endl<<endl<<"THE QUIZ HAD ENDED !!"<<endl;
        cout<<"THANKS FOR PARTICIPATING!!"<<endl;




}
