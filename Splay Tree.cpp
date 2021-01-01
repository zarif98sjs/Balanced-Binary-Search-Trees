
/** Which of the favors of your Lord will you deny ? **/

#include<bits/stdc++.h>
#include <ostream>

using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define F first
#define S second

#define ALL(x)      (x).begin(), (x).end()
#define READ        freopen("alu.txt", "r", stdin)
#define WRITE       freopen("vorta.txt", "w", stdout)

#ifndef ONLINE_JUDGE
#define DBG(x)      cout << __LINE__ << " says: " << #x << " = " << (x) << endl
#else
#define DBG(x)
#define endl "\n"
#endif

template<class T1, class T2>
ostream &operator <<(ostream &os, pair<T1,T2>&p);
template <class T>
ostream &operator <<(ostream &os, vector<T>&v);
template <class T>
ostream &operator <<(ostream &os, set<T>&v);

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int nmax = 2e5+7;

/*
 * Splay Tree
 * =====
 * */

struct Node
{
    int data;
    Node* l;
    Node* r;

    Node(int data)
    {
        this->data = data;
        l = r = NULL;
    }
};
typedef Node* SpNode; /*Splay Node*/

struct SplayTree
{
    SpNode root;

    SplayTree()
    {
        root = NULL;
    }

    SpNode rotateLeft(Node *node) /*single rotate Left*/
    {
        if(!node || !node->r) return node;

        SpNode temp = node->r;
        node->r = temp->l;
        temp->l = node;

        return temp;
    }

    SpNode rotateRight(Node *node) /*single rotate Right*/
    {
        if(!node || !node->l) return node;

        SpNode temp = node->l;
        node->l = temp->r;
        temp->r = node;

        return temp;
    }

    void split(SpNode t,SpNode &l,SpNode &r,int data) /*l has all values <= data , r has all values > data*/
    {
        if(!t)
        {
            l = NULL;
            r = NULL;
            return;
        }

        if(t->data <= data)
        {
            split(t->r,t->r,r,data);
            l = t;
        }
        else
        {
            split(t->l,l,t->l,data);
            r = t;
        }
    }

    SpNode splay(SpNode t,int data)
    {
        if(!t || t->data == data) return t;

        if(data < t->data)
        {
            if(!t->l) return t;

            if(data < t->l->data) // left left
            {
                t->l->l = splay(t->l->l,data);
                t = rotateRight(t);
            }
            else if(data > t->l->data) // left right
            {
                t->l->r = splay(t->l->r,data);
                t->l = rotateLeft(t->l);
            }

            t = rotateRight(t);
        }
        else
        {
            if(!t->r) return t;

            if(data > t->r->data) // right right
            {
                t->r->r = splay(t->r->r,data);
                t = rotateLeft(t);
            }
            else if(data < t->r->data) // right left
            {
                t->r->l = splay(t->r->l,data);
                t->r = rotateRight(t->r);
            }

            t = rotateLeft(t);
        }
    }

    void preorder(SpNode t)
    {
        if(!t) return;

        cout<<(*t).data;

        if(t->l || t->r)
            cout<<"(";
        preorder(t->l);
        if(t->l || t->r)
            cout<<")";

        if(t->l || t->r)
            cout<<"(";
        preorder(t->r);
        if(t->l || t->r)
            cout<<")";
    }

    void preorder()
    {
        preorder(root);
        cout<<endl;
    }

    SpNode search(SpNode t,int data)
    {
        if(!t || t->data==data)
            return t;

        if(data < t->data) return search(t->l,data);
        else return search(t->r,data);
    }


    // operations

    void insert(int val)
    {
        SpNode l,r;
        split(root,l,r,val);

        root = new Node(val);

        root->l = l;
        root->r = r;
    }

    void splay(int val)
    {
        root = splay(root,val);
    }

    void remove(int val)
    {
        splay(val); /*splay the element that i want to remove i.e. bring to the root*/

        SpNode L = root->l;
        SpNode R = root->r;

        SpNode to_del = root;
        delete (to_del);

        L = splay(L,INT_MAX); /* splay on the maximum element in L */

        if(L) L->r = R , root = L;
        else root = R;
    }

    bool search(int val)
    {
        SpNode ret = search(root,val);

        return ret!=NULL;
    }

};


int32_t main()
{
    optimizeIO();

    SplayTree t;

    string option;

    while(cin>>option)
    {
        int num;
        cin>>num;

        if(option=="F")
        {
            bool has = t.search(num);
            if(has)
                cout<<"True"<<endl;
            else
                cout<<"False"<<endl;
        }
        else if(option=="I")
        {
            t.insert(num);
            t.preorder();
        }
        else if(option=="D")
        {
            t.remove(num);
            t.preorder();
        }
        else if(option=="S")
        {
            t.splay(num);
            t.preorder();
        }
    }

    return 0;
}

/**
 I 5
 I 7
 I 12
 I 2
 I 6
 I 9
 I 13
 I 15
 S 2
 S 9


 I 10
 I 20
// F 10
// F 20
 D 10
**/

template<class T1, class T2>
ostream &operator <<(ostream &os, pair<T1,T2>&p)
{
    os<<"{"<<p.first<<", "<<p.second<<"} ";
    return os;
}
template <class T>
ostream &operator <<(ostream &os, vector<T>&v)
{
    os<<"[ ";
    for(T i:v)
    {
        os<<i<<" " ;
    }
    os<<" ]";
    return os;
}

template <class T>
ostream &operator <<(ostream &os, set<T>&v)
{
    os<<"[ ";
    for(T i:v)
    {
        os<<i<<" ";
    }
    os<<" ]";
    return os;
}
