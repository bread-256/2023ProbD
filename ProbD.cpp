#include <iostream>
#include <chrono>
void solve(){

    int count = 0;
    int c;
    std::string s;
    std::cin>>c;
    std::cin>>s;

    int sizeS = sizeof(s)/sizeof(s[0]);
    int lastRow = sizeS%c;
    int r = (sizeS+c-1)/c;

    int sPrime[r][c];

    for(int i = 0; i<c; i++){
        for(int j = 0; j<r; j++){
                if(((c*j)+i)>sizeS-1){ sPrime[j][i] = -1;
                } else if(s[i+j*c]=='1'){ sPrime[j][i] = true;
                } else if(s[i+j*c]=='0'){ sPrime[j][i] = false;
            }
        }
    }
    
    for(int j = 0; j+3<r; j++){
        for(int i = 0; i+3<c; i++){
            if(sPrime[j][i] && !sPrime[j][i+1] && !sPrime[j][i+2] && !sPrime[j][i+3] &&
            !sPrime[j+1][i] && !sPrime[j+1][i+1] && sPrime[j+1][i+2] && sPrime[j+1][i+3] &&
            !sPrime[j+2][i] && !sPrime[j+2][i+1] && !sPrime[j+2][i+2] && !sPrime[j+2][i+3] &&
            sPrime[j+3][i] && !sPrime[j+3][i+1] && sPrime[j+3][i+2] && !sPrime[j+3][i+3]) count+=1;
        }
    }

    std::cout<<'\n'<<"number of amogus: "<<count;

}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    auto start = std::chrono::high_resolution_clock::now();

    solve();

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout<<'\n';
    std::cerr << "Time taken: " << duration.count() << " ms" << std::endl;

    return 0;
}

