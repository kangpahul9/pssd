#include <bits/stdc++.h>
using namespace std;
class FairWorkload
{
public:
    bool partition(int mid,vector <int> folders, int workers){
        int tempSum=0;int currWorker=1;
        for (int i = 0; i < folders.size(); i++)
        {
            tempSum+=folders[i];
            if (tempSum>mid)
            {
                currWorker++;
                tempSum=folders[i];
            }
            
            if (currWorker > workers)
            {
                return false;
            }
        }
        return true;
    }
    int getMostWork(vector <int> folders, int workers){
        int sum = 0;int st=0; int mid = 0;int result=INT_MAX;
        for (int i : folders)
        {
            sum += i;
        }
        while (st<sum)
        {
            mid = st + (sum-st)/2;
            if (partition(mid,folders,workers))
            {
                if (mid<result)
                {
                    result = mid;
                    sum=mid;
                }    
            }
            else{
                st=mid;
            }
        }
        return result;
    }
};
