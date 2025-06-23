#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

long long repairCars(vector<int>& ranks, int cars) {
        
        // sort array to get highest rank
        sort(ranks.begin(), ranks.end());
        
        int high = ranks.back(); // highest rank

        long long low = 1; // lowest time 
        long long up = high*cars*cars; // highest time

        cout<<"Highest time taken "<<up<<endl;

        int mecs = ranks.size(); // no of mechanics

        int mid = up/2;

        int minTime = INT_MAX;

        int car = 0;

        while(low<=up){
            cout<<"lowest time is "<<low<<endl;
            cout<<"mid time is "<<mid<<endl;
            cout<<"highest time is "<<up<<endl;

            car = 0;

            for(int m=0; m<mecs; m++){
                car += floor(sqrt(mid/ranks[m]));
                cout<<"Cars repaired by "<<m<<" is "<<car<<endl;
            }

            cout<<"total cars repaired "<<car<<" in total time "<<mid<<endl;

            if(car<cars){
                low = mid+1;
                cout<<"new lowest time is "<<low<<endl;
                mid = floor((up+low)/2);
                cout<<"new mid is "<<mid<<endl;
                //cout<<"new highest time is "<<up<<endl;
            }

            else if(car>cars){
                up = mid-1;
                //cout<<"new lowest time is "<<low<<endl;
                cout<<"new highest time is "<<up<<endl;
                mid = floor((up+low)/2);
                cout<<"New mid is "<<mid<<endl;
            }

            else if(car==cars){
               minTime = mid;
               //return mid;
               break;
            }
        
        }

        while(car==cars){
            minTime--;
            car = 0;

            for(int m=0; m<mecs; m++){
                car += floor(sqrt(minTime/ranks[m]));
                cout<<"Cars repaired by "<<m<<" is "<<car<<endl;
            }
        }
        

        return minTime+1;


    }

int main() {

   vector<int> ranks = {3,3,1,2,1,1,3,2,1};

   int cars = 58;

    cout<<repairCars(ranks, cars)<<endl;


    return 0;
}