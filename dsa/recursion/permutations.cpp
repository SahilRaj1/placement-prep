/* TOPIC:  */

// TIME COMPLEXITY: O()
// SPACE COMPLEXITY: O()

// REFERENCE: 

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

void permutations(vector<int> &arr, vector<bool> &chosen, vector<int> &temp) {

    if (temp.size() == arr.size()) {
        ans.push_back(temp);
        return;
    }

    for (int i=0; i<arr.size(); i++) {
        if (!chosen[i]) {
            temp.push_back(arr[i]);
            chosen[i] = true;
            permutations(arr, chosen, temp);
            chosen[i] = false;
            temp.pop_back();
        }
    }

}

int main() {

    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i=0; i<n; i++) {
        cin>>arr[i];
    }

    vector<bool> chosen(n, false);
    vector<int> temp;
    permutations(arr, chosen, temp);

    for (auto &perm: ans) {
        cout<<"[ ";
        for (int &it: perm) {
            cout<<it<<" ";
        } cout<<"]"<<endl;
    }

    return 0;
}