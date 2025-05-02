#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<cctype>
#include<iomanip>
#include<climits>
#include<cstdlib>
#include<numeric>
#include<vector>
#include<utility>
#include<set>
#include<unordered_set>
#include<map>
#include<stack>
#include<queue>
#include<windows.h>
using namespace std;
#define ll long long
#define sortD(arr) sort(arr.rbegin(),arr.rend());
#define sortA(arr) sort(arr.begin(),arr.end());
namespace math
{
    bool prime(ll n)
    {
        if (n == 0 || n == 1 || (n % 2 == 0 && n != 2))
            return 0;
        else
            for (int i = 3; i <= sqrt(n); i += 2)
                if (n % i == 0)
                    return 0;
        return 1;
    }
    ll gcd(ll a, ll b)
    {
        ll ma = max(a, b), mn = min(a, b), mod;
        if (mn != 0)
            mod = ma % mn;
        else
            return ma;
        if (mod != 0)
        {
            while (mn % mod != 0)
            {
                ma = mn;
                mn = mod;
                mod = ma % mn;
            }
            return mod;
        }
        else
            return mn;
    }
    ll lcm(ll a, ll b)
    {
        return(a * b / gcd(a, b));
    }
    ll fact(ll a)
    {
        if (a == 1)return 1;
        return a * fact(a - 1);
    }
    int fibo(int a, int start)
    {
        if (a < start + 2)
            return a;
        return fibo(a - 1, start) + fibo(a - 2, start);
    }
    ll ceil(ll a, ll y)
    {
        return((a + y - 1) / y);
    }
    ll pOw(ll n, ll p)
    {
        ll tmp = n;
        if (!p)
            return 1;
        while (p - 1)
        {
            tmp *= n;
            p--;
        }
        return tmp;
    }
    bool even(ll x)
    {
        return(!(x % 2));
    }
    void Divisors(vector<ll>& arr, ll N)
    {
        for (int i = 1; i <= sqrt(N); i++)
            if (!(N % i))
            {
                arr.push_back(i);
                if ((N / i) != i)
                    arr.push_back(N / i);
            }
    }
    int Rand(int from, int to)
    {
        return(rand() % (to - from + 1) + from);
    }
}
using namespace math;
/* {
 first for background
 second for text
        0 = Black       8 = Gray
        1 = Blue        9 = Light Blue
        2 = Green       A = Light Green
        3 = Aqua        B = Light Aqua
        4 = Red         C = Light Red
        5 = Purple      D = Light Purple
        6 = Yellow      E = Light Yellow
        7 = White       F = Bright White
}*/

struct ExamDetails
{
    int NumberOfQuestions, QuestionsLevel, OperationType, CorrectAnswers, WrongAnswers;
    string S_OperationType, S_QuestionsLevel;
    ExamDetails()
    {
        NumberOfQuestions = 0;
        QuestionsLevel = 0;
        OperationType = 0;
        CorrectAnswers = 0;
        WrongAnswers = 0;
    }
};

enum Choice_QuestionsLevel { Easy = 1, Med, Hard };

enum Choice_OperationType { Add = 1, Sub, Mul, Div, Mix };

int ValidateIntNumber(int from, int to, string massage)
{
    int tmp;
    do
    {
        cout << massage;
        cin >> tmp;
    } while (tmp < from || tmp > to);
    return tmp;
}

void ReadNumberOfQuestions(int& NumberOfQuestions)
{
    NumberOfQuestions = ValidateIntNumber(1, 50, "How many questions do you want to answer ? ");
}

void ReadQuestionsLevel(int& QuestionsLevel)
{
    QuestionsLevel = ValidateIntNumber(1, 4, "Enter questions level [1] Easy, [2] Med, [3] Hard, [4] Mix ? ");
}

void ReadOperationType(int& OperationType)
{
    OperationType = ValidateIntNumber(1, 5, "Enter operation type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ? ");
    cout << endl;
}

int GenerateNumberATD(ExamDetails& Exam)
{
    switch (Exam.QuestionsLevel)
    {
    case Easy:
        Exam.S_QuestionsLevel = "Easy";
        return Rand(1, 10);
    case Med:
        Exam.S_QuestionsLevel = "Medium";
        return Rand(10, 99);
    case Hard:
        Exam.S_QuestionsLevel = "Hard";
        return Rand(100, 200);
    default:
        Exam.S_QuestionsLevel = "Mix";
        return Rand(1, 200);
    }
}

