#include <iostream>
#include <chrono>
void solve(){

    int count = 0;
    int c;
    std::string s;

    std::cin>>c;
    std::cin>>s;

    int sizeS = sizeof(s)/sizeof(s[0]);
    int r = (sizeS+(c-(sizeS%c)))/c;

    bool sPrime[c][r];
    
    for(int i = 0; i<c; i++){
	for(int j = 0; j<r; j++){
            if((i+1)*(j+1)>sizeS){ std::cout<<"\nextra\n"; /*&sPrime[i][j] = nullprt*/;
	    } else if(s[i+j*c]=='1'){ sPrime[i][j] = true;
            } else sPrime[i][j] = false;
        }
    }

    for(int i = 0; i+3<c; i++){
        for(int j = 0; j+3<r; j+=c){
            if(sPrime[i][j] && !sPrime[i+1][j] && !sPrime[i+2][j] && !sPrime[i+3][j] &&
            !sPrime[i][j+1] && !sPrime[i+1][j+1] && sPrime[i+2][j+1] && sPrime[i+3][j+1] &&
            !sPrime[i][j+2] && !sPrime[i+1][j+2] && !sPrime[i+2][j+2] && !sPrime[i+3][j+2] &&
            sPrime[i][j+3] && !sPrime[i+1][j+3] && sPrime[i+2][j+3] && !sPrime[i+3][j+3]) count+=1;
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

