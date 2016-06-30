//
//  Backtracking.cpp
//  testsing
//
//  Created by J Andrew McCormick on 6/29/16.
//  Copyright © 2016 J Andrew McCormick. All rights reserved.
//

#include "Backtracking.hpp"

using namespace std;

vector<int> *uniqueValues(vector<int> givenValues, vector<int> valuesToExclude)
{
    vector<int> *temp = new vector<int>();
    
    int givenValuesIndex = 0;
    int valuesToExcludeIndex = 0;
    
    while (givenValuesIndex < givenValues.size())
    {
        if (!valuesToExclude.empty())
            if(givenValues[givenValuesIndex] == valuesToExclude[valuesToExcludeIndex])
            {
                givenValuesIndex++;
                valuesToExcludeIndex++;
                continue;
            }
        
        if (find(temp->begin(), temp->end(), givenValues[givenValuesIndex]) == temp->end())
        {
            temp->push_back(givenValues[givenValuesIndex]);
            givenValuesIndex++;
        }
        else
        {
            givenValuesIndex++;
        }
    }
    return temp;
}

vector<int> *findZeroSolution(vector<int> givenValues)
{
    node *root = new node();
    root->value = 0;
    
    vector<int> *x = recursiveMethod(root, givenValues, givenValues);
    x->erase(x->begin());
    
    return x;
}

int maxVal = 144;

vector<int> *recursiveMethod(node *currentNode, vector<int> givenValues, vector<int> fullValues)
{
    int sum = 0;
    for (int i = 0; i < currentNode->solution.size(); i++)
    {
        sum += currentNode->solution[i];
    }
    
    if (sum > maxVal) return nullptr;
    
    if (sum == maxVal)
    {
        vector<int> *solution = new vector<int>();
        for (int i = 0; i < currentNode->solution.size(); i++)
        {
            solution->push_back(currentNode->solution[i]);
        }
        return solution;
    }
    
    vector<int> *uValues = uniqueValues(fullValues, currentNode->solution);
    
    vector <node *> child(0);
    currentNode->children = child;
    
    for (int i = 0; i < uValues->size(); i++)
    {
        currentNode->children.push_back(new node());
        currentNode->children.at(i)->value = givenValues.at(i);
        
        for (int j = 0; j < currentNode->solution.size(); j++)
        {
            currentNode->children.at(i)->solution.push_back(currentNode->solution.at(j));
        }
        
        currentNode->children.at(i)->solution.push_back(currentNode->value);
        
        vector<int> temp = givenValues;
        
        temp.erase(find(temp.begin(), temp.end(), givenValues.at(i)));
        
        vector<int> *x = recursiveMethod(currentNode->children[i], temp, fullValues);
        if (x != nullptr) return x;
    }
    
    return nullptr;
}










