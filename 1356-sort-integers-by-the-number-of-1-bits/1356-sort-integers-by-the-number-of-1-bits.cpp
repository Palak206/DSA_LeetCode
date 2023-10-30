//direct stl lib = __builtin_popcount(num);//O(1)
//a<b asecnding 
//a>b decending

//supoose 1101 is given we have to count 1's in it 
//first we do n&1   1101
//                  0001 = 0001 right most 1 cout = 1
//shift 1 to right n>=1
//            n =   0110
//         &1 =     0001 = 0000

//right shift  n =  0011
//         & 1 =    0001= 0001 count +=1+1 = 2

// right shift  n = 0001
//                 = 0001 = count=2+1 = 3

//right shift n = 0000 

//the no of bits in binary tree log(n)
//T.C = O(NLOGN * O(LOGN))

//auto -return type 
//[] = capture clause
// class Solution {
// public:
    
//     //log2(num)
//     int countOneBits(int n){
//         int count = 0;
        
//         while(num != 0){
//             count += (nums & 1);
//             num >= 1;//right shift
//         }
//         return count;
//     }
    
//     vector<int> sortByBits(vector<int>& arr) {
        
//         //if we want to excess countOneBits(tht is outside)
//         // for that we have to use capture clause
        
//         auto lamda = [&](int &a  , int &b);{
//             int count_a = countOneBits(a);
//             int count_b = countOneBits(b);
            
//             if(count_a == count_b){
//                 return a<b;//ascending
//             }
//             //if not 
//             return count_a < count_b;
//         };
        
//         sort(arr.begin() , arr.end() , lamda);
//     }
// };


//T.C = O(1)*O(NLOGN)
class Solution {
public:
    
    vector<int> sortByBits(vector<int>& arr) {
        
        //if we want to excess countOneBits(tht is outside)
        // for that we have to use capture clause
        
        auto lamda = [&](int &a  , int &b){
            int count_a = __builtin_popcount(a);
            int count_b = __builtin_popcount(b);
            
            if(count_a == count_b){
                return a<b;//ascending
            }
            //if not 
            return count_a < count_b;
        };
        
        sort(arr.begin() , arr.end() , lamda);
        return arr;
    }
};