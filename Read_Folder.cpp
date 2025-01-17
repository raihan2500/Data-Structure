#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;

void readFilesFromFolder(const string folderPath){
    ofstream output("/home/raihan/Desktop/Data Structure/output.txt");
    for(const auto& filename: filesystem::directory_iterator(folderPath)){
        if(filename.is_regular_file()){
            ifstream input_file(filename.path());
            if(input_file.is_open()){
                output << filename.path() << endl;           
                string line;
                while(getline(input_file, line)){
                    output << line << endl;
                }
                output << endl;
                input_file.close();
                // output.close();               
            }
        }
    }
}

int32_t main(){
    string path;
    cin >> path;
    readFilesFromFolder(path);
}
