# include <bits/stdc++.h>
using namespace std;

int main()
{
    int n=0;
    vector<int> arrival_time;
    vector<int> burst_time;
    vector<int> completion_time;
    vector<int> waiting_time;
    vector<int> response_time;
    vector<int> tat;

    cout << "Enter the total Number of Process : " ;
    cin >> n;
    cout << endl;
    cout << "Provide an array of Arrival Time of Processes in their arrival order : " << endl;
    for( int i=0 ; i<n; i++)
    {
        int a;
        cin >> a;
        arrival_time.push_back(a);
    }

    cout << "Provide an array of Burst Time of Processes in their arrival order : " << endl;
    for(int i=0; i<n; i++)
    {
        int a;
        cin>> a;
        burst_time.push_back(a);
    }

    //calculating completion time

    int time=0;
    for(int i=0; i<n; i++)
    {
        if(i==0)
        {
            time+=burst_time[0];
        }
        else
        {
            if(arrival_time[i]<time)
            {
                time+=burst_time[i];
            }
            else
            {
                time=arrival_time[i]+burst_time[i];
            }
        }
        completion_time.push_back(time);

        // Turn Around Time Calculation
        tat.push_back(completion_time[i]-arrival_time[i]);

        // Waiting Time Calculation
        waiting_time.push_back(tat[i]-burst_time[i]);

        // Response Time Calculation
        response_time.push_back(waiting_time[i]);
    }
    cout << endl;
    cout << "Column 1 is for Arrival time" <<endl;
    cout << "Column 2 is for Burst time" <<endl;    
    cout << "Column 3 is for Completion time" <<endl;
    cout << "Column 4 is for Turn Around Time" <<endl;
    cout << "Column 5 is for Waiting Time" <<endl;
    cout << "Column 6 is for Response time" <<endl;
    cout << endl;
    
    for(int i=0; i<n; i++)
    {
        cout << "P(" << i << ") :  " << completion_time[i] << " " << tat[i] << " " << waiting_time[i] << " " << response_time[i] << endl;
    }
}