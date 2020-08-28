#include <bits/stdc++.h>

using namespace std;

struct Node {
    bool endmark;
    Node* next[26+1];

    Node()
    {
        endmark=false;
        for(int i=0;i<26;i++){
            next[i]=nullptr;
        }
    }
} *root;

void insert(char *str,int len)
{
    Node* curr=root;
    for(int i=0;i<len;i++){
        int id=str[i]-'a';
        if(curr->next[id]==nullptr)
            curr->next[id]=new Node();
        curr=curr->next[id];
    }
    curr->endmark=true;
}

bool search(char *str,int len)
{
    Node* curr=root;
    for(int i=0;i<len;i++){
        int id=str[i]- 'a';
        if(curr->next[id]==nullptr) return false;
        curr=curr->next[id];
    }
    return curr->endmark;
}

void del(Node *curr)
{
    for(int i=0;i<26;i++){
        if(curr->next[i])
            del(curr->next[i]);
    }
    delete(curr);
}

int main()
{
    cout << "Enter number of words\n";
    root=new Node();
    int num_word;
    cin>>num_word;

    for(int i=1;i<=num_word;i++){
        char str[50];
        scanf("%s",str);
        insert(str,strlen(str));
    }
    cout << "Enter number of query\n";
    int q;
    cin>>q;
    for(int i=1;i<=q;i++){
        char str[50];
        scanf("%s",str);
        if(search(str,strlen(str)))
            cout << "Found in the dictionary\n";
        else
            cout << "Not found\n";
    }
    del(root);

    return 0;
}
