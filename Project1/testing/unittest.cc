
#ifndef UNITTEST
#define UNITTEST

#include <gtest/gtest.h>

#include "*.h"

NAMESPACE_BEGIN(std);

TEST(toString, ballot) {
  Ballot ballot_;
  ballot_.setBallot_id(10);
  ballot_.setNum_candidates(5);
  int a[] = {1,2,3,4};
  ballot_.setList_of_ranks(a);

}
