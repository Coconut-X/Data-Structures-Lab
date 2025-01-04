#include<iostream>
#include<fstream>
#include<string>
using namespace std;


int main()
{
    fstream myfile; //fstream is class and myfile is object, or we can say myfile is a variable of type fstream
    //ofstream is used to write to file, ifstream is used to read from file, fstream is used to read and write to file
    //so just use fstream to read and write to file inseatd of using ifstream and ofstream

    //now we have to write some text in file, we will first open it

    myfile.open("file.txt", ios::out); 
    //WE HAVE THREE MODES TO OPEN FILE
    //ios::in - open file for reading
    //ios::out - open file for writing
    //ios::app - open file for appending


    //IF YOU OPEN A FILE HAVING DATA IN IT IN ios::out MODE, IT WILL DELETE ALL THE DATA IN FILE AND THEN OPEN IT
    //SO ALWAYS USE APPEND WHEN YOU WANT TO CONTINUE WRITING IN FILE

    //MOREOVER, IOS OUT WILL CREATE A NEW FILE IF FILE DOES NOT EXIST (IN THE SAME FOLDER WHERE YOUR CODE IS LOCATED)
    //BUT APPEND WILL NOT CREATE A NEW FILE IF FILE DOES NOT EXIST

    //SIMILARLY AS WE USE COUT IN IOSTREAM, WHICH MEANS COUT OR CIN IS A OBJECT OF IOSTREAM CLASS WHICH IS USED TO READ OR WRITE TO CONSOLE
    //BUT NOW WE HAVE TO READ OR WRITE TO FILE, SO WE WILL USE OBJECT OF FSTREAM CLASS

cout<<"\n\nWRITING TEXT TO FILE\n";

    //WRITING TEXT TO FILE
    if(myfile.is_open()) //NO NEED TO CHECK IF FILE EXISTS OR NOT, IT WILL CREATE A NEW FILE IF FILE DOES NOT EXIST                
    {                    //BUT CHECK IN READ AND APPEND MODE
        myfile<<"Hello World\n";
        myfile<<"This is a file\n";
        myfile<<"This is a new line\n";
        myfile.close();  //ALWAYS CLODE THE FILE AFTER WRITING TO IT, ELSE IT WILL NOT SAVE THE DATA
    }
    else
    {
        cout<<"File not opened\n";
    }



    //NOW GO TO THE FOLDER WHERE THIS FILE IS LOCATED AND OPEN IT, YOU WILL SEE THE TEXT WRITTEN IN IT

    //NOW LETS READ THE FILE, WE HAVE ALREADY MADE A FILE OBJECT, SO WE WILL USE IT TO READ THE FILE
    

    //LETS OPEN IT IN READ MODE

    myfile.open("file.txt", ios::in); //OPENING FILE IN READ MODE

    //READING TEXT FROM FILE


    //METHOD 1: USING STRING AND GETLINE FUNCTION

    cout<<"\n\nREADING TEXT FROM FILE USING GETLINE\n";

    string line;

    if(myfile.is_open())
    {
        while(getline(myfile, line)) //GETLINE FUNCTION WILL READ THE FILE LINE BY LINE, IT WILL AUTOMATICALLY STOP READING WHEN IT REACHES END OF FILE
        {                            //AND AUTOMATICALY GOES TO NEXT LINE, THIS WILL BE PROVED LATER 
            cout<<line<<endl;
        }
    
        myfile.close();
    }
    else
    {
        cout<<"File not opened\n";
    }


    //METHOD 2: USING >> OPERATOR
    cout<<"\n\nREADING TEXT FROM FILE WORD BY WORD USING >> OPERATOR\n";


    myfile.open("file.txt", ios::in); //OPENING FILE IN READ MODE

    string word;
    myfile>>word; //THIS WILL READ THE FIRST WORD IN FILE, IT WILL STOP READING WHEN IT REACHES SPACE OR NEW LINE
    cout<<word<<endl; //now the buffer is pointing to the next word in file

    myfile>>word; //THIS WILL READ THE SECOND WORD IN FILE
    cout<<word<<endl; //now the buffer is pointing to the next word in file

    myfile.close();

    //METHOD 3: USING CHAR

    cout<<"\n\nREADING TEXT FROM FILE CHARACTER BY CHARACTER USING CHAR AND GET\n";

    myfile.open("file.txt", ios::in); //OPENING FILE IN READ MODE

    char ch;

    if(myfile.is_open())
    {
        while(myfile.get(ch)) //GET FUNCTION WILL READ THE FILE CHARACTER BY CHARACTER, IT WILL AUTOMATICALLY STOP READING WHEN IT REACHES END OF FILE
        {                            //AND AUTOMATICALY GOES TO NEXT CHARACTER, THIS WILL BE PROVED LATER 
            cout<<ch;
        }
    
        myfile.close();
    }
    else
    {
        cout<<"File not opened\n";
    }


    //METHOD 4: USING rdbuff FUNCTION, ONE OF THE BEST METHOD

    cout<<"\n\nREADING TEXT FROM FILE USING rdbuf FUNCTION\n";

    myfile.open("file.txt", ios::in); //OPENING FILE IN READ MODE

    cout<<myfile.rdbuf(); //THIS WILL READ THE WHOLE FILE AND PRINT IT, IT WILL AUTOMATICALLY STOP READING WHEN IT REACHES END OF FILE

    myfile.close();


    //NOW LETS APPEND SOME TEXT TO FILE

    cout<<"\n\nAPPENDING TEXT TO FILE\n";

    myfile.open("file.txt", ios::app); //OPENING FILE IN APPEND MODE

    if(myfile.is_open())
    {
        myfile<<"This is appended text\n";
        myfile.close();
    }
    else
    {
        cout<<"File not opened\n";
    }

    //NOW LETS READ THE FILE AGAIN using rdbuff

    cout<<"\n\nREADING TEXT FROM FILE AFTER APPENDING USING rdbuf FUNCTION\n";

    myfile.open("file.txt", ios::in); //OPENING FILE IN READ MODE

    cout<<myfile.rdbuf();

    myfile.close();

    //THERE IS ONE MORE MODE IOS:TRUNC, IT WILL DELETE ALL THE DATA IN FILE AND OPEN IT, SO BE CAREFUL WHILE USING IT, (IT WILL NOT DELETE THE FILE JUST THE DATA)
    //YEA IT IS SIMILAR TO IOS:OUT, BUT IT WILL NOT CREATE A NEW FILE IF FILE DOES NOT EXIST

    //NOW LETS TRUNCATE THE FILE

    cout<<"\n\nTRUNCATING THE FILE\n";

    myfile.open("file.txt", ios::trunc); //OPENING FILE IN TRUNC MODE

    //NOW LETS READ THE FILE AGAIN using rdbuff

    cout<<"\n\nREADING TEXT FROM FILE AFTER TRUNCATING USING rdbuf FUNCTION\n";

    myfile.open("file.txt", ios::in); //OPENING FILE IN READ MODE

    cout<<myfile.rdbuf();

    myfile.close();

    cout<<"AS YOU CAN SEE, THE FILE IS EMPTY NOW\n";


    //NOW LETS DELETE THE FILE

    cout<<"\n\nDELETING THE FILE\n";

    remove("file.txt"); //THIS WILL DELETE THE FILE

    cout<<"FILE DELETED\n";

    //TRY TO OPEN THE FILE NOW, WITH IF STATEMENT

    myfile.open("file.txt", ios::in); //OPENING FILE IN READ MODE

    if(myfile.is_open())
    {
        cout<<"File opened\n";
    }
    else
    {
        cout<<"File not opened\n";
    }

    return 0;
}