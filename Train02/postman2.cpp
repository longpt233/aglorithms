#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;
class customers{
    int x;
    unsigned int m;
    public:
    customers(){}
    customers(int x1,unsigned int m1){
        x=x1;
        m=m1;
    }
    int getArea(){
        return x;
    }
    int getM(){
        return m;
    } 
    void setM(unsigned int m2){
        this->m=m2;
    }
    void Print(){
        cout<<x<<" "<<m<<endl;
    }
};

void PrintList(vector<customers>a){
    for(int i=0;i<a.size();i++){
        customers x;
        x=a.at(i);
        x.Print();

    }
}

bool compare(customers a,customers b){
    if(a.getArea()<b.getArea())return true;
    return false;
}

int main(){
    //ios_base::sync_with_stdio(false);

    freopen("input.txt","r",stdin);

    int n,k;
    cin >>n >>k;
    vector<customers> c;
    for(int i=0;i<n;i++){
        int x1;
        unsigned int m1;
        cin >>x1>>m1;
        //customers a=new customers(x1,m1);  tai sao k dc ??
        customers a(x1,m1);
        c.push_back(a);
    }
    
    sort(c.begin(),c.end(),compare); // sap xep theo thu tu giam dan theo chieu 0,1,2,..
    
    // vector <customers> :: iterator iter_name; // khai bao mot con tro 
    // for (iter_name= x.begin();iter_name!= x.end();iter_name++){
    //     cout<<*iter_name;
    // }
    int i=n-1;

    /* PrintList(c);  
    cout<<endl<<n<<k;   */
    long result;
    while(i>=0){
        
        customers a= c.at(i);
        if(a.getArea()<0)break;
        int loop=a.getM()/k;
        int remain=a.getM()-loop*k;

        if(remain!=0){
            result+=a.getArea()*(loop+1)*2;
            a=c.at(i-1);
            a.setM(a.getM()-remain);
        }else{
            result+=a.getArea()*(loop)*2;
        }
        
        i--;
        
    }
    if(i){
         
        for (int j=0;j<=i;j++){
        
        customers a= c.at(j);
        //if(a.getArea()<0)break;
        int loop=a.getM()/k;
        int remain=a.getM()-loop*k;

        if(remain){
            result+=a.getArea()*(loop+1)*2;
            a=c.at(j+1);
            a.setM(a.getM()-remain);
        }else{
            result+=a.getArea()*(loop)*2;
        }
        
    
        
        }

    }

    PrintList(c);
    cout <<endl<< result;
    return 0;
}