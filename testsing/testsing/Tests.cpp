//
//  Tests.cpp
//  testsing
//
//  Created by J Andrew McCormick on 6/29/16.
//  Copyright © 2016 J Andrew McCormick. All rights reserved.
//

#include "catch.hh"
#include "Backtracking.hpp"

using namespace std;

TEST_CASE("find zero solution")
{
    vector<int> givenValues(6);
    givenValues[0] = 59;
    givenValues[1] = 59;
    givenValues[2] = 59;
    givenValues[3] = 59;
    givenValues[4] = 44;
    givenValues[5] = 44;
    givenValues[6] = 44;
    givenValues[7] = 44;
    givenValues[8] = 41;
    givenValues[9] = 41;
    givenValues[10] = 41;
    givenValues[11] = 41;
    
    vector<int> *actualValue = findZeroSolution(givenValues);
    
    REQUIRE_EQ(59, actualValue->at(0));
    REQUIRE_EQ(44, actualValue->at(1));
    REQUIRE_EQ(41, actualValue->at(2));
}
TEST_CASE("Backtracking: numberOfUniqueItems returns 3 given an empty values to exclude")
{
    vector<int> givenValues(6);
    givenValues[0] = 59;
    givenValues[1] = 59;
    givenValues[2] = 44;
    givenValues[3] = 44;
    givenValues[4] = 41;
    givenValues[5] = 41;
    
    vector<int> valuesToExclude(0);
    
    vector<int> *x = uniqueValues(givenValues, valuesToExclude);
    
    REQUIRE_EQ(x->size(), 3);
}

TEST_CASE("Backtracking: numberOfUniqueItems returns 0 if the values to exclude vector is the same as the given values vector")
{
    vector<int> givenValues(6);
    givenValues[0] = 59;
    givenValues[1] = 59;
    givenValues[2] = 44;
    givenValues[3] = 44;
    givenValues[4] = 41;
    givenValues[5] = 41;
    
    vector<int> valuesToExclude(6);
    valuesToExclude[0] = 59;
    valuesToExclude[1] = 59;
    valuesToExclude[2] = 44;
    valuesToExclude[3] = 44;
    valuesToExclude[4] = 41;
    valuesToExclude[5] = 41;
    
    vector<int> *x = uniqueValues(givenValues, valuesToExclude);
    
    REQUIRE_EQ(x->size(), 0);
}