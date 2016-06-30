//
//  catch.h
//  IRRCalculation
//
//  Created by J Andrew McCormick on 6/14/16.
//  Copyright © 2016 J Andrew McCormick. All rights reserved.
//

#ifndef catch_h
#define catch_h

#include "catchSuper.hh"

#define REQUIRE_EQ_WITH_ACCURACY( actualValue , expectedValue , accuracy ) \
REQUIRE(percentDifference( actualValue , expectedValue ) < accuracy)

#define REQUIRE_EQ( actualValue , expectedValue ) \
REQUIRE(actualValue == expectedValue)

const double doublePrecision = 0.000000001;

#endif /* catch_h */
