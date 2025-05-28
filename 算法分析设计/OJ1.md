# 1.1 全排列

### Description
R={ r1,r2,… ,rn }是要进⾏排列的n 个元素。其中元素r1,r2,… ,rn可能相同。

试设计⼀个算法，列出R的所有不同排列。 

编程任务：给定n 以及待排列的n 个元素。计算出这n 个元素的所有不同排列。

Input

 输⼊由多组测试数据组成。每组测试数据的第1 ⾏是元素个数n，1 <= n <= 500。接下来的1 ⾏是待排列的n 个元素。 
Output

 对应每组输⼊，将计算出的n 个元素的所有不同排列输出，每种排列单独⼀⾏。最后1 ⾏中的数是排列总数。

Sample Input
 4
aacc
Sample Output 

aacc
acac
acca
caac
caca
ccaa
6

>[!WARNING]
>
>测试数据未按字典序，具体未知，正常过2个样例即可，老师手动评分



```Cpp
#include <bits/stdc++.h>
using namespace std;
void perd(string &s1,unordered_set<string> &s2,int l,int r){
    if(l==r) s2.insert(s1); 
    else{
        for(int i=0;i<=r;i++){
            swap(s1[l],s1[i]);      
            perd(s1,s2,l+1,r);      
            swap(s1[l],s1[i]);    
        }  
    } 
} 
int main(){
    int n;  
    while(cin>>n){
        string s1;    
        cin>>s1;    
        unordered_set<string> result;    
        perd(s1,result,0,n-1);    
        vector<string>sortedresult(result.begin(),result.end());
        sort(sortedresult.begin(),sortedresult.end());    
        for(const auto & current : sortedresult){
            cout<<current<<endl;    
        }    
        cout<<sortedresult.size()<<endl;  
    }  
    return 0; 
}
```



# 1.2 桶查找

Description 

科研调查时得到了n个⾃然数，每个数均不超过1500000000。已知不
相同的数不超过10000个，现在需要在其中查找某个⾃然数，如找到则输出并统计这个⾃然数出现的次数，如没找到则输出NO。

Input 
输⼊由多组测试数据组成。
每组测试数据输⼊包含n+1⾏； 
第⼀⾏是两个整数n和x，n表⽰⾃然数的个数,x表⽰要查找的⾃然
数，两者之间⽤空格隔开； 
第2⾄n+1每⾏⼀个⾃然数。
Output 
对应每组输⼊，如果查找到x，则每⾏输出两个整数，分别是⾃然数
和该数出现的次数，其间⽤⼀个空格隔开；如果没有查找到x，则每⾏输出NO.

Sample Input 
8 100
2
4
2
4
5
100
2
100
Sample Output 
100 2

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,x;
  while(cin>>n>>x){
    unordered_map<int,int> numcount;
    for(int i=0;i<n;i++){
      int num;
      cin>>num;
      numcount[num]++;
    }
    if(numcount.find(x)!=numcount.end()){
      cout<<x<<" "<< numcount[x]<<endl;
    }
    else {
      cout<<"NO"<<endl;
    }
  }
  return 0;
}
```

