// Telco data check & query
#include <bits/stdc++.h>
using namespace std;

bool validatePhoneNumber(string phoneNumber)
{
    int lenPhoneNum = phoneNumber.length();
    if(lenPhoneNum!= 10)
        return false;
    for (int i=0; i<lenPhoneNum; i++)
    {
        if(phoneNumber[i] < '0' || phoneNumber[i]>'9')
            return false;
    }
    return true;
}

long calTimeCall(string s_time, string e_time)
{
    int hour = ((e_time[0] - '0') - (s_time[0]  - '0')) * 10 + ((e_time[1] - '0') - (s_time[1]  - '0'));
    int minutes = ((e_time[3] - '0') - (s_time[3]  - '0')) * 10 + ((e_time[4] - '0') - (s_time[4]  - '0'));
    int second = ((e_time[6] - '0') - (s_time[6]  - '0')) * 10 + ((e_time[7] - '0') - (s_time[7]  - '0'));
    return hour*3600 + minutes*60 + second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    map<string, int>  countCall, timeCall;

    string  instruct, f_number, t_number, date, s_time, e_time;
    long totalCall = 0;
    bool checkPhoneNumber = true;

    while(true)
    {
        cin >> instruct;
        if(instruct == "#")
            break;

        cin >> f_number >> t_number >> date >> s_time >> e_time;
        totalCall++;

        if(checkPhoneNumber && (!validatePhoneNumber(f_number) || !validatePhoneNumber(t_number)))
            checkPhoneNumber = false;

        if(countCall.find(f_number) != countCall.end())
            countCall[f_number]++;
        else
            countCall.insert(pair<string, int>(f_number, 1));

        if(timeCall.find(f_number) != timeCall.end())
            timeCall[f_number]+= calTimeCall(s_time, e_time);
        else
            timeCall.insert(pair<string, int>(f_number, calTimeCall(s_time, e_time)));
    }

    string query;
    while(true)
    {
        cin >> query;
        if(query == "?check_phone_number")
            printf("%d\n", checkPhoneNumber);
        else if(query == "?number_calls_from")
        {
                string phoneNumber;
                cin >> phoneNumber;
                printf("%d\n", countCall[phoneNumber]);
        }
        else if(query == "?number_total_calls")
            printf("%d\n", totalCall);
        else if(query == "?count_time_calls_from")
        {
                string phoneNumber;
                cin >> phoneNumber;
                printf("%d\n", timeCall[phoneNumber]);
        }
        else
            break;
    }
    return 0;
}
