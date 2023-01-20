class Solution {
public:
    int findInMountainArray(int target, MountainArray &m) {
        int n = m.length() ;
        int i = 0 , j = n-1 ;
        int peak_index ;
        while(i<j){
            int mid = (i+j)/2 ;
            int l = m.get(mid-1) , mi = m.get(mid) , r = m.get(mid+1) ;
            if(l>mi && mi>r) j = mid;
            else if(l<mi && mi<r) i = mid+1 ;
            else{
                if(target == mi) return mid ;
                peak_index = mid ;
                break;
            }
        }
        i = 0 , j = peak_index -1 ;
        while(i<=j){
            
            int mid = (i+j)/ 2 ;
            
            int ele = m.get(mid) ;
            
            if(ele == target) return mid ;
            else if(ele > target) j = mid-1 ;
            else i = mid+1 ;
            
        }

        i = peak_index+1 , j = n-1 ;

        while(i<=j){
            cout<<i<<" , "<<j<<" , ";
            int mid = (i+j)/2 ;
            cout<<mid<<" -> ";
            int ele = m.get(mid) ;
            cout<<ele<<endl;
            if(ele == target) return mid ;
            else if(ele > target) i = mid+1 ;
            else j = mid-1 ;
        }

        return -1 ;

    }
};
