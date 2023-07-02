#include <bits/stdc++.h>
using namespace std;

// Time complexity--->(1),for all the operations
// Space complexity--->(2*n)
class MinStack
{
public:
    stack<pair<int, int>> st;

    MinStack() {}

    void push(int x)
    {
        if (st.empty() || x < st.top().second)
            st.push({x, x});
        else
            st.push({x, st.top().second});
    }

    void pop()
    {
        if (!st.empty())
            st.pop();
    }

    int top()
    {
        if (st.empty())
            return -1;
        return st.top().first;
    }

    int getMin()
    {

        if (st.empty())
            return -1;
        return st.top().second;
    }
};

// Time complexity--->(1),for all the operations
// Space complexity--->(n)
class MinStack
{
public:
    stack<long long> st;
    long long mini;

    MinStack()
    {
        while (!st.empty())
            st.pop();
        mini = INT_MAX;
    }

    void push(int x)
    {
        if (st.empty())
        {
            st.push(x);
            mini = x;
        }
        else
        {
            long long val = x;
            if (val < mini)
            {
                st.push(2 * val - mini);
                mini = val;
            }
            else
                st.push(val);
        }
    }

    void pop()
    {
        if (st.empty())
            return;
        long long tp = st.top();
        st.pop();
        if (tp < mini)
            mini = 2 * mini - tp;
    }

    int top()
    {
        if (st.empty())
            return -1;
        long long tp = st.top();
        if (tp < mini)
            return mini;
        return tp;
    }

    int getMin()
    {
        if (st.empty())
            return -1;
        return mini;
    }
};
