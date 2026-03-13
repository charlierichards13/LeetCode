// Suppose we have some input data describing a graph of relationships between parents and children over multiple generations. 
// The data is formatted as a list of (parent, child) pairs, where each individual is assigned a unique positive integer identifier.


// For example, in this diagram, 6 and 8 have common ancestors of 4 and 14.


//               15
//              / \
//         14  13  21
//         |   |
// 1   2   4   12
// \ /   / | \ /
//  3   5  8  9
//   \ / \     \
//    6   7     11


// pairs = [
//    (1, 3), (2, 3), (3, 6), (5, 6), (5, 7), (4, 5),
//    (15, 21), (4, 8), (4, 9), (9, 11), (14, 4), (13, 12),
//    (12, 9), (15, 13)
// ]

// 3: [1,2]
// 4: [14]
// 6: [3,5,1,2,4,14]
// 8:[4,14]



// Write a function that takes this data and the identifiers of two individuals as inputs and returns true if and only if they share at least one ancestor.


// Sample input and output:


// hasCommonAncestor(pairs, 3, 8)   => false
// hasCommonAncestor(pairs, 5, 8)   => true
// hasCommonAncestor(pairs, 6, 8)   => true
// hasCommonAncestor(pairs, 6, 9)   => true
// hasCommonAncestor(pairs, 1, 3)   => false
// hasCommonAncestor(pairs, 3, 1)   => false
// hasCommonAncestor(pairs, 7, 11)  => true
// hasCommonAncestor(pairs, 6, 5)   => true
// hasCommonAncestor(pairs, 5, 6)   => true
// hasCommonAncestor(pairs, 3, 6)   => true
// hasCommonAncestor(pairs, 21, 11) => true


// n: number of pairs in the input




#include <vector>
#include <iostream>
#include <stack>

using namespace std;


class Solution {

public:
    int getMaxId(const vector<vector<int>>& pairs) {
        int maxId = 0;
        for (const auto& pair : pairs) {
            maxId = max(maxId, max(pair[0], pair[1]));
        }
        return maxId;
    }


    vector<vector<int>> buildParentList(const vector<vector<int>>& pairs, int maxId) {
       vector<vector<int>> parents(maxId + 1);

        for (const auto& p : pairs) {
            int parent = p[0];
            int child = p[1];
            parents[child].push_back(parent);
        }

        return parents;
    }


vector<bool> getAncestors(int person, const vector<vector<int>>& parents) {
        vector<bool> foundAncestor(parents.size(), false);
        stack<int> stack;
        stack.push(person);

        while (!stack.empty()) {
            int current = stack.top();
            stack.pop();

            for (int parent : parents[current]) {
                if (!foundAncestor[parent]) {
                    foundAncestor[parent] = true;
                    stack.push(parent);
                }
            }
        }

        return foundAncestor;
    }



    bool hasCommonAncestor(const vector<vector<int>>& pairs, int person1, int person2) {
        int maxId = getMaxId(pairs);
        vector<vector<int>> parents = buildParentList(pairs, maxId);

        vector<bool> ancestors1 = getAncestors(person1, parents);
        vector<bool> ancestors2 = getAncestors(person2, parents);

        for (int i = 0; i <= maxId; i++) {
            if (ancestors1[i] && ancestors2[i]) {
                return true;
            }
        }

        return false;
    }



};





int main() {

std::vector<std::vector<int>> pairs = {
    {1, 3}, {2, 3}, {3, 6}, {5, 6}, {5, 7}, {4, 5},
    {15, 21}, {4, 8}, {4, 9}, {9, 11}, {14, 4}, {13, 12},
    {12, 9}, {15, 13}
};



Solution sol;

    cout << boolalpha;
    cout << sol.hasCommonAncestor(pairs, 3, 8) << endl;   // false
    cout << sol.hasCommonAncestor(pairs, 5, 8) << endl;   // true
    cout << sol.hasCommonAncestor(pairs, 6, 8) << endl;   // true
    cout << sol.hasCommonAncestor(pairs, 6, 9) << endl;   // true
    cout << sol.hasCommonAncestor(pairs, 1, 3) << endl;   // false
    cout << sol.hasCommonAncestor(pairs, 3, 1) << endl;   // false
    cout << sol.hasCommonAncestor(pairs, 7, 11) << endl;  // true
    cout << sol.hasCommonAncestor(pairs, 6, 5) << endl;   // true
    cout << sol.hasCommonAncestor(pairs, 5, 6) << endl;   // true
    cout << sol.hasCommonAncestor(pairs, 3, 6) << endl;   // true
    cout << sol.hasCommonAncestor(pairs, 21, 11) << endl; // true


    // finish after prints
    return 0;



}