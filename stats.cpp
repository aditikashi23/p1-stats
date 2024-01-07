// stats.cpp
#include "stats.hpp"
#include "p1_library.hpp"
#include <cassert>
#include <vector>
#include <cmath>

using namespace std;

vector<pair<double, int> > summarize(vector<double> v) 
{
    sort(v);
    std::vector<std::pair<double, int> > vp;
    int count = 1;

    for(size_t k = 1; k< v.size() + 1; k++)
    {
        if(v[k] == v[k - 1])
        {
            count++;
        }
        else
        {
            vp.push_back({v[k - 1],count});
            count = 1;
        }
    }
    return vp;
}

int count(vector<double> v) 
{
    int counter = v.size();
    return counter;
}

double sum(vector<double> v) 
{
    double sum = 0.0;

    for(size_t i = 0; i < v.size(); i++)
    {
        sum += v[i];
    }
    return sum;
}

double mean(vector<double> v)
{
    double mean = 0.0;
    mean = sum(v)/count(v);
    return mean;
}

double median(vector<double> v) 
{
    int vec_size = v.size();
    int bound1, bound2 = 0;
    sort(v);
    if(vec_size % 2 == 0)
    {
        bound1 = (vec_size/2) + 0.5;
        bound2 = (vec_size/2) - 0.5;
        return (v[bound1] + v[bound2]) / 2;

    }
    else
    {
        bound1 = vec_size/2;
        return v[bound1];
    }
}

double mode(vector<double> v) 
{
    std::vector<std::pair<double, int> > vp = summarize(v);
    std::vector<double> newv;
    std::vector<double> mode;
    for (int k = 0; k < vp.size(); k++) 
    {
        newv.push_back(vp[k].second);
    }

    sort(newv);
    double max = newv[newv.size() - 1]; 

    for (size_t i = 0; i < vp.size(); i++) 
    {
        if(max == vp[i].second)
        {
            mode.push_back(vp[i].first);
        }
    }

    sort(mode);
    return mode[0];

}

double min(vector<double> v) 
{
    sort(v);
    return v[0];
}

double max(vector<double> v) 
{
    int vec_size = v.size() - 1;
    sort(v);
    return v[vec_size];
}

double stdev(vector<double> v) 
{
    double sum = 0.0;
    double mean = 0.0; 
    double stdev = 0.0;

    for(size_t i = 0; i < v.size(); i++)
    {
        sum += v[i];
    }

    mean = sum/(v.size());

    for(size_t j = 0; j < v.size(); j++)
    {
        stdev += pow((v[j] - mean), 2); 
    }

    stdev = (1.0 / (v.size() - 1)) * stdev;
    stdev = sqrt(stdev);
    return stdev;
}

double percentile(vector<double> v, double p) 
{
    double n, percentile, fractpart, intpart = 0.0;

    n = (p/100.0) * (v.size() - 1) + 1.0;
    fractpart = modf(n , &intpart);
    percentile = v[intpart - 1] + fractpart * (v[intpart] - v[intpart - 1]);
    return percentile;
}
