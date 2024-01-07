/* stats_tests.cpp
 *
 * Unit tests for the simple statistics library
 *
 * EECS 280 Project 1
 *
 * Protip #1: Write tests for the functions BEFORE you implement them!  For
 * example, write tests for median() first, and then write median().  It sounds
 * like a pain, but it helps make sure that you are never under the illusion
 * that your code works when it's actually full of bugs.
 *
 * Protip #2: Instead of putting all your tests in main(),  put each test case
 * in a function!
 */


#include "stats.hpp"
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
using namespace std;

void test_summarize();
void test_sum();
void test_count();
void test_mean();
void test_median();
void test_mode();
void test_min();
void test_max();
void test_stdev();
void test_percentile();

// Add prototypes for you test functions here.

int main() 
{
  test_summarize();
  test_sum();
  test_count();
  test_mean();
  test_median();
  test_mode();
  test_min();
  test_max();
  test_stdev();
  test_percentile();
  // Call your test functions here

  return 0;
}

void test_summarize() 
{
  cout << "test_summarize" << endl;

  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(1);
  data.push_back(2);
  data.push_back(1);
  data.push_back(3);

  std::vector<std::pair<double, int> > vp;
  vp = summarize(data);
  cout << "PASS!" << endl;
}

void test_sum() 
{
  cout << "test_sum" << endl;

  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);

  assert(sum(data) == 6);

  cout << "PASS!" << endl;
}

void test_count()
{
  cout<< "test_count" << endl;
  
  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);

  assert(count(data) == 3);
  cout << "PASS!" << endl;
}

void test_mean()
{
  cout<< "test_mean" << endl;
  
  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);

  assert(mean(data) == 2);
  cout << "PASS!" << endl;
}

void test_median()
{
  cout<< "test_median" << endl;
  
  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);
  data.push_back(4);

  assert(median(data) == 2.5);
  cout << "PASS!" << endl;
}

void test_mode()
{
  cout<< "test_mode" << endl;
  
  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);
  data.push_back(4);
  data.push_back(4);
  data.push_back(2);
  data.push_back(4);

  cout<< mode(data);

  assert(mode(data) == 4);
  cout << "PASS!" << endl;
}

void test_min()
{
  cout<< "test_min" << endl;
  
  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);

  assert(min(data) == 1);
  cout << "PASS!" << endl;
}

void test_max()
{
  cout<< "test_max" << endl;
  
  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);

  assert(max(data) == 3);
  cout << "PASS!" << endl;
}

void test_stdev()
{
  cout<< "test_stdev" << endl;
  
  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);
  data.push_back(4);

  assert((round(stdev(data) * 1000.0) / 1000.0) == 1.291);
  cout << "PASS!" << endl;
}

void test_percentile()
{
  cout<< "test_percentile" << endl;
  
  vector<double> data;
  data.push_back(15);
  data.push_back(20);
  data.push_back(35);
  data.push_back(40);
  data.push_back(50);

  assert(percentile(data, 40) == 29);
  cout << "PASS!" << endl;
}

// Add the test function implementations here.
