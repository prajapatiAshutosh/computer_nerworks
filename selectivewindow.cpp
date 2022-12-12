// WAP to implement selective repeat sliding window.

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int protocol(int nf, int N){
    int no_tr = 0;
    int i = 0;
    while (i < nf)
    {
        int x = 0;
        for (int j = i; j < i + N && j < nf; j++)
        {
            cout << "Sent Frame " << j << endl;
            no_tr++;
        }
        for (int j = i; j < i + N && j < nf; j++)
        {
            int flag = rand() % 2;
            if (!flag)
            {
                cout << "Acknowledgment for Frame " << j << endl;
                x++;
            }
            else
            {
                cout << "Frame " << j << " Not Received" << endl;
                v.push_back(j);
                x++;
            }
        }
        cout << endl;
        i += x;
    }
    return no_tr;
}
void sendRemaining(int &no_tr, int N)
{
    int i = 0, nf = v.size();
    while (i < nf)
    {
        for (int j = i; j < v.size() && j < i + N; j++)
        {
            cout << "Sent Frame " << v[j] << endl;
            no_tr++;
        }
        for (int j = i; j < v.size() && j < i + N; j++)
        {
            int flag = rand() % 2;
            if (!flag)
            {
                cout << "Acknowledgment for Frame " << v[j] << endl;
                v[j] = -999;
            }
            else
            {
                cout << "Frame " << v[j] << " Not Received" << endl;
            }
        }
        cout << endl;
        i += N;
    }
    auto it = remove_if(v.begin(), v.end(), [](const int j)
                        { return j < 0; });

    v.erase(it, v.end());
}
int main()

{
    int nf, N, no_tr;
    char choice;
    srand(time(NULL));
    cout << "Enter the number of frames : ";
    cin >> nf;
    cout << "Enter the Window Size : ";
    cin >> N;
    no_tr = protocol(nf, N);
    while (v.size() > 0)
    {
        cout << "Do you want to retransmitt remaining frames? Enter 'Y' or 'y' for yes" << endl;
        cin >> choice;
        if (choice == 'Y' || choice == 'y')
        {
            sendRemaining(no_tr, N);
        }
        else
            break;
    }
    cout << "Total number of transmissions : " << no_tr << endl;
    return 0;
}
