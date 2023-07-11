// Bạn cần phải đặt 8
//  quân hậu lên một bàn cờ vua, sao cho không có hai quân hậu nào tấn công lẫn nhau. Để tăng phần thử thách, mỗi ô vuông sẽ được đánh dấu là ô trống hoặc ô bị cấm, và bạn chỉ được xếp các quân hậu trên những ô trống. Tuy nhiên, những ô bị cấm không chặn đường chiếu của các quân hậu.

// Có bao nhiêu cách để đặt các quân hậu?

// Input
// Gồm 
//  dòng, mỗi dòng chứa 
// 8 kí tự. Mỗi ô vuông là trống nếu kí tự tại đó là ., hoặc bị cấm nếu là *.
// Output
// In ra một số nguyên: số lượng cách xếp hậu.
// Example
// Sample input

// Copy
// Copy
// ........
// ........
// ..*.....
// ........
// ........
// .....**.
// ...*....
// ........
// Sample output

// Copy
// Copy
// 65
#include <bits/stdc++.h>
using namespace std;
bool check(char ban[][8],int hang,int cot){
    int n=8;
    for(int i=0;i<n;i++){
        if(ban[hang][i]=='Q')return false;
    }for(int i=0;i<n;i++){
        if(ban[i][cot]=='Q')return false;
    }for(int i=hang,j=cot;i>=0&&j>=0;i--,j--){
        if(ban[i][j]=='Q')return false;
    }for(int i=hang,j=cot;i>=0&&j<n;i--,j++){
        if(ban[i][j]=='Q')return false;
    }
    return true;
}
int backtrack(char ban[][8],int hang){
    int n=8,count=0;
    if(hang==n){
        count++;
        return count;
    }
    for (int cot=0;cot<n;cot++) {
        if(ban[hang][cot]=='.'&&check(ban,hang,cot)){
            ban[hang][cot]='Q';
            count+=backtrack(ban,hang+1);
            ban[hang][cot]='.';
        }
    }
    return count;
}
int main() {
    char ban[8][8];
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cin>>ban[i][j];
        }
    }
    cout<<backtrack(ban,0);
    return 0;
}