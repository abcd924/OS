#include <stdio.h>
#include <stdlib.h>
typedef struct pagetable
{
  int fno, fcnt; // extra member from fifo logic
  char status;
} pagetable;
pagetable pt[10];

typedef struct node
{
  int data;
  struct node *next;
} node;

node *front, *rear;

int prefstr[] = {5, 4, 9, 3, 4, 9, 1, 2, 8, 7, 2, 6, 5, 3, 9};
int nprefstr;

int *freeframe;
int fno, n;

int dpage, vpage, pagefault;
int r = 5, c = 25, max; // extra variable from fifo logic

int getfreeframe()
{
  int i;
  for (i = 0; i < n; i++)
    if (freeframe[i] == 0)
      return i;
  return -1;
}

void appendnode(int no)
{
  node *temp;
  temp = (node *)malloc(sizeof(node));
  temp->data = no;
  temp->next = NULL;

  if (front == NULL)
  {
    front = temp;
    rear = temp;
  }
  else
  {
    rear->next = temp;
    rear = rear->next;
  }
}

// delete max counter node
int deletenode()
{
  int no;
  node *q, *temp, *p1, *p2;
  int max;

  max = pt[front->data].fcnt;
  temp = front;
  p1 = front;
  q = p1->next;
  while (q != NULL)
  {
    if (pt[q->data].fcnt > max)
    {
      max = pt[q->data].fcnt;
      p2 = p1;
      temp = q;
    }
    p1 = q;
    q = q->next;
  }
  if (temp == front)
    front = front->next;
  else
  {
    p2->next = temp->next;
    if (temp == rear)
      rear = p2;
  }
  temp->next = NULL;
  no = temp->data;
  free(temp);
  return no;
}

void setposition(int r, int c)
{
  printf("\033[%d;%df", r, c);
}

void displaynode()
{
  node *p;
  p = front;
  while (p != NULL)
  {
    printf("%d(%d)-->", p->data, pt[p->data].fcnt);
    p = p->next;
  }
  printf("NULL");
}

int main()
{
  int i, j;
  system("clear");
  printf("\nEnter how many frames:");
  scanf("%d", &n);

  freeframe = (int *)malloc(sizeof(int) * n);
  for (i = 0; i < n; i++)
    freeframe[i] = 0;

  nprefstr = sizeof(prefstr) / sizeof(int);
  for (i = 0; i < 10; i++)
  {
    pt[i].status = 'i';
    pt[i].fcnt = 0; // extra line from fifo logic
  }

  printf("\n\nReference page ");
  for (i = 0; i < nprefstr; i++)
  {
    dpage = prefstr[i];
    pt[dpage].fcnt++; // extra line from fifo logic
    setposition(r, c);
    printf("%d ", dpage);
    getchar();
    if (pt[dpage].status == 'i') // page is not in the frame
    {
      pagefault++;
      fno = getfreeframe();
      if (fno != -1) // free frame available
      {
        pt[dpage].fno = fno;
        pt[dpage].status = 'v';
        freeframe[fno] = dpage;
      }
      else // page replacement
      {
        vpage = deletenode();
        pt[dpage].fno = pt[vpage].fno;
        pt[vpage].status = 'i';
        pt[dpage].status = 'v';
        freeframe[pt[vpage].fno] = dpage;
        pt[vpage].fcnt = 0; // extra line from fifo logic
      }
      appendnode(dpage);
    }
    setposition(8, 1);
    printf("\nData of linked list ");
    displaynode();
    getchar();

    for (j = 0; j < n; j++)
    {
      setposition(12 + j, c);
      if (freeframe[j] != 0)
        printf("%d", freeframe[j]);
    }
    c = c + 3;
    getchar();

    setposition(16, 1);
    printf("\nNumber of page fault is %d", pagefault);
    getchar();
  }
  return 0;
}
