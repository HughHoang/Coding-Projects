#include <iostream>
#include <queue>

using namespace std;

float distFromOrigin(pair<int,int> coord)
{
    return sqrt(pow(coord.first, 2) + pow(coord.second, 2));
}

struct ComparisonStruct {
    bool operator() (pair<int,int> coordOne, pair<int,int> coordTwo) {
        return distFromOrigin(coordOne) > distFromOrigin(coordTwo);
    }
};

pair<int, int> findKthSmallest(vector<pair<int, int>> coordinates, int k)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, ComparisonStruct> pq;
    
    for (auto coord : coordinates)
    {
        pq.push(coord);
    }
    
    for (int i = 0; i < k - 1; i++)
    {
        pq.pop();
    }
    
    return pq.top();
}

int main()
{
    int k = 3;
    vector<pair<int, int>> coordinates;
    
    coordinates.push_back(make_pair(4, 6));
    coordinates.push_back(make_pair(2, 3));
    coordinates.push_back(make_pair(1, 1));
    coordinates.push_back(make_pair(1, 2));
    
    pair<int, int> smallest = findKthSmallest(coordinates, k);
    
    cout << "(" << smallest.first << ", " << smallest.second << ")" << endl;
    
    return 0;
}
