#include <stdio.h>
#include <iostream>
#include <vector>
#include <iterator>
#include <map>
#include <cmath>

#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;

int32_t main()
{
    int items;
    cout << "Enter number of items present : ";
    cin >> items;
    cout << "Enter total weight of sack : ";
    int weight;
    cin >> weight;
    vector<int> p(items), w(items);

    cout << "Enter profits : ";
    for (int i = 0; i < items; i++)
    {
        cin >> p[i];
    }

    cout << "Enter weights : ";
    for (int i = 0; i < items; i++)
    {
        cin >> w[i];
    }

    multimap<double, int, greater<int>> map;
    double pDivW;
    for (int i = 0; i < items; i++)
    {
        pDivW = round(double(p[i]) / double(w[i]) * 100) / 100;
        map.insert(make_pair(pDivW, i));
    }

    cout << "Pi/Wi : index\n";
    double max_profit = 0;

    while (weight)
    {
        int index, key;
        double frac_weight;
        multimap<double, int>::iterator itr;
        itr = map.begin();

        while (itr != map.end())
        {
            cout << itr->first << " : " << itr->second << "\n";
            index = itr->second;
            key = itr->first;
            if (w[index] <= weight)
            {
                max_profit += p[index];
                weight -= w[index];
                itr++;
            }
            else
            {
                cout << weight << "\n\n";
                frac_weight = double(weight) /
                              double(w[index]);
                max_profit += (double(itr->first) * weight);
                weight -= weight;
                if (weight == 0)
                    break;
            }
        }
    }
    cout << "Maximum Profit : " << max_profit << endl
         << endl;
    return 0;
}
