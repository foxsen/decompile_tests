#include <bits/stdc++.h>
struct node {
  int data;
  struct node* next;
};
struct node* SortedMerge(struct node* a, struct node* b);
void FrontBackSplit(struct node* source, struct node** frontRef,
                    struct node** backRef);
void MergeSort(struct node** headRef) {
  struct node* head = *headRef;
  struct node* a;
  struct node* b;
  if ((head == NULL) || (head->next == NULL)) {
    return;
  }
  FrontBackSplit(head, &a, &b);
  MergeSort(&a);
  MergeSort(&b);
  *headRef = SortedMerge(a, b);
}
struct node* SortedMerge(struct node* a, struct node* b) {
  struct node* result = NULL;
  if (a == NULL)
    return (b);
  else if (b == NULL)
    return (a);
  if (a->data <= b->data) {
    result = a;
    result->next = SortedMerge(a->next, b);
  } else {
    result = b;
    result->next = SortedMerge(a, b->next);
  }
  return (result);
}
void FrontBackSplit(struct node* source, struct node** frontRef,
                    struct node** backRef) {
  struct node* fast;
  struct node* slow;
  if (source == NULL || source->next == NULL) {
    *frontRef = source;
    *backRef = NULL;
  } else {
    slow = source;
    fast = source->next;
    while (fast != NULL) {
      fast = fast->next;
      if (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
      }
    }
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
  }
}
void printList(struct node* node) {
  while (node != NULL) {
    printf("%d ", node->data);
    node = node->next;
  }
}
void push(struct node** head_ref, int new_data) {
  struct node* new_node = (struct node*)malloc(sizeof(struct node));
  new_node->data = new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}
using namespace std;
int main() {
  int n, m;
  cin >> n;
  cin >> m;
  int* a = new int[m];
  int* count = new int[n];
  struct node** b = new struct node*[n];
  for (int i = 0; i < n; i++) {
    b[i] = NULL;
    count[i] = 0;
  }
  long long int d = 0;
  for (int i = 0; i < m; i++) {
    cin >> a[i];
    if (i > 0) d = d + abs(a[i] - a[i - 1]);
  }
  if (m == 1) {
    printf("%d\n", 0);
    return 0;
  }
  for (int i = 0; i < m; i++) {
    if (i > 0) {
      if (a[i - 1] != a[i]) {
        push(&b[a[i] - 1], a[i - 1]);
        count[a[i] - 1]++;
      }
    }
    if (i < m - 1) {
      if (a[i + 1] != a[i]) {
        push(&b[a[i] - 1], a[i + 1]);
        count[a[i] - 1]++;
      }
    }
  }
  long long int w = 0;
  for (int i = 0; i < n; i++) {
    if (count[i] != 0) {
      MergeSort(&b[i]);
      struct node* temp = b[i];
      for (int j = 0; j < (count[i] + 1) / 2 - 1; j++) temp = temp->next;
      int median = temp->data;
      long long int w1 = 0, w2 = 0;
      temp = b[i];
      while (temp != NULL) {
        w1 += abs(i + 1 - (temp->data));
        w2 += abs(median - (temp->data));
        temp = temp->next;
      }
      if (w1 - w2 > w) w = w1 - w2;
    }
  }
  cout << d - w << endl;
}
