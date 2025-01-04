#include<iostream>
#include<string>
#include<vector>

using namespace std;


class stack
{
    public:
    vector<string> infix;
    vector<string> postfix;
    vector<string> intermediate;
    vector<string> eval;
    double r=0;

    void stringToInfix(string str)
    {
        //push each character of string to infix vector, check the numbers for multiple digits and then push them as a single number
        string temp = "";
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] >= '0' && str[i] <= '9')
            {
                temp += str[i];
            }
            else
            {
                if (temp != "")
                {
                    infix.push_back(temp);
                    temp = "";
                }
                infix.push_back(string(1, str[i]));
            }
        }

        if (!temp.empty())  ///check for any last left number
            infix.push_back(temp);
    }

    void displayInfix()
    {
        for (int i = 0; i < infix.size(); i++)
            cout << infix[i];
    }

    void displayPostfix()
    {
        //if end of infix is not a number, display incorrect expression
        if (infix[infix.size() - 1] == "+" || infix[infix.size() - 1] == "-" || infix[infix.size() - 1] == "*" || infix[infix.size() - 1] == "/" || infix[infix.size() - 1] == "%" || infix[infix.size() - 1] == "(")
        {
            cout << "Incorrect Expression";
            return;
        }

        for (int i = 0; i < postfix.size(); i++)
            cout << postfix[i];
    }

    void infixToPostfix()
    {
        if(infix.empty())
        {
            cout<<"Empty infix expression";
            return;
        }

        if(infix.size()==1)
        {
            cout<<"Postfix: "<<infix[0];
            cout<<endl<<"Result: "<<infix[0];
            return;
        }

        for(int i=0;i<infix.size();i++)
        {           
            //if infix is not operator or bracket, means it is an operand or number
            if(infix[i]!="+" && infix[i]!="-" && infix[i]!="*" && infix[i]!="/" && infix[i]!="(" && infix[i]!=")" && infix[i]!="%")
            {
                postfix.push_back(infix[i]);
            }

            //if open bracket, push it to stack
            if(infix[i]=="(")
            {
                intermediate.push_back(infix[i]);
            }

            ///we pop from stack and push it to postfix on three conditions
				///	1. jb dono(top of stack and new operator ) ki precedence same ho e.g: +,- or -,+ or *,/ or /,*
				/// 2. jb dono operators same hon e.g: +,+ etc
				/// 3. aglay(new li) ki precedence kum ho 

            else if(infix[i]=="+" || infix[i]=="-" )
            {
                ///if empty stack or top of stack is "("
                if(intermediate.empty() || intermediate.back()=="(")
                {
                    intermediate.push_back(infix[i]);
                }
                else if(intermediate.back()=="+" || intermediate.back()=="-" || intermediate.back()=="*" || intermediate.back()=="/")
                {
                    //keep popping and pushing until precedence of new operator is less than top of stack
                    while(intermediate.back()=="+" || intermediate.back()=="-" || intermediate.back()=="*" || intermediate.back()=="/")
                    {
                        postfix.push_back(intermediate.back());
                        intermediate.pop_back();
                    }
                    intermediate.push_back(infix[i]); ///push new operator to stack
                }
                else
                {
                    intermediate.push_back(infix[i]);
                }
              
            }

            ///for * and /
            else if(infix[i]=="*" || infix[i]=="/")
            {
                if(intermediate.empty() || intermediate.back()=="(")
                {
                    intermediate.push_back(infix[i]);
                }
                else if(intermediate.back()=="*" || intermediate.back()=="/")
                {
                    while(intermediate.back()=="*" || intermediate.back()=="/")
                    {
                        postfix.push_back(intermediate.back());
                        intermediate.pop_back();
                    }
                    intermediate.push_back(infix[i]);
                }
                else
                {
                    intermediate.push_back(infix[i]);
                }
            }

             ///for modulo
            else if(infix[i]=="%")
            {
                if(intermediate.empty() || intermediate.back()=="(")
                {
                    intermediate.push_back(infix[i]);
                }
                else if(intermediate.back()=="%" )
                {
                    while(intermediate.back()=="%")
                    {
                        postfix.push_back(intermediate.back());
                        intermediate.pop_back();
                    }
                    intermediate.push_back(infix[i]);
                }
                else
                {
                    intermediate.push_back(infix[i]);
                }
            }


            else if(infix[i]=="(") //simply push "(" to stack
            {
                intermediate.push_back(infix[i]);
            }

            else if(infix[i]==")")  ///pop until "(" inclusive
            {
                while(intermediate.back()!="(")
                {
                    //if size of stack is 1 and "(" is not found, means incorrect expression
                    if(intermediate.size()==1)
                    {
                        cout<<"Incorrect Expression :(";
                        return;
                    }

                    postfix.push_back(intermediate.back());
                    intermediate.pop_back();
                }
                    intermediate.pop_back(); ///pop "("
            }
            
        }

        //push remaining stack to postfix
        while(!intermediate.empty())
        {
            postfix.push_back(intermediate.back());
            intermediate.pop_back();
        }

        cout<<"Postfix: ";
        displayPostfix();
        evaluate();

    }

    void evaluate()
    {
        double result = 0;
        string a, b;

        for (int i = 0; i < postfix.size(); i++)
        {

            if (!(postfix[i] == "+" || postfix[i] == "-" || postfix[i] == "*" || postfix[i] == "/"))
            {
                eval.push_back(postfix[i]); ///if not an operator push 
            }

            else if(postfix[i] == "+" || postfix[i] == "-" || postfix[i] == "*" || postfix[i] == "/" || postfix[i] == "%")
            {
                double f = stod(eval.back());
                eval.pop_back();
                double s = stod(eval.back());
                eval.pop_back();
                
                if (postfix[i] == "+")
                {
                    result = s + f;
                }
                else if (postfix[i] == "-")
                {
                    result = s - f;
                }
                else if (postfix[i] == "*")
                {
                    result = s * f;
                }
                else if (postfix[i] == "/")
                {
                    if(f==0)
                    {
                        cout<<"Division by zero not allowed";
                        return;
                    }

                    result = s / f;
                }
                else if (postfix[i] == "%")
                {
                    //typecast to int
                    int ss = s;
                    int ff = f;
                    result = ss % ff;
                }
                ///push it to eval array
                eval.push_back(to_string(result));
            } 
        }

        cout <<endl<<"Result: "<< result<<endl;
        r=result;
    }
    
};


