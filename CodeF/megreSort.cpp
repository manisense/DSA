#include <vector>
#include <limits.h>
#include <iostream>

using namespace std;


void merge(vector<int>& arr, int l, int r, int mid){

        cout<<"Merging from index "<<l<<" to "<<r<<", Mid index: "<<mid<<endl;

        int l_size = mid-l+1;
        int r_size = r-mid;

        
        vector<int> left(l_size+1);
        vector<int> right(r_size+1);
        
        for(int i=0; i<l_size; i++){
            left[i] = arr[i+l];
        }

        cout<<"Left array: ";
        for(int i=0; i<l_size; i++){
            cout<<left[i]<<" ";
        }
        cout<<endl;
        
        for(int i=0; i<r_size; i++){
            right[i] = arr[i+mid+1];
        }

        cout<<"Right array: ";
        for(int i=0; i<r_size; i++){
            cout<<right[i]<<" ";
        }
        cout<<endl;
        
        left[l_size] = right[r_size] = INT_MAX;
        
        int left_i = 0;
        int right_i = 0;
        
        for(int i=l; i<=r; i++){
            if(left[left_i]<=right[right_i]){
                arr[i] = left[left_i];
                left_i++;
            }
            else{
                arr[i] = right[right_i];
                right_i++;
            }
        }
        
    }
    

 void mergeSort(vector<int>& arr, int l, int r) {
        
        if(l>=r)return;
        
        int mid = (l+r)/2;
        cout<<"Left index: "<<l<<", Right index: "<<r<<", Mid index: "<<mid<<endl;
        
        mergeSort(arr, l, mid);
        cout<<"After sorting left half: ";
        mergeSort(arr, mid+1, r);
        cout<<"After sorting right half: ";
        
        merge(arr, l, r, mid);
        cout<<"After merging: ";
    }

int main(){

    vector<int> arr = {4, 1, 3, 9, 7};
    int n = arr.size();

    cout<<"Size of array: "<<n<<endl;

    cout<<"Original array: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    mergeSort(arr, 0, n-1);

    cout<<"Sorted array: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}