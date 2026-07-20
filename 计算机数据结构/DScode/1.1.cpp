#include <iostream>
#include <algorithm>
using namespace std;

struct student
{
    int id;
    string name;
    int score;
};

bool  cmp(student &a, student &b)
{
    return a.id < b.id;
}
int main()
{
    int n;
    cin >> n;
    student s[1001];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i].id >> s[i].name >> s[i].score;
    }
    int failCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i].score < 60)
        {
            failCount++;
        }
    }
    cout << "Fail Count: " << failCount << endl;
        sort(s, s + n, cmp);
    for (int i = 0; i < n; i++){
        if (s[i].score < 60)
        {
            cout << s[i].id << " " << s[i].name << " " << s[i].score << endl;
        }  
    }
    return 0;
}
