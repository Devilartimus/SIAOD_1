#include <iostream>
#include <fstream>

#define MAX_STACK_SIZE 50

using namespace std;

int t;
char stack[MAX_STACK_SIZE];
char prev1 = NULL;
char prev2 = NULL;
void init();    //done
void Push(char);    //done
char Pop(); //done
char Top(); //done
bool IsEmpty(); //done
void read(ifstream* fin);   //done
void print(ofstream* fout); //done


int main()
{
    ofstream fout;  //файл вывода
    fout.open("E:/3 term/SIAOD/lab2/fin.txt");
    if (!fout.is_open())
        cout << "Errror! File can't be opened\n\n";

    ifstream fin;   //файл ввода
    fin.open("E:/3 term/SIAOD/lab2/start.txt");
    if (!fin.is_open())
        cout << "Errror! File can't be opened\n\n";
    else
    {
        init();
        while(!fin.eof())
        {
            read(&fin);
            print(&fout);
        }
    }

    return 0;
}

void read(ifstream* fin)
{
    char a, b, buf=0;
    while(1)
    {
        if(prev1 == NULL && prev2 == NULL)
        {
            fin -> get(a);
            if (a == ' ')
            {
                fin -> get(a);
            }

            fin -> get(b);
            if (b == ' ')
            {
                fin -> get(b);
            }
        }
        else if (prev1 != NULL && prev2 != NULL)
        {
            a = prev1;
            prev1 = NULL;
            b = prev2;
            prev2 = NULL;
        }
        else if (prev1 != NULL && prev2 == NULL)
        {
            a = prev1;
            prev1 = NULL;
            fin -> get(b);
            if (b == ' ')
            {
                fin -> get(b);
            }
        }


        if(a < b && buf < a)
        {
            Push(a);
            Push(b);
            buf = b;
        }
        else if (buf > a && a < b)
        {
            prev1 = a;
            prev2 = b;
            break;
        }
        else if( buf < a && a > b)
        {
            Push(a);
            prev1 = b;
            prev2 = NULL;
            break;
        }
    }
}

void print(ofstream* fout)
{
    char a;
    while(!IsEmpty())
    {
        a = Pop();
        cout << a << " ";
        *fout << a << " ";
    }
    cout << endl;
    *fout << endl;
}

void init() {t=-1;}

bool IsEmpty() {return(t==-1);}

char Top()
{
    if(!IsEmpty())
        return (stack[t]);
    else
        return EOF;
}

void Push(char a)
{
    if (t!=MAX_STACK_SIZE)
    {
        stack[++t]=a;
    }
    else
    {
        cout << "Atempt to Push() to full stack" << endl << t << endl;
    }
}

char Pop()
{
    char a;
    if (!IsEmpty())
    {
        a = stack[t];
        stack[t] = NULL;
        --t;
        return a;
    }
    else
    {
        cout << "Atempt to Pop() from empty stack" << endl;
        return EOF;
    }
}
