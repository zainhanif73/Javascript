#include<iostream>
#include <stdlib.h>
#include<bits/stdc++.h>
#include<cstring>  
#include <algorithm>
using namespace std;

struct Node{
	char data[50];
	int val;
	struct Node* right;
	struct Node* left;
};

typedef struct Node* NODE;

void insertNode(NODE* head,char data[]){
	
    NODE temp = (NODE) malloc (sizeof(struct Node));
	temp->left = NULL;
	temp->right = NULL;
	temp->val = 1;
	strcpy(temp->data,data);

    NODE newNode = temp;
    NODE hold_the_head = *head;
    
    if(*head == NULL){
        *head = newNode;
        (*head)->right = NULL;
        (*head)->left = NULL;
        (*head)->val = 1;
        return;
    }

    while(true){
        if(strcmp(newNode->data,(*head)->data)>0 && ((*head)->right== NULL)){
            (*head)->right = newNode;
            *head = hold_the_head;
            return;
        }
        else if(strcmp(newNode->data,(*head)->data)>0 ){
            (*head) = (*head)->right;
        }
        else if( strcmp(newNode->data,(*head)->data)<0 && ( (*head)->left == NULL ) ){
            (*head)->left = newNode;
            *head = hold_the_head;
            return;
        }
        else if(strcmp(newNode->data,(*head)->data)<0 ){
            (*head) = (*head)->left;
        }
        else if(strcmp(newNode->data,(*head)->data)==0){
        	(*head)->val += 1;
			*head= hold_the_head; 
			return;
		}
    }
}

void inOrderTraversal(NODE node){

    if(node == NULL)
       return;
    inOrderTraversal(node->left);
    cout<<node->data<<"\t"<<node->val<<endl;
    inOrderTraversal(node->right);
}

void remove(NODE* root,char data[]){
	if(root == NULL){
        cout << "Tree is empty\n";
        return;
    }

    queue<NODE> q;
    q.push(*root);

    while(!q.empty())
    {
        NODE temp = q.front();
        q.pop();

        if(strcmp(temp->data , data)==0 && temp->val == 1)
        {
            NODE current = *root;
            NODE prev;

            while(current->right != NULL)
            {
                prev = current;
                current = current->right;
            }

            strcpy(temp->data , current->data);
            prev->right = NULL;
			free(current);
            cout << data<<" Deleted\n";

            return;
        }
        else if (strcmp(temp->data , data)==0 && temp->val > 1){
        	temp->val -= 1;
        	return;
		}

        if(temp->left != NULL)
            q.push(temp->left);
        if(temp->right != NULL)
            q.push(temp->right);
    }

    cout << data<<" not found for deletion\n";
}

void search(NODE* root,char data[]){
	if(root == NULL){
        cout << "Tree is empty\n";
        return;
    }

    queue<NODE> q;
    q.push(*root);

    while(!q.empty())
    {
        NODE temp = q.front();
        q.pop();

        if(strcmp(temp->data , data)==0)
        {
           cout<<temp->data <<" "<<temp->val<<endl;
        	return;
		}

        if(temp->left != NULL)
            q.push(temp->left);
        if(temp->right != NULL)
            q.push(temp->right);
    }
}

void min(NODE* head){
	
	NODE hold_the_head = *head;
	while ((*head)->left != NULL){
		*head = (*head)->left;
	}
	cout<<(*head)->data<<"\n";
	*head = hold_the_head;
	return;
}

void max(NODE* head){
	
	NODE hold_the_head = *head;
	while ((*head)->right != NULL){
		*head = (*head)->right;
	}
	cout<<(*head)->data<<"\n";
	*head = hold_the_head;
	return;
}

void child(NODE* root, char data[]){
	if(root == NULL){
        cout << "Tree is empty\n";
        return;
    }

    queue<NODE> q;
    q.push(*root);

    while(!q.empty())
    {
        NODE temp = q.front();
        q.pop();

        if(strcmp(temp->data , data)==0)
        {
           if (temp->left == NULL){
           		cout<<"NULL  ";
		   }
		   else{
		   		cout<<temp->left->data<<"  ";
		   }
		   if (temp->right == NULL){
		   	cout<<"NULL";
		   }
		   else{
		   	cout<<temp->right->data;
		   }
		   
        	return;
		}

        if(temp->left != NULL)
            q.push(temp->left);
        if(temp->right != NULL)
            q.push(temp->right);
    }		
}

