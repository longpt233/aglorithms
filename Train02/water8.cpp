// chu y voi bai nhieu version nhơ chú thích 
#include<iostream>
#include<queue>


using namespace std;

struct Node{
    int x,y;
    int stt;
    Node *next;
    Node(){}
    Node(int a, int b, int c){
        this->x=a;
        this->y=b;
        this->stt=c;
    }
};

struct List{
	Node* phead;
	Node* ptail;
};
void Initlist(List& l){
	l.phead=l.ptail=NULL;
}

bool Check(Node *a,Node *b){
    if (a->x==b->x&&a->y==b->y)  return true;
    return false; 
}
bool ExistNode(List *l,Node*node){
    Node* p;
    p = l->phead;
    while (p != NULL){
    	// Process Node
        if (Check(p,node))return true;
    	p = p->next;
    }
    return false;
}

bool  Isempty(List& l){
	if(l.phead==NULL)return true;
	return false;
}
void AddTail(List& l,Node* pnode){
	if(Isempty(l))l.ptail=l.phead=pnode;
	else {
		l.ptail -> next = pnode;
		l.ptail = pnode;
		}
}

int BFS(int a,int b,int c){
    
    queue<Node> q;
   
    
    // khoi tao Node root
    Node root= Node(0,0,0);
    // khoi tao danh sach chua cac cau hinh da di qua
    List s;
    Initlist(s);
    AddTail(s,&root);
    
    q.push(root);

    // lay ra 
    while(!q.empty()){
        Node current=q.front();
        q.pop();
        
        if(current.x==c|| current.y==c){
            return current.stt-1;
        }

        // sinh cau hinh 
        Node temp;
         temp.stt=current.stt+1;
        
        //if(current.y=0){
            temp.x=current.x;
            temp.y=b;
            if(ExistNode(&s,&temp)) {  
                    q.push(temp); 
                AddTail(s,&temp);
            }
        //}
        //if(current.x=0){

             temp.x=a;
            temp.y=current.y;
            if(ExistNode(&s,&temp)) {  
             q.push(temp); 
            AddTail(s,&temp);
        }
        //}
    //if(current.x=a){
        temp.x=0;
        temp.y=current.y;
        if(ExistNode(&s,&temp)) {  
             q.push(temp); 
            AddTail(s,&temp);
        }
    //}
    //if(current.y=b){
        temp.x=current.x;
        temp.y=0;
        if(ExistNode(&s,&temp)) {  
             q.push(temp); 

                AddTail(s,&temp);
        }
    //}
        for (int ap = 0; ap <= max(a, b); ap++) { 
            
            temp.x = current.x + ap; 
            temp.y = current.y - ap; 
            if (temp.x == a || temp.y == 0 ) 
                if(ExistNode(&s,&temp)){
                    q.push(temp); 
                    AddTail(s,&temp);
                }
            
            temp.x = current.x - ap; 
            temp.y = current.y + ap; 
            if (temp.x == 0  || temp.y == b) 
                if(ExistNode(&s,&temp)){
                    q.push(temp); 
                    AddTail(s,&temp);
                } 
        }
    }
    return -1;

}

int main(){

    int a,b,c;
    cin >>a>>b>>c;
   
cout<<BFS(a,b,c);

    return 0;
}