char GenerateOperationType(ExamDetails& Exam)
{
    int tmp = Exam.OperationType;
    bool f = 1;
    if (tmp == Mix)
    {
        f = 0;
        Exam.S_OperationType = "Mix";
        tmp = Rand(1, 4);
    }
    switch (tmp)
    {
    case Add:
        if (f)
            Exam.S_OperationType = "Addition";
        return '+';
    case Sub:
        if (f)
            Exam.S_OperationType = "Subtraction";
        return '-';
    case Div:
        if (f)
            Exam.S_OperationType = "Division";
        return '/';
    case Mul:
        if (f)
            Exam.S_OperationType = "Multiplication";
        return '*';
    }
}

int CalculateNumbers(int FirstNumber, int SecondNumber, int OperationType)
{
    switch (OperationType)
    {
    case '+':
        return FirstNumber + SecondNumber;
    case '-':
        return FirstNumber - SecondNumber;
    case '/':
        return FirstNumber / SecondNumber;
    default:
        return FirstNumber * SecondNumber;
    }
}

void CorrectTheAnswer(int UserAnswer, int CorrectAnswer, ExamDetails& Exam)
{
    if (UserAnswer == CorrectAnswer)
    {
        cout << "Right answer :-)";
        Exam.CorrectAnswers++;
        system("color 2f");
    }
    else
    {
        cout << "Wrong answer :-(\n";
        cout << "The right answer is :" << CorrectAnswer;
        Exam.WrongAnswers++;
        system("color 4f");
    }
    cout << "\n\n\n\n";
}

void StartExam(ExamDetails& Exam)
{
    int UserAnswer, CorrectAnswer, FirstNumber, SecondNumber;
    char OperationType;
    for (int i = 0; i < Exam.NumberOfQuestions; i++)
    {
        cout << "Question [" << i + 1 << "/" << Exam.NumberOfQuestions << "]\n\n";
        FirstNumber = GenerateNumberATD(Exam);
        SecondNumber = GenerateNumberATD(Exam);
        OperationType = GenerateOperationType(Exam);
        cout << FirstNumber << endl;
        cout << SecondNumber << ' ' << OperationType << "\n\n";
        cout << "_______________________\n";
        cin >> UserAnswer;
        CorrectAnswer = CalculateNumbers(FirstNumber, SecondNumber, OperationType);
        CorrectTheAnswer(UserAnswer, CorrectAnswer, Exam);
    }
}

string IsPassed(int CorrectAnswers, int WrongAnswers)
{
    if (CorrectAnswers >= WrongAnswers)
    {
        system("color 2f");
        return "PASS :-)";
    }
    system("color 4f");
    return "FAIL :-(";
}

void PrintFinalResults(ExamDetails Exam)
{
    cout << "__________________________________________________\n\n";
    cout << " Final result is " << IsPassed(Exam.CorrectAnswers, Exam.WrongAnswers);
    cout << "\n\n";
    cout << "__________________________________________________\n\n";
    cout << "Number of questions : " << Exam.NumberOfQuestions << '\n';
    cout << "Questions level     : " << Exam.S_QuestionsLevel << '\n';
    cout << "Operation Type      : " << Exam.S_OperationType << '\n';
    cout << "Number of right answers: " << Exam.CorrectAnswers << '\n';
    cout << "Number of wrong answers: " << Exam.WrongAnswers << endl;
    cout << "__________________________________________________\n\n";
}

void MakeExam()
{
    system("cls");
    system("color 07");
    ExamDetails Exam;
    char AnotherExam;
    ReadNumberOfQuestions(Exam.NumberOfQuestions);
    ReadQuestionsLevel(Exam.QuestionsLevel);
    ReadOperationType(Exam.OperationType);
    StartExam(Exam);
    PrintFinalResults(Exam);
    cout << "Do you want another exam ? Y/N ?";
    cin >> AnotherExam;
    if (tolower(AnotherExam) == 'y')
        MakeExam();
}

int main(void)
{
    MakeExam();





    return 0;
}