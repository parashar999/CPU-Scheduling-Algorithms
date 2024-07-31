#include <bits/stdc++.h>
using namespace std;

bool compare(pair<string, pair<int, int>> x, pair<string, pair<int, int>> y) {
    if (x.second.first != y.second.first) {
        return x.second.first < y.second.first;
    }
    return x.second.second < y.second.second;
}

bool compare2(pair<string, pair<int, int>> x, pair<string, pair<int, int>> y)
{
    return x.first<y.first;
}

int main() {
    int n = 0;
    vector<pair<string, pair<int, int>>> process;
    vector<int> completion_time;
    vector<int> waiting_time;
    vector<int> response_time;
    vector<int> tat;

    cout << "Enter the total Number of Process: ";
    cin >> n;
    cout << endl;
    cout << "Provide pairs of arrival time and burst time of Processes " << endl;
    for (int i = 0; i < n; i++) {
        string str = "P" + to_string(i);
        int x;
        cin >> x;
        int y;
        cin >> y;
        pair<int, int> p;
        p.first = x;
        p.second = y;
        process.push_back(make_pair(str, p));
    }

    sort(process.begin(), process.end(), compare);
    int time = 0;
    pair<string, pair<int, int>> execution_memory;
    execution_memory.first = "";
    execution_memory.second.first = INT_MAX;
    execution_memory.second.second = INT_MAX;
    vector<pair<string, pair<int, int>>> v;
    vector<pair<string, pair<int, int>>> waiting_memory;
    int i = 0;

    while (i < process.size() || !waiting_memory.empty() || execution_memory.second.second >0) 
    {
        if (i < process.size() && time == process[i].second.first) {
            while (i < process.size() && time == process[i].second.first) 
            {
                waiting_memory.push_back(process[i]);
                i++;
            }
        }
        
        sort(waiting_memory.begin(), waiting_memory.end(), compare);

        if (execution_memory.second.second == INT_MAX && !waiting_memory.empty()) {
            execution_memory = waiting_memory.front();
            waiting_memory.erase(waiting_memory.begin());
        }

        if (execution_memory.second.second == 0) {
            execution_memory.second.second = time;
            v.push_back(execution_memory);
            if (waiting_memory.empty()) 
            {
                execution_memory.first = "";
                execution_memory.second.first = INT_MAX;
                execution_memory.second.second = INT_MAX;
            } 
            else 
            {
                execution_memory = waiting_memory.front();
                waiting_memory.erase(waiting_memory.begin());
            }
        }

        if (execution_memory.second.second != INT_MAX) {
            execution_memory.second.second--;
        }
        time++;
    }
    execution_memory.second.second = time;
    v.push_back(execution_memory);
    sort(v.begin(),v.end(),compare2);
    sort(process.begin(),process.end(),compare2);
    cout << endl;
    cout << "Column 1 is for Arrival time" <<endl;
    cout << "Column 2 is for Burst time" <<endl;    
    cout << "Column 3 is for Completion time" <<endl;
    cout << "Column 4 is for Turn Around Time" <<endl;
    cout << "Column 5 is for Waiting Time" <<endl;
    cout << "Column 6 is for Response time" <<endl;
    cout << endl ;
    for (int i = 0; i < v.size(); i++) {
        completion_time.push_back(v[i].second.second);
        tat.push_back(v[i].second.second-v[i].second.first);
        waiting_time.push_back(tat[i]-process[i].second.second);
        response_time.push_back(tat[i]-process[i].second.second);
        cout << v[i].first << " " << process[i].second.first << " " << process[i].second.second << " " << completion_time[i]  << " " << tat [i]<< " " << waiting_time[i] <<  " " << response_time[i]<< endl; 
    }
}
