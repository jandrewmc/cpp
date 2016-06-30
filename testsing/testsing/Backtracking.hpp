//
//  Backtracking.hpp
//  testsing
//
//  Created by J Andrew McCormick on 6/29/16.
//  Copyright © 2016 J Andrew McCormick. All rights reserved.
//

#ifndef Backtracking_hpp
#define Backtracking_hpp

#include <vector>

struct node
{
    node *parent;
    std::vector<node *> children;
    std::vector<int> solution;
    int numberOfChildren;
    int value;
};

std::vector<int> *uniqueValues(std::vector<int> givenValues, std::vector<int> valuesToExclude);
std::vector<int> *findZeroSolution(std::vector<int> givenValues);
std::vector<int> *recursiveMethod(node *root, std::vector<int> givenValues, std::vector<int> fullValues);

#endif /* Backtracking_hpp */