void help()
{
	cout<<"1-> insert\n";
	cout<<"2-> delete\n";
	cout<<"3-> search\n";
	cout<<"4-> minimum\n";
	cout<<"5-> maximum\n";
	cout<<"6-> next\n";
	cout<<"7-> previous\n";
	cout<<"8-> list\n";
	cout<<"9-> parent\n";
	cout<<"10-> child\n";
	cout<<"11-> help\n";
	cout<<"12-> quit\n";
}

void prev(NODE* root, char data[]){
	if(root == NULL){
        cout << "Tree is empty\n";
        return;
    }
	NODE hold_the_head = *root;
	NODE tempp;
	while ((*root)->left != NULL){
		*root = (*root)->left;
	}
	tempp = *root;
//	cout<<(tempp)->data<<endl;
	*root = hold_the_head;
    queue<NODE> q;
    q.push(*root);
    string mins = "";
   

    while(!q.empty())
    {
        NODE temp = q.front();
        q.pop();

		if (strcmp(temp->data , (tempp)->data)>=0 && strcmp(temp->data , data)<0 ){
				mins= temp->data;
		}
        

        if(temp->left != NULL)
            q.push(temp->left);
        if(temp->right != NULL)
            q.push(temp->right);
    }	

	cout<<mins<<" ";		
}

void next(NODE* root, char data[]){
	if(root == NULL){
        cout << "Tree is empty\n";
        return;
    }
	NODE hold_the_head = *root;
	NODE tempp;
	while ((*root)->right != NULL){
		*root = (*root)->right;
	}
	tempp = *root;
	cout<<(tempp)->data<<endl;
	*root = hold_the_head;
    queue<NODE> q;
    q.push(*root);
    string mins = "";
   

    while(!q.empty())
    {
        NODE temp = q.front();
        q.pop();

		if (strcmp(temp->data , (tempp)->data)<0 && strcmp(temp->data , data)>0 ){
				mins= temp->data;
				break;
		}

        if(temp->left != NULL)
            q.push(temp->left);
        if(temp->right != NULL)
            q.push(temp->right);
    }	

	cout<<mins<<" ";	
}

void parent(NODE* root, char data[]){
	
}

int main(){

	string tag;
	char para[50];
    NODE head = NULL;
    
    //sample data
    insertNode(&head,"cat");
    insertNode(&head,"dog");
    insertNode(&head,"elephant");
    insertNode(&head,"frog");
	string quit="quit";
	cout<<"Enter your option by entering function name :\n";

	
	while(tag!=quit)
	{
		cin>>tag;
		transform(tag.begin(), tag.end(), tag.begin(), ::tolower);
		if(tag=="insert")
		{
			cin>>para;
			insertNode(&head, para);
		}
		else if(tag=="delete")
		{
			cin>>para;
			remove(&head, para);
			cout<<endl;
			cout<<endl;
		}
		else if(tag=="search")
		{
			cin>>para;
			search(&head, para);
			cout<<endl;
			cout<<endl;
		}
		else if(tag=="min")
		{
			min(&head);
			cout<<endl;
		}
		else if(tag=="max")
		{
			max(&head);
			cout<<endl;
		}
		else if(tag=="next")
		{
			cin>>para;
			next(&head, para);
			cout<<endl;
			cout<<endl;
		}
		else if(tag=="prev")
		{
			cin>>para;
			prev(&head, para);
			cout<<endl;
		}
		else if(tag=="list")
		{
			inOrderTraversal(head);
			cout<<endl;
			cout<<endl;
		}
		else if(tag=="parent")
		{
			cin>>para;
			insertNode(&head, para)
			cout<<endl;
			cout<<endl;
		}
		else if(tag=="child")
		{
			cin>>para;
			child(&head, para);
			cout<<endl;
			cout<<endl;
		}
		else if(tag=="help")
		{
			help();
			cout<<endl;
			cout<<endl;
		}
		else if(tag=="quit")
		{
			system("exit");
		}
	}

//    inOrderTraversal(head);
//    cout<<endl;

//	remove(&head , "chandu");
//	remove(&head , "palak");
//	remove(&head , "naman");
//	remove(&head , "jagdish");
//	remove(&head, "umang")	
//	min(&head);
//	max(&head);

//child(&head , "cat");
//	cout<<endl<<endl;
//	inOrderTraversal(head);
//
//    cout<<endl;
    return 0;

}