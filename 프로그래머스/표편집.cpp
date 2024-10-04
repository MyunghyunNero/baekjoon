#include <string>
#include <vector>
#include <stack>
 
using namespace std;
 
struct NODE
{
    int Data;
    NODE *Prev;
    NODE *Next;
    NODE(int D)
    {
        Data = D;
        Prev = NULL;
        Next = NULL;
    }
};
 
struct LINKEDLIST
{
    NODE *Head;
    NODE *Tail;
 
    LINKEDLIST() : Head(NULL), Tail(NULL) {}
    void Insert(int _Data);
    NODE* Erase(NODE *Node);
    void Restore(NODE *Node);
};
 
void LINKEDLIST::Insert(int _Data)
{
    if (Head == NULL)
    {
        NODE *NewNode = new NODE(_Data);
        Head = NewNode;
        Tail = NewNode;
    }
    else
    {
        NODE *NewNode = new NODE(_Data);
        NewNode->Prev = Tail;
        Tail->Next = NewNode;
        Tail = Tail->Next;
    }
}

NODE* LINKEDLIST::Erase(NODE *Node)
{
    if (Node == Head)
    {
        Head = Node->Next;
        Node->Next->Prev = NULL;
        return Node->Next;
    }
    else if (Node == Tail)
    {
        Tail = Node->Prev;
        Node->Prev->Next = NULL;
        return Node->Prev;
    }
    else
    {
        Node->Prev->Next = Node->Next;
        Node->Next->Prev = Node->Prev;
        return Node->Next;
    }

}

void LINKEDLIST::Restore(NODE *Node)
{
    if (Node->Prev == NULL)
    {
        Head = Node;
        Node->Next->Prev = Node;
    }
    else if (Node->Next == NULL)
    {
        Tail = Node;
        Node->Prev->Next = Node;
    }
    else
    {
        Node->Prev->Next = Node;
        Node->Next->Prev = Node;
    }
}
stack<NODE*> stk;
LINKEDLIST *List;
 
string solution(int n, int k, vector<string> cmd)
{
    string answer = "";
    List = new LINKEDLIST();
    for (int i = 0; i < n; i++) List->Insert(i);
    NODE *Iter = List->Head;
    for (int i = 0; i < k; i++) Iter = Iter->Next;
 
    for (int i = 0; i < cmd.size(); i++)
    {
    
        if (cmd[i][0] == 'U')
        {
            string SX = cmd[i].substr(2);
            int x = stoi(SX);
            for (int i = 0; i < x; i++) Iter = Iter->Prev;
        }
        else if (cmd[i][0] == 'D')
        {
            string SX = cmd[i].substr(2);
            int x = stoi(SX);
            for (int i = 0; i < x; i++) Iter = Iter->Next;
        }
        else if (cmd[i][0] == 'C')
        {
            stk.push(Iter);
            Iter = List->Erase(Iter);
        }
        else
        {
            NODE *Z = stk.top();
            stk.pop();
            List->Restore(Z);
        }
    }

    for (int i = 0; i < n; i++) answer += 'O';
    while (!stk.empty())
    {
        NODE *Temp = stk.top();
        stk.pop();

        int Idx = Temp->Data;
        answer[Idx] = 'X';
    }
    return answer;
}