#include "StringMatching.h"
int BF(const char *MainString, const char *SubString)
{
    int result = -1;
    int MainStringLength = strlen(MainString);
    int SubStringLength = strlen(SubString);
    int i = 0, j = 0;
    while (i < MainStringLength && j < SubStringLength)
    {
        if (MainString[i] == SubString[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j >= SubStringLength)
    {
        result = i - j;
        cout << "substring matching succeed!" << endl;
        cout << MainString << endl;
        for (int i = 0; i < result; i++)
        {
            cout << " ";
        }
        for (int i = 0; i < SubStringLength; i++)
        {
            cout << "^";
        }
    }
    else
    {
        cerr << "substring matching failed!" << endl;
    }
    return 1;
}
void StringTest(void)
{
    const char *s1 = "举世皆浊我独清，世人皆醉我独醒!";
    const char *s2 = "世人";
    BF(s1, s2);
}