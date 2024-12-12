#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool areIsomorphic(const vector<vector<int>>& adjMatrix1, const vector<vector<int>>& adjMatrix2, const vector<int>& permutation) {
    int n = adjMatrix1.size();
    vector<vector<int>> permutedMatrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            permutedMatrix[i][j] = adjMatrix1[permutation[i]][permutation[j]];
    return permutedMatrix == adjMatrix2;
}

bool checkIsomorphism(const vector<vector<int>>& adjMatrix1, const vector<vector<int>>& adjMatrix2) {
    int n = adjMatrix1.size();
    vector<int> permutation(n);
    for (int i = 0; i < n; i++) permutation[i] = i;
    do {
        if (areIsomorphic(adjMatrix1, adjMatrix2, permutation)) return true;
    } while (next_permutation(permutation.begin(), permutation.end()));
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adjMatrix1(n, vector<int>(n)), adjMatrix2(n, vector<int>(n));
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) cin >> adjMatrix1[i][j];
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) cin >> adjMatrix2[i][j];
    cout << (checkIsomorphism(adjMatrix1, adjMatrix2) ? "Yes" : "No") << endl;
    return 0;
}
