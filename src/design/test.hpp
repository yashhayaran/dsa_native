#include <vector> 


/*
arr: 1,:2,3,4,5
dims :5
axis: 0
 
answer
15
 
 
arr: 1,2,3,4,5,6,7,8,9
dims: 3,3
axis: 0
 
ans:
6,15,24
 
 
arr: 1,2,3,4,5,6,7,8,9
dims: 3,3
axis: 1
 
ans:
12,15,18
 
 
arr: 1,2,3,4,5,6,7,8,9
dims: 3,3
axis: 0,1
ans:
45
 
 
arr: 1,2,3,4,5,6,7,8,9
dims: 3,3
axis: 1,0
ans:
45



    1, 2, 3,
    4, 5, 6,
    7, 8, 9,



*/

template <typename T=int>
std::vector<T> reduceSum(const std::vector<T>& data, const std::vector<size_t>& dims, const std::vector<size_t>& axes) {
    size_t totalElements = 1;
    size_t M(0), N(0), MO(0), MS(0), NO(0), NS(0), MB(0), NB(0);

    for (auto& e: dims) {
        totalElements *= e;
    }
    
    std::vector<T> currResult(data.begin(), data.end());
    
    for (auto& currAxis: axes) {
        if (currAxis == 0) {
            MO = 1;
            NO = 1;
            MS = 1;
            NS = 1;
            MB = dims[0];
            NB = dims[0];
        }
        else if (currAxis == 1) {
            MO = 1;
            NO = 1;
            MS = 1;
            NS = 1;
            MB = dims[0];
            NB = dims[0];
        }

        for (; M < MB; ) {
            T _sum = 0;
            for (; N < NB; ) {
                _sum += data[N];
                N = N * NO + NS;
            }
            currResult.push_back(_sum);
            M = M * MO + MS;
        } 

    }

    for (size_t M = 0; M < dims[0]; M++) {
        for (size_t N = M; N < dims[0]; N++) {
            
        }
    }



    return result;
} 