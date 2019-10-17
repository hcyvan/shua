# include <bits/stdc++.h>
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
};

list_node * input_list(int n)
{
    int val;
    list_node * phead = new list_node();
    list_node * cur_pnode = phead;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &val);
        if (i == 1) {
            cur_pnode->val = val;
            cur_pnode->next = NULL;
        }
        else {
            list_node * new_pnode = new list_node();
            new_pnode->val = val;
            new_pnode->next = NULL;
            cur_pnode->next = new_pnode;
            cur_pnode = new_pnode;
        }
    }
    return phead;
}


list_node *reverse_list(list_node *head) {
    if(!head || !head->next) {
        return head;
    }
    list_node *p1=head, *p2=p1->next, *tmp;
    while(p2) {
        tmp = p2;
        p2 = p2->next;
        tmp->next=p1;
        p1=tmp;
    }
    head->next = NULL;
    return p1;
}

list_node * add_list(list_node * head1, list_node * head2)
{
    list_node *dummy = new list_node();
    dummy->val = 0;
    dummy->next = NULL;
    list_node *p1=reverse_list(head1);
    list_node *p2=reverse_list(head2);
    list_node *p3=dummy;
    int next_value, cur;
    while(p1 || p2) {
        int v1 = p1 ? p1->val : 0;
        int v2 = p2 ? p2->val : 0;
        cur = v1 + v2 + next_value;
        next_value = cur / 10;
        cur = cur % 10;
        p3->next = new list_node();
        p3->next->val = cur;
        p3->next->next = NULL;
        p3 = p3->next;
        if(p1) p1=p1->next;
        if(p2) p2=p2->next;
    }
    if(next_value) {
        p3->next = new list_node();
        p3->next->val = next_value;
        p3->next->next = NULL;
    }
    return reverse_list(dummy->next);
}

void print_list(list_node * head)
{
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    puts("");
}

int main ()
{
    int n, m;
    scanf("%d%d", &n, &m);
    list_node * head1 = input_list(n), * head2 = input_list(m);
    list_node * new_head = add_list(head1, head2);
    print_list(new_head);
    return 0;
}