void separate(string boolean, string &left, string &right, string &op1,string &op2)
{
    int i=0;
    while(i<boolean.length() && ( boolean[i]!='=' && boolean[i]!='>' && boolean[i]!='<' && boolean[i]!='!'))
    {
        left+=boolean[i];
        i++;
    }

    op1=boolean[i];
    //check for second operator if any
    if(boolean[i+1]=='=' || boolean[i+1]=='>' || boolean[i+1]=='<' || boolean[i+1]=='!' || boolean[i+1]=='<=' || boolean[i+1]=='>=')
    {
        op2=boolean[i+1];
        i++;
    }

    i++;

    while(i<boolean.length())
    {
        right+=boolean[i];
        i++;
    }
}


int main()
{

    stack s;
    //s.stringToInfix("2*3+14/70");
    //s.stringToInfix("((a+((b-c)*((d/e)/f)))-(g*(h+i)))");
    //s.stringToInfix("1+3*(6+4/2)-3/(1-1)");
    cout<<endl;
    s.stringToInfix("1/(3-3)");
    s.infixToPostfix();

    // take string to find true or false expression, 
    cout<<endl<<endl;
    string boolean="1+2*2!=4";

    string left="";
    string right="";
    string op1="";
    string op2=" ";
    separate(boolean,left,right,op1,op2);

    stack s1;
    s1.stringToInfix(left);
    s1.infixToPostfix();

    stack s2;
    s2.stringToInfix(right);
    s2.infixToPostfix();


    cout<<endl;

    if(op1==">" and op2==" ")
    {
        if(s1.r>s2.r)
            cout<<"True";
        else
            cout<<"False";
    }

    else if (op1=="<" and op2==" ")
    {
        if(s1.r<s2.r)
            cout<<"True";
        else
            cout<<"False";
    }

    else if (op1=="=" and op2==" ")
    {
        if(s1.r==s2.r)
            cout<<"True";
        else
            cout<<"False";
    }

    else if (op1=="!" and op2=="=")
    {
        if(s1.r!=s2.r)
            cout<<"True";
        else
            cout<<"False";
    }

    else if (op1=="<" and op2=="=")
    {
        if(s1.r<=s2.r)
            cout<<"True";
        else
            cout<<"False";
    }

    else if (op1==">" and op2=="=")
    {
        if(s1.r>=s2.r)
            cout<<"True";
        else
            cout<<"False";
    }


    return 0;
}