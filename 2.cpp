#include <bits/stdc++.h>
#define endl "\n" 
#define int long long
#define ct cout << (double)(clock() - sTime)/CLOCKS_PER_SEC << endl;
using namespace std;

int N=1e8;
vector<int> createArr(int n, int cur_max = 1){
    srand((unsigned) time(NULL));            
    vector<int> v(n,0);  

    int peak = max(rand()%(n-1), n/8);

    for(int i=0; i<peak; i++){
        cur_max += rand()%10000;
        v[i]=cur_max;  
    }
    
    for(int i=peak; i<n; i++){
        cur_max -= rand()%10000;
        v[i]=max(cur_max,0ll);        
    }
    return v;
}


int s=0, e=N-1;
int helper(vector<int> &v, int mid){
    if(mid>=N) return 2;
    if(mid<0) return 1;

    // case 1: peak
    if(v[mid-1]<v[mid] && v[mid]>v[mid+1]) return 0;

    // case 2: increasing
    else if(v[mid-1]<v[mid+1]) return 1;

    // case 3: decreasing
    else if(v[mid-1]>v[mid+1]) return 2;

    // case 4: flat
    else return 3;
}

void fn(vector<int> &v){
    while(s<e){
        int mid=(s+e)/2;
        switch (helper(v, mid)){
        case 0:
            s=mid;
            return;
        
        case 1:
            s=mid+1;
            break;

        case 2:
            e=mid-1;
            break;

        case 3:
            int i=2;
            bool flat=true;
            while(flat){
                int left = helper(v, mid-i);
                int right = helper(v, mid+i);
                if(left==0){
                    return; 
                }
                else if(right==0){
                    return; 
                }
                else if(left == 1 || right == 1){
                    flat=false;
                    s=mid+1;
                }
                else if(left == 2 || right == 2){
                    flat=false;
                    e=mid-1;
                }
                else{
                    i+=2;
                }
            }
        }
    }

}


void bruteForce(vector<int> &v){
    int i;
    for(i=0; i<v.size()-1; i++){
        if(v[i]>v[i+1])
            break;
    }
    cout<<v[i]<<" - "<<i;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    clock_t sTime;

    vector<int> v = createArr(N);
    // v={1,3,7,9,11,11,11,13,5,3,1};
    // for(auto i:v) cout<<i<<endl;
    sTime = clock();
    fn(v);
    cout<<v[s]<<" - "<<s<<endl;
    ct

    sTime = clock();
    bruteForce(v);
    cout<<endl;
    ct

    return 0;
    
}

// binary search variation:
// average case: Theta(log(n))
// worst case: O(n)

// brute Force:
// average case: O(n)
// worst case: O(n)
