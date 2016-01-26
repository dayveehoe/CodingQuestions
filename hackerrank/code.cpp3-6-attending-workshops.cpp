#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops

struct Workshop {
    int start;
    int duration;
    int end;
};

struct Available_Workshops {
    int N;
    vector<Workshop> workshops;
};

Available_Workshops * initialize (int start_time[ ], int duration[ ], int N)  {
    Available_Workshops * avail = new Available_Workshops;
    Workshop w;

    avail->N = N;

    // Build Available Workshops
    for (int i = 0 ; i < N ; i++) {
        w.start = start_time[i];
        w.duration = duration[i];
        w.end = start_time[i] + duration[i];
        avail->workshops.push_back(w);
    }

    // Sort Workshops by end time
    sort(avail->workshops.begin(),
         avail->workshops.end(),
         [](Workshop a, Workshop b) {
            return (a.end < b.end);
        });

    return avail;
}

int CalculateMaxWorkshops (Available_Workshops * avail) {
    // Determine overlap_forward.
    int N = avail->N;
    int No_overlaps = 0;
    int finish = 0;

    for (auto w : avail->workshops) {
        cout << "Start " << w.start << " Dur " << w.duration << " End " << w.end << endl;
    }

    // Greedy algo, check finish times instead
    for (int i = 0 ; i < N ; i++) {
        if (finish <= avail->workshops[i].start) {
            finish = avail->workshops[i].end;
            No_overlaps++;
        }
    }

    return No_overlaps;
}




int main()
{
    int n;
    cin>>n;
    int start_time[n],duration[n];
    for(int i=0;i<n;i++)
    {
        cin>>start_time[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>duration[i];
    }

    Available_Workshops * ptr;
    ptr=initialize(start_time,duration,n);
    cout<<CalculateMaxWorkshops(ptr)<<endl;
    return 0;
}

