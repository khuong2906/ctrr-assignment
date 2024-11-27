
#include <iostream> 
#include <fstream> 
using namespace std;
int main(){
                ifstream inputFile("input.txt");
        if(!inputFile){
                cout << "Error opening file" << endl;
                return -1;
        }
        inputFile.close();
        bellman();

        return 0;
}