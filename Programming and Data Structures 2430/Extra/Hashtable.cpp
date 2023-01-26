#include <iostream>
#include <list>
using namespace std;

class Hashing {
    int hash_bucket;
    list <int> *hashtable;
public:
    Hashing(int V);
    void insert_key(int val);
    void delete_key(int val);
    int hashFunction(int x) {
        return(x % hash_bucket);
    }
    void displayHash(); };

Hashing::Hashing(int b) {
    this->hash_bucket = b;
    hashtable = new list<int>[hash_bucket];
}
void Hashing::insert_key(int key) {
    int index = hashFunction(key);
    hashtable[index].push_back(key);
}
void Hashing::delete_key(int key) {
    int index = hashFunction(key);
    list<int>::iterator i;
    for (i = hashtable[index].begin(); i != hashtable[index].end(); i++) {
        if (*i == key)
            break;
    }
    if (i != hashtable[index].end())
        hashtable[index].erase(i);
}
void Hashing::displayHash() {
    for (int i = 0; i < hash_bucket; i++) {
        cout << i;
        for (auto x : hashtable[i])
            cout << " --<< " << x;
            cout << endl;
    }
}
int main(int argc, char* argv[])
{
    int hash_array[] = { 11,12,21,14,15 };
    int n = sizeof(hash_array) / sizeof(hash_array[0]);
    Hashing h(7);
    for (int i = 0; i < n; i++) 
        h.insert_key(hash_array[i]);
    cout << "Hash table created:" << endl;
    h.displayHash();
    h.delete_key(12);
    cout << "Hash table after deletion of key 12:" << endl;
    h.displayHash();
}

