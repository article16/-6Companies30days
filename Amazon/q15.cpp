void linkdelete(struct Node  *head, int M, int N)
{
    Node *last, *temp, *p = head;
    int m, n;
    while (p) {
        m = M; n = N;
        while (p && m--) {
            last = p;
            p = p->next;
        }
        while (p && n--) {
            temp = p;
            p = p->next;
            delete temp;
        }
        last->next = p;
    }
}