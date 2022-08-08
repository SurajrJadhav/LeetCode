
/* // Definition for singly-linked list.
  struct ListNode {
      int val;
      struct ListNode *next;
  };
 */
    
struct ListNode * getnode()
{
    struct ListNode * new =(struct ListNode *)malloc(sizeof(struct ListNode));
    return new;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int sum=0,carry=0;
    struct ListNode * new =(struct ListNode *)malloc(sizeof(struct ListNode *));

    //new=getnode();
    //copy of head ptr
    struct ListNode * ssum=new;
    sum=0;
    int flag=0;
    while(l1 != NULL || l2!=NULL || carry!=0)
    {
        if(l1!=NULL)
        {
            sum+=l1->val;
            l1=l1->next;
        }
        if(l2!=NULL)
        {
            sum+=l2->val;
            l2=l2->next;
        }
        sum+=carry;
        carry=sum/10;
        sum=sum%10;
        
        //for first node update heead
        if(flag==0)
        {
            new=getnode();
            new->val=sum;
            new->next=NULL;
            flag=1;
            ssum=new;
            printf("first addition\n");
        }
        else
        {
            ssum->next=getnode();
            ssum=ssum->next;
            ssum->val=sum;
            ssum->next=NULL;
        }
        //ssum=ssum->next;
        
        sum=0;
    }
    //ssum=NULL;
    return new;
}
